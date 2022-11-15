//
// Created by Liam on 19/10/2022.
//

#include "GameManager.h"

GameManager::GameManager()
    : map{MAPSIZEX, MAPSIZEY},
      monsters{},
      mapItems{},
      historyLogger{},
      player{map, monsters, mapItems, historyLogger},
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
    map.loadMap();
    setUpGameItemsAndMonsters();

    // Main Game Loop
    while(!gameOver())
        update();

    // Called when game is over
    renderGameOverUI();
    historyLogger.logGameOver();
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
        if (monstersAndItem.first == GameMap::skeletonChar)
            monsters.emplace_back(new Skeleton(map, monstersAndItem.second));

        else if (monstersAndItem.first == GameMap::zombieChar) {
            monsters.emplace_back(new Zombie(map, monstersAndItem.second));
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
    utility::gotoScreenPosition(0, MAPSIZEY + 1);
    std::cout << "Level: " << level << " "
              << "| Str: " << player.getStrength() << " "
              << "| HP: " << player.getHealth() << " "
              << "| XP: " << player.getXP();

    // Players Attacking State
    utility::gotoScreenPosition(0, MAPSIZEY + 3);
    std::cout << "Attacking: " << (player.getAttacking() ? "Yes\n" : "No \n");


    // Inventory UI
    utility::gotoScreenPosition(0, MAPSIZEY + 5);
    std::cout << "Inventory {\n Gold Coins: " << player.getInventory().getNumGoldCoins()
              << "\n Health Potions: " << player.getInventory().getNumHealthPotions()
              << "\n";

    std::cout << " Current Weapon: ";

    if (!player.getInventory().getWeapons().empty()) {
        if (player.getNextWeaponPressed()) {
            std::cout << "                                                     \n\n";
            player.resetNextWeaponPressed();
        }
        else
            std::cout << player.getInventory().getCurrentWeapon() << "\n\n";
    } else {
        std::cout << "No Weapons\n\n";
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

    std::cout << "}";
}

/**
 *  Renders the Games game over UI elements.
 */
void GameManager::renderGameOverUI() {
    system("cls");

    utility::gotoScreenPosition(0, 0);
    std::cout << R"(
 _____   ___  ___  ___ _____   _____  _   _  _____ ______
|  __ \ / _ \ |  \/  ||  ___| |  _  || | | ||  ___|| ___ \
| |  \// /_\ \| .  . || |__   | | | || | | || |__  | |_/ /
| | __ |  _  || |\/| ||  __|  | | | || | | ||  __| |    /
| |_\ \| | | || |  | || |___  \ \_/ /\ \_/ /| |___ | |\ \
 \____/\_| |_/\_|  |_/\____/   \___/  \___/ \____/ \_| \_|)";

    std::cout << "\n\n";

    std::cout << " Hard Luck! \nYou were killed by a monster!\n";
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

