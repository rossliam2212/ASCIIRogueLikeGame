//
// Created by Liam on 19/10/2022.
//

#include "GameManager.h"

GameManager::GameManager()
    : map{MAPSIZEX, MAPSIZEY},
      player{map},
      level{1} {
}

void GameManager::startGame() {
    map.loadMap();

    while(!stopGame)
        update();
}

void GameManager::update() {
    player.update();
    renderUI();
}

void GameManager::renderUI() {
    utility::gotoScreenPosition(0, MAPSIZEY + 1);

    std::cout << "Level: " << level << " "
              << "| Gold: " << player.getInventory().getNumGoldCoins() << " "
              << "| Str: " << player.getStrength() << " "
              << "| HP: " << player.getHealth() << " "
              << "| XP: " << player.getXP();
}

void GameManager::endGame() {
    stopGame = true;
}
