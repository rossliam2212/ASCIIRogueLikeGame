//
// Created by Liam on 17/10/2022.
//

#include "Player.h"


Player::Player(const GameMap& map, std::vector<Monster*>& monsters, const HistoryLogger& hl)
    : strength{defaultStrength},
      health{defaultHealth},
      xp{defaultXP},
      position{defaultStartPositionX, defaultStartPositionY},
      newPosition{defaultStartPositionX, defaultStartPositionY},
      map{map},
      inventory{},
      monsters{monsters},
      historyLogger{hl} {
}

//Player::Player(const GameMap &map, int startPositionX, int startPositionY, std::vector<Monster*>& monsters)
//    : strength{defaultStrength},
//      health{defaultHealth},
//      xp{defaultXP},
//      positionX(startPositionX),
//      positionY(startPositionY),
//      newPositionX{startPositionX},
//      newPositionY{startPositionY},
//      map{map},
//      inventory{},
//      monsters{monsters} {
//}

Player::Player(const GameMap& map, Point& startPosition, std::vector<Monster*>& monsters, const HistoryLogger& hl)
    : strength{defaultStrength},
      health{defaultHealth},
      xp{defaultXP},
      position{startPosition},
      newPosition{startPosition},
      map{map},
      inventory{},
      monsters{monsters},
      historyLogger{hl} {
}

void Player::update() {
    handleInput();
    renderPlayer();
    checkCollisions();
}

/**
 * Handles all the Player input.
 */
void Player::handleInput() {
//    newPositionX = positionX;
//    newPositionY = positionY;

    newPosition = position;

    // ==== Moving Up - W (87) ====
    if (GetKeyState(87) & 0x8000) {
        // Boundary Checking
        if (map.getXY(position.getX(), position.getY()-1) != GameMap::roofChar &&
            map.getXY(position.getX(), position.getY()-1) != GameMap::wallChar &&
            map.getXY(position.getX(), position.getY()-1) != GameMap::skeletonChar &&
            map.getXY(position.getX(), position.getY()-1) != GameMap::zombieChar) {
//            newPositionY = positionY - 1;
            newPosition.setXY(position.getX(), position.getY()-1);
        }

        // Checking for enemies
        if (map.getXY(position.getX(), position.getY() - 1) == GameMap::skeletonChar ||
            map.getXY(position.getX(), position.getY() - 1) == GameMap::zombieChar) {
            checkMonster(position.getX(), position.getY() - 1);
        } else
            attacking = false;
    }

    // ==== Moving Down - S (83) ====
    if (GetKeyState(83) & 0x8000) {
        // Boundary Checking
        if (map.getXY(position.getX(), position.getY()+1) != GameMap::roofChar &&
            map.getXY(position.getX(), position.getY()+1) != GameMap::wallChar &&
            map.getXY(position.getX(), position.getY()+1) != GameMap::skeletonChar &&
            map.getXY(position.getX(), position.getY()+1) != GameMap::zombieChar) {
//            newPositionY = positionY + 1;
            newPosition.setXY(position.getX(), position.getY()+1);
        }

        // Checking for enemies
        if (map.getXY(position.getX(), position.getY()+1) == GameMap::skeletonChar ||
            map.getXY(position.getX(), position.getY()+1) == GameMap::zombieChar) {
            checkMonster(position.getX(), position.getY()+1);
        } else
            attacking = false;
    }

    // ==== Moving Right - D (68) ====
    if (GetKeyState(68) & 0x8000) {
        // Boundary Checking
        if (map.getXY(position.getX()+1, position.getY()) != GameMap::wallChar &&
            map.getXY(position.getX()+1, position.getY()) != GameMap::roofChar &&
            map.getXY(position.getX()+1, position.getY()) != GameMap::skeletonChar &&
            map.getXY(position.getX()+1, position.getY()) != GameMap::zombieChar) {
//            newPositionX = positionX + 1;
            newPosition.setXY(position.getX()+1, position.getY());
        }

        // Checking for enemies
        if (map.getXY(position.getX()+1, position.getY()) == GameMap::skeletonChar ||
            map.getXY(position.getX()+1, position.getY()) == GameMap::zombieChar) {
            checkMonster(position.getX()+1, position.getY());
        } else
            attacking = false;
    }

    // ==== Moving Left - A (65) ====
    if (GetKeyState(65) & 0x8000) {
        // Boundary Checking
        if (map.getXY(position.getX()-1, position.getY()) != GameMap::wallChar &&
            map.getXY(position.getX()-1, position.getY()) != GameMap::roofChar &&
            map.getXY(position.getX()-1, position.getY()) != GameMap::skeletonChar &&
            map.getXY(position.getX()-1, position.getY()) != GameMap::zombieChar) {
//            newPositionX = positionX - 1;
            newPosition.setXY(position.getX()-1, position.getY());
        }

        // Checking for enemies
        if (map.getXY(position.getX()-1, position.getY()) == GameMap::skeletonChar ||
            map.getXY(position.getX()-1, position.getY()) == GameMap::zombieChar) {
            checkMonster(position.getX()-1, position.getY());
        } else
            attacking = false;
    }

    // ==== Using Health Potion - R (82) ====
    if (GetKeyState(82) & 0x8000) {
        if (inventory.getNumHealthPotions() > 0 && health < maxHealth) {
            inventory.removeHealthPotion();

            if (health + Inventory::healthPotionIncrease >= maxHealth)
                health = maxHealth;
            else
                health += Inventory::healthPotionIncrease;
        }
    }

    // ==== Cycling through weapons - Right Arrow ====
    if (GetKeyState(VK_RIGHT) & 0x8000) {
        if (!inventory.getWeapons().empty()) {
            nextWeaponPressed = true;
            inventory.nextWeapon();
        }
    }

    // ==== Dropping Current Weapon - Q (81) ====
    if (GetKeyState(81) & 0x8000) {
        if (!inventory.getWeapons().empty()) {
            removeCurrentWeaponPressed = true;
            inventory.removeCurrentWeapon();
        }
    }

    // ==== FOR TESTING - Removing Players Health - X (88) ====
    if (GetKeyState(88) & 0x8000) {
        health -= 10;
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
                map.setXY(monster->getPosition().getX(), monster->getPosition().getY(), GameMap::defaultChar);

                utility::gotoScreenPosition(position);
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

/**
 * Called when the player is within one space from a monster. This function finds the monster at the given
 * xy position and then the player begins attacking that particular monster.
 * @param x The monsters x position.
 * @param y The monsters y position.
 */
void Player::checkMonster(int x, int y) {
    if (!attacking) {
        for (auto& m: monsters) {
            if (m->getPosition().getX() == x && m->getPosition().getY() == y) {
                attacking = true;
                attack(m);
                break;
            }
        }
    }
}

/**
 * Renders the player in the correct xy position whenever the player is moved.
 */
void Player::renderPlayer() {
    utility::gotoScreenPosition(position);
    std::cout << " ";

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::playerChar;

//    positionX = newPositionX;
//    positionY = newPositionY;

    position = newPosition;

    Sleep(120);
}

/**
 * Checks for collisions with all the different game objects, such as gold coins, health potions, etc.
 */
void Player::checkCollisions() {
    // Checking for Gold Coin Collision
    if (map.getXY(position.getX(), position.getY()) == GameMap::goldCoinChar){
        inventory.pickUpGoldCoin();

        // Setting the character at the position of the coin back to the default map character '='
        map.setXY(position.getX(), position.getY(), GameMap::defaultChar);
    }

    // Checking for Health Potion Collision
    if (map.getXY(position.getX(), position.getY()) == GameMap::healthPotionChar) {
        inventory.pickUpHealthPotion();

        // Setting the character at the position of the health potion back to the default map character '='
        map.setXY(position.getX(), position.getY(), GameMap::defaultChar);
    }

    // Checking for Weapon Collision
    if (map.getXY(position.getX(), position.getY()) == GameMap::weaponChar) {
        if (!inventory.weaponSlotsFull()) {
            inventory.pickUpWeapon();
            // Setting the character at the position of the weapon back to the default map character '='
            map.setXY(position.getX(), position.getY(), GameMap::defaultChar);
        }
    }
}

/**
 * Increases the players XP.
 * @param amount The amount to increase the XP by.
 */
void Player::increaseXP(int amount) { xp += amount; }

/**
 * Deals damage to the player.
 * @param amount The amount of damage to deal to the player.
 */
void Player::takeDamage(int amount) { health -= amount; }

/**
 * Checks if the player is dead - If their health is <= 0.
 * @return True if the player is dead, False otherwise.
 */
bool Player::isDead() const { return health <= 0; }

/**
 * Players strength getter.
 * @return The players strength.
 */
int Player::getStrength() const { return  strength; }

/**
 * Players health getter.
 * @return The players health.
 */
int Player::getHealth() const { return health; }

/**
 * Players XP getter.
 * @return The players XP.
 */
int Player::getXP() const { return xp; }

/**
 * Player position getter.
 * @return The players position.
 */
Point Player::getPosition() const { return position; }

/**
 * Players inventory getter.
 * @return The players inventory.
 */
Inventory Player::getInventory() const { return inventory; }

/**
 * Players next weapon pressed getter.
 * @return Whether the player has pressed next weapon (Right Arrow)
 */
bool Player::getNextWeaponPressed() const { return nextWeaponPressed; }

/**
 * Resets next weapon pressed to false.
 * Called from the GameManager to render the current weapon UI correctly.
 */
void Player::resetNextWeaponPressed() { nextWeaponPressed = false; }

bool Player::getRemoveCurrentWeaponPressed() const {
    return removeCurrentWeaponPressed;
}

void Player::resetRemoveCurrentWeaponPressed() {
    removeCurrentWeaponPressed = false;
}




