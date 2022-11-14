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
        for (auto p: monsters)
            delete p;
    }

    if (!mapItems.empty()) {
        for (auto i : mapItems)
            delete i;
    }
}

void GameManager::startGame() {
    map.loadMap();
    setUpGameItemsAndMonsters();

    while(!gameOver())
        update();

    renderGameOverUI();
    historyLogger.logGameOver();
}

void GameManager::update() {
    player.update();
    renderUI();

    if (!monsters.empty()) {
        for (const auto monster: monsters) {
            if (!monster->isDead())
                monster->update();
        }
    }
}

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

void GameManager::renderUI() {
    // General UI
    utility::gotoScreenPosition(0, MAPSIZEY + 1);
    std::cout << "Level: " << level << " "
              << "| Str: " << player.getStrength() << " "
              << "| HP: " << player.getHealth() << " "
              << "| XP: " << player.getXP();

    // Inventory UI
    utility::gotoScreenPosition(0, MAPSIZEY + 3);
    std::cout << "Inventory {\n Gold Coins: " << player.getInventory().getNumGoldCoins()
              << "\n Health Potions: " << player.getInventory().getNumHealthPotions()
              << "\n";

    std::cout << " Current Weapon: ";

    if (!player.getInventory().getWeapons().empty()) {

        // Clearing the current weapon text to display the next weapon when the player cycles through the weapons
        if (player.getNextWeaponPressed()) {
            std::cout << "                                                     \n\n";
            player.resetNextWeaponPressed();
        }
        else
            std::cout << player.getInventory().getCurrentWeapon() << "\n\n";

        // Displaying all the players weapons
        std::cout << " Weapons: \n";
        if (player.getRemoveCurrentWeaponPressed()) {
            for (int i = 0; i < player.getInventory().getWeapons().size()+3; i++) {
                std::cout << "                                                     \n";
            }
            player.resetRemoveCurrentWeaponPressed();
        }
        else {
            for (const auto& w : player.getInventory().getWeapons()) {
                std::cout << "  " << w << "\n";
            }
        }
    }
    else {
        std::cout << "                                                     \n\n";
    }

    std::cout << "}";
}

void GameManager::renderGameOverUI() {
    system("cls");

    std::cout << R"(
 _____   ___  ___  ___ _____   _____  _   _  _____ ______
|  __ \ / _ \ |  \/  ||  ___| |  _  || | | ||  ___|| ___ \
| |  \// /_\ \| .  . || |__   | | | || | | || |__  | |_/ /
| | __ |  _  || |\/| ||  __|  | | | || | | ||  __| |    /
| |_\ \| | | || |  | || |___  \ \_/ /\ \_/ /| |___ | |\ \
 \____/\_| |_/\_|  |_/\____/   \___/  \___/ \____/ \_| \_|)";

    std::cout << "\n";
}

bool GameManager::gameOver() {
    return player.isDead();
}

