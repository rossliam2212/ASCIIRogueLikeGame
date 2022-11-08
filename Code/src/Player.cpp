//
// Created by Liam on 17/10/2022.
//

#include "Player.h"


Player::Player(const GameMap& map, std::vector<Monster*>& monsters)
        : Player(map, defaultStartPositionX, defaultStartPositionY, monsters) {
}

Player::Player(const GameMap &map, int startPositionX, int startPositionY, std::vector<Monster*>& monsters)
    : strength{defaultStrength},
      health{defaultHealth},
      xp{defaultXP},
      positionX(startPositionX),
      positionY(startPositionY),
      newPositionX{startPositionX},
      newPositionY{startPositionY},
      map{map},
      inventory{},
      monsters{monsters} {
}

void Player::update() {
    handleInput();
    renderPlayer();
    checkCollisions();
}

void Player::handleInput() {
    newPositionX = positionX;
    newPositionY = positionY;

    // ==== Moving Up - W (87) ====
    if (GetKeyState(87) & 0x8000) {
        // Boundary Checking
        if (map.getXY(positionX, positionY-1) != GameMap::roofChar &&
            map.getXY(positionX, positionY-1) != GameMap::wallChar &&
            map.getXY(positionX, positionY-1) != GameMap::skeletonChar &&
            map.getXY(positionX, positionY-1) != GameMap::zombieChar) {
            newPositionY = positionY - 1;
        }

        // Checking for enemies
        if (map.getXY(positionX, positionY - 1) == GameMap::skeletonChar ||
            map.getXY(positionX, positionY - 1) == GameMap::zombieChar) {
            checkMonster(positionX, positionY - 1);
        } else
            attacking = false;
    }

    // ==== Moving Down - S (83) ====
    if (GetKeyState(83) & 0x8000) {
        // Boundary Checking
        if (map.getXY(positionX, positionY+1) != GameMap::roofChar &&
            map.getXY(positionX, positionY+1) != GameMap::wallChar &&
            map.getXY(positionX, positionY+1) != GameMap::skeletonChar &&
            map.getXY(positionX, positionY+1) != GameMap::zombieChar) {
            newPositionY = positionY + 1;
        }

        // Checking for enemies
        if (map.getXY(positionX, positionY+1) == GameMap::skeletonChar ||
            map.getXY(positionX, positionY+1) == GameMap::zombieChar) {
            checkMonster(positionX, positionY+1);
        } else
            attacking = false;
    }

    // ==== Moving Right - D (68) ====
    if (GetKeyState(68) & 0x8000) {
        // Boundary Checking
        if (map.getXY(positionX+1, positionY) != GameMap::wallChar &&
            map.getXY(positionX+1, positionY) != GameMap::roofChar &&
            map.getXY(positionX+1, positionY) != GameMap::skeletonChar &&
            map.getXY(positionX+1, positionY) != GameMap::zombieChar) {
            newPositionX = positionX + 1;
        }

        // Checking for enemies
        if (map.getXY(positionX+1, positionY) == GameMap::skeletonChar ||
            map.getXY(positionX+1, positionY) == GameMap::zombieChar) {
            checkMonster(positionX+1, positionY);
        } else
            attacking = false;
    }

    // ==== Moving Left - A (65) ====
    if (GetKeyState(65) & 0x8000) {
        // Boundary Checking
        if (map.getXY(positionX-1, positionY) != GameMap::wallChar &&
            map.getXY(positionX-1, positionY) != GameMap::roofChar &&
            map.getXY(positionX-1, positionY) != GameMap::skeletonChar &&
            map.getXY(positionX-1, positionY) != GameMap::zombieChar) {
            newPositionX = positionX - 1;
        }

        // Checking for enemies
        if (map.getXY(positionX-1, positionY) == GameMap::skeletonChar ||
            map.getXY(positionX-1, positionY) == GameMap::zombieChar) {
            checkMonster(positionX-1, positionY);
        } else
            attacking = false;
    }

    // ==== Using Health Potion - R (82) ====
    if (GetKeyState(82) & 0x8000) {
        if (inventory.getNumHealthPotions() > 0) {
            inventory.removeHealthPotion();

            if (health + Inventory::healthPotionIncrease >= 100)
                health = 100;
            else
                health += Inventory::healthPotionIncrease;
        }
    }

    // Cycling through weapons - Right Arrow
    if (GetKeyState(VK_RIGHT) & 0x8000) {
        if (!inventory.getWeapons().empty()) {
            inventory.nextWeapon();
        }
    }
}

void Player::attack(Monster* monster) {
//    std::cout << "Player attacking: " << monster->getName() << "\n";

    if (attacking) {
        if (!isDead()) {
            monster->takeDamage(inventory.getCurrentWeapon().attack());

            if (monster->isDead()) {
                attacking = false;
                increaseXP(monster->getDeathXP());
                map.setXY(monster->getPositionX(), monster->getPositionY(), GameMap::defaultChar);

                utility::gotoScreenPosition(0, 80);
                std::cout << monster->getName() << " KILLED!\n";
            }
        }
    }

//    while (attacking) {
//        if (!isDead()) {
//            // Players Turn
//            monster->takeDamage(inventory.getCurrentWeapon().attack());
//
//            if (monster->isDead()) {
//                increaseXP(monster->getDeathXP());
//                map.setXY(monster->getPositionX(), monster->getPositionY(), GameMap::defaultChar);
//
////                auto m = std::find(std::begin(monsters), std::end(monsters), monster);
////                delete *m;
////                monsters.erase(m);
//
//                attacking = false;
//            }
//
//            // Monsters Turn
//            takeDamage(monster->getStrength());
//        }
//        else {
//            std::cout << "GAME OVER!!!\n";
//            break;
//        }
//    }
}

void Player::checkMonster(int x, int y) {
    if (!attacking) {
        for (auto &m: monsters) {
            if (m->getPositionX() == x && m->getPositionY() == y) {
                attacking = true;
                attack(m);
                break;
            }
        }
    }
}

void Player::renderPlayer() {
    utility::gotoScreenPosition((short)positionX, (short)positionY);
    std::cout << " ";

    utility::gotoScreenPosition((short)newPositionX, (short)newPositionY);
    std::cout << GameMap::playerChar;

    positionX = newPositionX;
    positionY = newPositionY;

    Sleep(120);
}

void Player::checkCollisions() {
    // Checking for Gold Coin Collision
    if (map.getXY(positionX, positionY) == GameMap::goldCoinChar){
        inventory.pickUpGoldCoin();

        // Setting the character at the position of the coin back to the default map character '='
        map.setXY(positionX, positionY, GameMap::defaultChar);
    }

    // Checking for Health Potion Collision
    if (map.getXY(positionX, positionY) == GameMap::healthPotionChar) {
        inventory.pickUpHealthPotion();

        // Setting the character at the position of the health potion back to the default map character '='
        map.setXY(positionX, positionY, GameMap::defaultChar);
    }

    // Checking for Weapon Collision
    if (map.getXY(positionX, positionY) == GameMap::weaponChar){
        inventory.pickUpWeapon();

        // Setting the character at the position of the weapon back to the default map character '='
        map.setXY(positionX, positionY, GameMap::defaultChar);
    }
}

void Player::increaseXP(int amount) { xp += amount; }
void Player::takeDamage(int amount) { health -= amount; }
bool Player::isDead() const { return health <= 0; }

int Player::getStrength() const { return  strength; }
int Player::getHealth() const { return health; }
int Player::getXP() const { return xp; }
int Player::getPositionX() const { return positionX; }
int Player::getPositionY() const { return positionY; }
Inventory Player::getInventory() const { return inventory; }


