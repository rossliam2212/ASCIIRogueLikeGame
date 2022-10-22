//
// Created by Liam on 17/10/2022.
//

#include "Player.h"


Player::Player(const GameMap& map)
        : Player(map, defaultStartPositionX, defaultStartPositionY) {
}

Player::Player(const GameMap& map, int startPositionX, int startPositionY)
    : strength{defaultStrength},
      health{defaultHealth},
      xp{defaultXP},
      positionX(startPositionX),
      positionY(startPositionY),
      newPositionX{startPositionX},
      newPositionY{startPositionY},
      map{map} {
}

void Player::update() {
    handleInput();
    renderPlayer();
}

void Player::handleInput() {
    newPositionX = positionX;
    newPositionY = positionY;

    // Moving Up - W
    if (GetKeyState(87) & 0x8000) {
        if (map.getXY(positionX, positionY-1) != GameMap::roofChar &&
            map.getXY(positionX, positionY-1) != GameMap::wallChar)
            newPositionY = positionY - 1;
    }

    // Moving Down - S
    if (GetKeyState(83) & 0x8000) {
        if (map.getXY(positionX, positionY+1) != GameMap::roofChar &&
            map.getXY(positionX, positionY+1) != GameMap::wallChar)
            newPositionY = positionY + 1;
    }

    // Moving Right - D
    if (GetKeyState(68) & 0x8000) {
        if (map.getXY(positionX+1, positionY) != GameMap::wallChar &&
            map.getXY(positionX+1, positionY) != GameMap::roofChar)
            newPositionX = positionX + 1;
    }

    // Moving Left - A
    if (GetKeyState(65) & 0x8000) {
        if (map.getXY(positionX-1, positionY) != GameMap::wallChar &&
            map.getXY(positionX-1, positionY) != GameMap::roofChar)
            newPositionX = positionX - 1;
    }

    // Checking for Gold Coin Collision
    if (map.getXY(positionX, positionY) == GameMap::goldCoinChar){
        std::cout << "\n\nPicked up gold coin\n";
        inventory.pickUpGoldCoin();
    }

    // Checking for Health Potion Collision
    if (map.getXY(positionX, positionY) == GameMap::healthPotionChar) {
        std::cout << "\n\nPicked up health potion\n";
        health = maxHealth;
    }

    // Checking for Weapon Collision
    if (map.getXY(positionX, positionY) == GameMap::healthPotionChar){
        std::cout << "Picked up weapon:\n";
    }
}

void Player::renderPlayer() {
    utility::gotoScreenPosition(positionX, positionY);
    std::cout << " ";

    utility::gotoScreenPosition(newPositionX, newPositionY);
    std::cout << playerSymbol;

    positionX = newPositionX;
    positionY = newPositionY;

    Sleep(120);
}

void Player::increaseXP(int amount) { xp += amount; }

int Player::getStrength() const { return  strength; }
int Player::getXP() const { return xp; }
int Player::getHealth() const { return health; }
Inventory Player::getInventory() const { return inventory; }


