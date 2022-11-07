//
// Created by Liam on 19/10/2022.
//

#include "GameManager.h"

GameManager::GameManager()
    : map{MAPSIZEX, MAPSIZEY},
      monsters{},
      player{map, monsters},
      level{1} {
}

GameManager::~GameManager() {
    if (!monsters.empty()) {
        for (auto p: monsters)
            delete p;
    }
}

void GameManager::startGame() {
    map.loadMap();
    setUpMonsters();

    while(!stopGame)
        update();
}

void GameManager::update() {
    player.update();
    renderUI();

    if (!monsters.empty()) {
        for (const auto monster: monsters)
            monster->update();
    }
}

void GameManager::setUpMonsters() {
    auto monsterChars = map.getMonsters();
    auto positions = map.getMonsterPositions();

    for (int i = 0; i < monsterChars.size(); i++) {
        if (monsterChars[i] == GameMap::skeletonChar)
            monsters.emplace_back(new Skeleton(map, positions[i].first, positions[i].second));

        else if (monsterChars[i] == GameMap::zombieChar){
            monsters.emplace_back(new Zombie(map, positions[i].first, positions[i].second));
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

    if (!player.getInventory().getWeapons().empty()) {
        for (const auto& w : player.getInventory().getWeapons()) {
            std::cout << " " << w << "\n";
        }
    }
    std::cout << "}";
}

void GameManager::renderGameOverUI() {

}

void GameManager::endGame() {
    stopGame = true;
}
