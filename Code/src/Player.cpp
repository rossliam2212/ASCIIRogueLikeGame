//
// Created by Liam on 17/10/2022.
//

#include "Player.h"

Player::Player(const GameMap& map,
               std::vector<Monster*>& monsters,
               std::vector<Item*>& items,
               const HistoryLogger& hl,
               int& gameLevel)
    : strength{defaultStrength},
      health{defaultHealth},
      maxHealth{defaultMaxHealth},
      xp{defaultXP},
      xpLevel{1},
      gameLevel{gameLevel},
      position{defaultStartPositionX, defaultStartPositionY},
      newPosition{defaultStartPositionX, defaultStartPositionY},
      map{map},
      historyLogger{hl},
      inventory{hl},
      monsters{monsters},
      items{items} {
}

Player::Player(const GameMap& map,
               Point& startPosition,
               std::vector<Monster*>& monsters,
               std::vector<Item*>& items,
               const HistoryLogger& hl,
               int& gameLevel)
    : strength{defaultStrength},
      health{defaultHealth},
      maxHealth{defaultMaxHealth},
      xp{defaultXP},
      xpLevel{1},
      gameLevel{gameLevel},
      position{startPosition},
      newPosition{startPosition},
      map{map},
      historyLogger{hl},
      inventory{hl},
      monsters{monsters},
      items{items} {
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
    newPosition = position;

    // If player is attacking, then they cannot do anything until the attack is over.
    if (!attacking) {

        // ==== Moving Up - W (87) ====
        if(GetKeyState(87) & 0x8000) {
            // Boundary Checking
            if(map.getXY(position.getX(), position.getY() - 1) != GameMap::roofChar &&
               map.getXY(position.getX(), position.getY() - 1) != GameMap::wallChar &&
               map.getXY(position.getX(), position.getY() - 1) != GameMap::skeletonChar &&
               map.getXY(position.getX(), position.getY() - 1) != GameMap::zombieChar &&
               map.getXY(position.getX(), position.getY() - 1) != GameMap::goblinChar &&
               map.getXY(position.getX(), position.getY() - 1) != GameMap::ogreChar) {
                newPosition.setXY(position.getX(), position.getY() - 1);
            }

            // Checking for enemies
            if(map.getXY(position.getX(), position.getY() - 1) == GameMap::skeletonChar ||
               map.getXY(position.getX(), position.getY() - 1) == GameMap::zombieChar ||
               map.getXY(position.getX(), position.getY() - 1) == GameMap::goblinChar ||
               map.getXY(position.getX(), position.getY() - 1) == GameMap::ogreChar) {
                checkMonster(position.getX(), position.getY() - 1);
            }
        }

        // ==== Moving Down - S (83) ====
        if(GetKeyState(83) & 0x8000) {
            // Boundary Checking
            if(map.getXY(position.getX(), position.getY() + 1) != GameMap::roofChar &&
               map.getXY(position.getX(), position.getY() + 1) != GameMap::wallChar &&
               map.getXY(position.getX(), position.getY() + 1) != GameMap::skeletonChar &&
               map.getXY(position.getX(), position.getY() + 1) != GameMap::zombieChar &&
               map.getXY(position.getX(), position.getY() + 1) != GameMap::goblinChar &&
               map.getXY(position.getX(), position.getY() + 1) != GameMap::ogreChar) {
                newPosition.setXY(position.getX(), position.getY() + 1);
            }

            // Checking for enemies
            if(map.getXY(position.getX(), position.getY() + 1) == GameMap::skeletonChar ||
               map.getXY(position.getX(), position.getY() + 1) == GameMap::zombieChar ||
               map.getXY(position.getX(), position.getY() + 1) == GameMap::goblinChar ||
               map.getXY(position.getX(), position.getY() + 1) == GameMap::ogreChar) {
                checkMonster(position.getX(), position.getY() + 1);
            }
        }

        // ==== Moving Right - D (68) ====
        if(GetKeyState(68) & 0x8000) {
            // Boundary Checking
            if(map.getXY(position.getX() + 1, position.getY()) != GameMap::wallChar &&
               map.getXY(position.getX() + 1, position.getY()) != GameMap::roofChar &&
               map.getXY(position.getX() + 1, position.getY()) != GameMap::skeletonChar &&
               map.getXY(position.getX() + 1, position.getY()) != GameMap::zombieChar &&
               map.getXY(position.getX() + 1, position.getY()) != GameMap::goblinChar &&
               map.getXY(position.getX() + 1, position.getY()) != GameMap::ogreChar) {
                newPosition.setXY(position.getX() + 1, position.getY());
            }

            // Checking for enemies
            if(map.getXY(position.getX() + 1, position.getY()) == GameMap::skeletonChar ||
               map.getXY(position.getX() + 1, position.getY()) == GameMap::zombieChar ||
               map.getXY(position.getX() + 1, position.getY()) == GameMap::goblinChar ||
               map.getXY(position.getX() + 1, position.getY()) == GameMap::ogreChar) {
                checkMonster(position.getX() + 1, position.getY());
            }
        }

        // ==== Moving Left - A (65) ====
        if(GetKeyState(65) & 0x8000) {
            // Boundary Checking
            if(map.getXY(position.getX() - 1, position.getY()) != GameMap::wallChar &&
               map.getXY(position.getX() - 1, position.getY()) != GameMap::roofChar &&
               map.getXY(position.getX() - 1, position.getY()) != GameMap::skeletonChar &&
               map.getXY(position.getX() - 1, position.getY()) != GameMap::zombieChar &&
               map.getXY(position.getX() - 1, position.getY()) != GameMap::goblinChar &&
               map.getXY(position.getX() - 1, position.getY()) != GameMap::ogreChar) {
                newPosition.setXY(position.getX() - 1, position.getY());
            }

            // Checking for enemies
            if(map.getXY(position.getX() - 1, position.getY()) == GameMap::skeletonChar ||
               map.getXY(position.getX() - 1, position.getY()) == GameMap::zombieChar ||
               map.getXY(position.getX() - 1, position.getY()) == GameMap::goblinChar ||
               map.getXY(position.getX() - 1, position.getY()) == GameMap::ogreChar) {
                checkMonster(position.getX() - 1, position.getY());
            }
        }

        // ==== Using Health Potion - R (82) ====
        if(GetKeyState(82) & 0x8000) {
            if(!removeItemPressed) {
                removeItemPressed = true;
                if(inventory.getNumHealthPotions() > 0 && health < maxHealth) {
                    inventory.removeHealthPotion();

                    health = maxHealth;
                }
            }

            Sleep(500); // Half second delay
            removeItemPressed = false;
        }

        // ==== Cycling through weapons - Right Arrow ====
        if(GetKeyState(VK_RIGHT) & 0x8000) {
            if(!inventory.getWeapons().empty()) {
                inventory.nextWeapon();
            }

            Sleep(500); // Half second delay
        }

        // ==== Dropping Current Weapon - Q (81) ====
        if(GetKeyState(81) & 0x8000) {
            if(!inventory.getWeapons().empty()) {
                removeCurrentWeaponPressed = true;
                inventory.removeCurrentWeapon();
            }

            Sleep(500); // Half second delay
        }

        // ==== Opening Buy Menu - B (66) ====
        if(GetKeyState(66) & 0x8000 && buyMenu) {
            openBuyMenu();
        }

        // ==== FOR TESTING - Removing Players Health - X (88) ====
        if(GetKeyState(88) & 0x8000) {
            health -= 10;
        }
    }
}

void Player::openBuyMenu() {
    auto bm = new BuyMenu{gameLevel, xpLevel};
    Weapon* w;
    int weaponPrice;
//    int goldCoins{inventory.getNumGoldCoins()};
    int goldCoins{50};

    bm->displayWeapons();

    while (buyMenu) {
        // Selecting first weapon - 1 (49)
        if (GetKeyState(49) & 0x8000) {
            w = bm->pickWeapon(1);
            weaponPrice = w->getPrice();
            break;
        }
            // Selecting second weapon - 2 (50)
        else if (GetKeyState(50) & 0x8000) {
            w = bm->pickWeapon(2);
            weaponPrice = w->getPrice();
            break;
        }
            // Selecting third weapon - 3 (51)
        else if (GetKeyState(51) & 0x8000) {
            w = bm->pickWeapon(3);
            weaponPrice = w->getPrice();
            break;
        }
    }
    Sleep(500); // Half second delay

    buyMenu = false;

    if (goldCoins >= weaponPrice) {
        inventory.addItem(w);
        historyLogger.logWeaponBought(w);
    }

    bm->clearBuyMenu();
//            delete bm;
}


/**
 * This function handles the combat between the player and monsters.
 * This function begins the combat loop and allows both the player and the monster a chance
 * to attack. The players gets the first turn and then the monster gets theirs. The loop continues
 * until either the player or monster is killed.
 * @param monster The monster that the player is attacking.
 */
void Player::attack(Monster* monster) {
    while (attacking) {
        if (!isDead()) {

            // Players Turn
            int damageAmount;
            Weapon w{}; // Temp Weapon variable
            w = inventory.getCurrentWeapon();

            // If the player does not have a weapon, use their strength to attack the enemy
            if (!inventory.getWeapons().empty()) {
                damageAmount = w.attack();
            } else {
                damageAmount = strength;
            }

            monster->takeDamage(damageAmount);
            historyLogger.logDamageDealtToMonster(monster, damageAmount);


            if (monster->isDead()) {
                attacking = false;

                // Testing
                utility::gotoScreenPosition(monster->getPosition());
                std::cout << monster->getName() << " KILLED!\n";

                increaseXP(monster->getDeathXP());
                historyLogger.logMonsterKilled(monster, &w);

                auto p = monster->getPosition();
                map.setXY(p, GameMap::defaultChar);
            }
            else {
                // Monsters Turn
                Sleep(1000); // One-second delay
                takeDamage(monster->getStrength());
                historyLogger.logDamageDealtToPlayer(monster, health, monster->getStrength());
            }
        } else {
            attacking = false;
            historyLogger.logPlayerKilled(monster);
        }
    }
}

/**
 * Called when the player is within one space from a monster. This function finds the monster at the given
 * xy position and then the player begins attacking that particular monster.
 * @param x The monsters x position.
 * @param y The monsters y position.
 */
void Player::checkMonster(int x, int y) {
    for (auto* m: monsters) {
        if (m->getPosition().getX() == x && m->getPosition().getY() == y) {
            attacking = true;
            historyLogger.logAttackStarted(m);
            m->setAttacking();
            attack(m);
            break;
        }
    }
}

/**
 * Called when the player collects a game item. This function finds the item at the given
 * xy position and then adds the item to the players inventory.
 * @param x The items x position.
 * @param y The items y position.
 */
void Player::checkItem(int x, int y) {
     for (auto* item : items) {
        if (item->getPosition().getX() == x && item->getPosition().getY() == y) {
            inventory.addItem(item);
            historyLogger.logItemPickUp(item);
            break;
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

    position = newPosition;

    Sleep(120);
}

/**
 * Checks for collisions with all the different game items, such as gold coins, health potions, etc.
 * Also checks for when the player collides with the character to move onto the next level.
 */
void Player::checkCollisions() {
    if (map.getXY(position) == GameMap::goldCoinChar ||
        map.getXY(position) == GameMap::healthPotionChar ||
        map.getXY(position) == GameMap::weaponChar) {
        checkItem(position.getX(), position.getY());
        // Setting the character at the position of the item back to the default map character '='
        map.setXY(position, GameMap::defaultChar);
    }

    // Buy Menu
    if (map.getXY(position) == GameMap::buyMenuChar) {
        buyMenu = true;
        map.setXY(position, GameMap::defaultChar);
    }

    // Moving onto the next level
    if (map.getXY(position) == GameMap::nextLevelChar) {
        levelChange = true;
    }
}

/**
 * Levels up the player by increasing their max Health and strength.
 */
void Player::levelUp() {
    xpLevel++;
    maxHealth += 10;
    strength += 10;

    historyLogger.logPlayerXPLevelUp(xpLevel, maxHealth, strength);
}

/**
 * Increases the players XP.
 * @param amount The amount to increase the XP by.
 */
void Player::increaseXP(int amount) {
    xp += amount;

    if (xp > 30) {
        levelUp();
        xp = 0;
    }
}

/**
 * Sets the players position.
 * @param newPos The players new position.
 */
void Player::setPosition(const Point& newPos) {
    position = newPos;
}

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
 * Players XP level getter.
 * @return The players xp level.
 */
int Player::getXPLevel() const { return xpLevel; }

/**
 * Players attacking flag getter.
 * @return The players attacking flag.
 */
bool Player::getAttacking() const { return attacking; }

/**
 * Players buy menu flag getter.
 * @return The players buy menu flag.
 */
bool Player::getBuyMenu() const { return buyMenu; }

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


bool Player::getLevelChange() const { return levelChange; }
void Player::resetLevelChange() { levelChange = false; }

/**
 * Players next weapon pressed getter.
 * @return Whether the player has pressed next weapon (Right Arrow).
 */
bool Player::getNextWeaponPressed() const { return nextWeaponPressed; }

/**
 * Resets next weapon pressed to false.
 * Called from the GameManager to render the current weapon UI correctly.
 */
void Player::resetNextWeaponPressed() { nextWeaponPressed = false; }


/**
 * Players remove current weapon pressed getter.
 * @return Whether the player has pressed to drop their current weapon (Q).
 */
bool Player::getRemoveCurrentWeaponPressed() const { return removeCurrentWeaponPressed; }

/**
 * Resets resets remove current weapon pressed to false.
 * Called from the GameManager to render the current weapon UI correctly.
 */
void Player::resetRemoveCurrentWeaponPressed() { removeCurrentWeaponPressed = false; }
