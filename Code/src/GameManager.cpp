//
// Created by Liam on 19/10/2022.
//

#include "GameManager.h"

GameManager::GameManager()
    : map{MAPSIZEX, MAPSIZEY},
      player{map},
      monsters{},
      level{1} {
}

GameManager::~GameManager() {
    for (auto p : monsters)
        delete p;
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
    // call update for all monsters
}

void GameManager::setUpMonsters() {
    auto monsterLetters = map.getMonsters();

    for (auto letter : monsterLetters) {
        if (letter == GameMap::skeletonChar)
            monsters.push_back(new Skeleton(map));
        else if (letter == GameMap::zombieChar) {

        }
    }
}

void GameManager::renderUI() {
    utility::gotoScreenPosition(0, MAPSIZEY + 1);

    std::cout << "Level: " << level << " "
              << "| Gold: " << player.getInventory().getNumGoldCoins() << " "
              << "| Str: " << player.getStrength() << " "
              << "| HP: " << player.getHealth() << " "
              << "| XP: " << player.getXP();
}

void GameManager::renderGameOverUI() {

}

void GameManager::endGame() {
    stopGame = true;
}
