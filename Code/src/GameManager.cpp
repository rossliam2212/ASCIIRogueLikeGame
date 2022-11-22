//
// Created by Liam on 19/10/2022.
//

#include "GameManager.h"

GameManager::GameManager()
    : map{mapSizeX, mapSizeY},
      monsters{},
      mapItems{},
      historyLogger{},
      player{map, monsters, mapItems, historyLogger, level},
      level{1} {
}

GameManager::~GameManager() {
    if (!monsters.empty()) {
        for (auto* p: monsters)
            delete p;
    }

    if (!mapItems.empty()) {
        for (auto* i : mapItems)
            delete i;
    }
}

/**
 * Starts the game.
 * The game map is loaded and then the main game loop starts.
 */
void GameManager::startGame() {
    map.loadMap(level, levels);
    setUpGameItemsAndMonsters();

    // Main Game Loop
    while(!gameOver() && !levelsCompleted) {
        if (player.getLevelChange()) {
            nextLevel();
            Sleep(5000);
        } else {
            update();
        }
    }

    // Called when game is over
    if (levelsCompleted)
        renderGameOverWinUI();
    else
        renderGameOverUI();

    historyLogger.logGameOver();
}

void GameManager::nextLevel() {
    level++;
    if (level >= 3) {
        levelsCompleted = true;
        return;
    }

    cleanResourcesOnLevelChange();
    map.loadMap(level, levels);
    setUpGameItemsAndMonsters();
    historyLogger.logLevelChange(level);


    player.setPosition(Point{2, 1});
    player.resetLevelChange();
}

/**
 * Calls the players and monsters update functions and also updates the UI.
 */
void GameManager::update() {
    player.update();
    renderUI();

    if (!monsters.empty()) {
        for (auto* monster: monsters) {
            if (!monster->isDead())
                monster->update();
        }
    }
}

/**
 * Sets up all of the monsters and game items gathered when the map is loaded.
 * Monsters & Items (gold coins & health potions) are created dynamically and placed into
 * their respective vectors.
 */
void GameManager::setUpGameItemsAndMonsters() {
    auto monstersAndItems = map.getMonstersAndItems();

    for (auto& monstersAndItem : monstersAndItems) {
        if (monstersAndItem.first == GameMap::skeletonChar){
            monsters.emplace_back(new Skeleton(&player, map, monstersAndItem.second));
        }
        else if (monstersAndItem.first == GameMap::zombieChar) {
            monsters.emplace_back(new Zombie(&player, map, monstersAndItem.second));
        }
        else if (monstersAndItem.first == GameMap::goblinChar) {
            monsters.emplace_back(new Goblin(&player, map, monstersAndItem.second));
        }
        else if (monstersAndItem.first == GameMap::ogreChar) {
            monsters.emplace_back(new Ogre(&player, map, monstersAndItem.second));
        }
        else if (monstersAndItem.first == GameMap::goldCoinChar) {
            mapItems.emplace_back(new GoldCoin{monstersAndItem.second});
        }
        else if (monstersAndItem.first == GameMap::healthPotionChar) {
            mapItems.emplace_back(new HealthPotion{monstersAndItem.second});
        }
        else if (monstersAndItem.first == GameMap::weaponChar) {
            mapItems.emplace_back(new Weapon{monstersAndItem.second});
        }
    }
}

/**
 * Renders (prints out) the Games UI elements.
 */
void GameManager::renderUI() {
    // General UI
    utility::gotoScreenPosition(0, mapSizeY + 1);
    std::cout << "Game Level: " << level << "\n";

    std::cout << "Strength: " << player.getStrength() << " "
              << "| HP: " << player.getHealth() << " "
              << "| XP-Level: " << player.getXPLevel() << "/" << Player::maxXPLevel << " "
              << "| XP: " << player.getXP() << " \n";

    // Players Attacking State
    utility::gotoScreenPosition(0, mapSizeY + 4);
    std::cout << "Buy Menu Available: " << (player.getBuyMenu() ? "Yes\n" : "No \n");


    // Inventory UI
    utility::gotoScreenPosition(0, mapSizeY + 6);
    std::cout << "Inventory: \n Gold Coins: " << player.getInventory().getNumGoldCoins()
              << "\n Health Potions: " << player.getInventory().getNumHealthPotions()
              << "\n";

    std::cout << " Current Weapon: ";

    if (!player.getInventory().getWeapons().empty()) {
        if (player.getNextWeaponPressed()) {
            std::cout << "                                                                              \n\n";
            player.resetNextWeaponPressed();
        }
        else
            std::cout << player.getInventory().getCurrentWeapon() << "\n\n";
    } else {
        std::cout << "No Weapons                                                 \n\n";
    }

    std::cout << " Weapons: \n";

    if (!player.getInventory().getWeapons().empty()) {
        if (player.getRemoveCurrentWeaponPressed()) {
            for (int i = 0; i < player.getInventory().getWeapons().size()+3; i++) {
                std::cout << "                                                     \n";
            }
            player.resetRemoveCurrentWeaponPressed();
        }
        else {
            for (auto* w : player.getInventory().getWeapons()) {
                std::cout << "  " << *w << "\n";
            }
        }
    }

//    std::cout << "}";
}

/**
 * Renders the game over win ui - When the player beats the game.
 */
void GameManager::renderGameOverWinUI() {
    system("cls");

    utility::gotoScreenPosition(0, 0);
    std::cout << R"(
   ____                            _         _       _   _                 _
  / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___| |
 | |   / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __| |
 | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \_|
  \____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___(_)
                   |___/                                                    )";

    std::cout << R"(
 __   _____  _   _  __        _____ _   _ _ _
 \ \ / / _ \| | | | \ \      / /_ _| \ | | | |
  \ V / | | | | | |  \ \ /\ / / | ||  \| | | |
   | || |_| | |_| |   \ V  V /  | || |\  |_|_|
   |_| \___/ \___/     \_/\_/  |___|_| \_(_|_)
                                             )";

    std::cout << "\n\n";
    std::cout << "You have successfully beaten the game!\n";
    std::cout << "Check the GameSessionHistory.txt file for your game details.\n\n\n\n";
}

/**
 *  Renders the Games game over ui elements.
 */
void GameManager::renderGameOverUI() {
    system("cls");

    utility::gotoScreenPosition(0, 0);
    std::cout << R"(
   ____                         ___                 _
  / ___| __ _ _ __ ___   ___   / _ \__   _____ _ __| |
 | |  _ / _` | '_ ` _ \ / _ \ | | | \ \ / / _ \ '__| |
 | |_| | (_| | | | | | |  __/ | |_| |\ V /  __/ |  |_|
  \____|\__,_|_| |_| |_|\___|  \___/  \_/ \___|_|  (_))";

    std::cout << "\n\n";

    std::cout << "Hard Luck! \nYou were killed by a monster!\n";
    std::cout << "Better luck next time.\n\n";
    std::cout << "Check the GameSessionHistory.txt file for your game details.\n\n\n\n";
}

/**
 * Checks whether the player is dead.
 * The game will end when the player is dead.
 * @return True if the player is dead, false otherwise.
 */
bool GameManager::gameOver() {
    return player.isDead();
}

/**
 * Cleans up some resources from the previous level when the player moves onto the next level.
 */
void GameManager::cleanResourcesOnLevelChange() {
    for (auto* m : monsters) {
        if (!m->isDead())
            m->setIsDead();
    }

//    monsters.clear();

//    for (auto* i : mapItems)
//        delete i;

//    mapItems.clear();

    map.clearResourcesForLevelChange();
}
