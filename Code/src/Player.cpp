//
// Created by Liam on 17/10/2022.
//

#include "Player.h"

Player::Player()
    : health{100}, xp{0}, positionX{5}, positionY{5}, newPositionX{5}, newPositionY{5} {
}

Player::Player(int startPositionX, int startPositionY)
    : health{100},
      xp{0},
      positionX(startPositionX),
      positionY(startPositionY),
      newPositionX{startPositionX},
      newPositionY{startPositionY} {
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
        newPositionY = positionY - 1;
    }

    // Moving Down - S
    if (GetKeyState(83) & 0x8000) {
        newPositionY = positionY + 1;
    }

    // Moving Right - D
    if (GetKeyState(68) & 0x8000) {
        newPositionX = positionX + 1;
    }

    // Moving Left - A
    if (GetKeyState(65) & 0x8000) {
        newPositionX = positionX - 1;
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


int Player::getXp() const { return xp; }
void Player::setXp(int xp) { this->xp = xp; }

int Player::getHealth() const { return health; }
void Player::setHealth(int health) { this->health = health; }

int Player::getPositionX() const { return positionX; }
void Player::setPositionX(int startPositionX) { this->positionX = startPositionX; }

int Player::getPositionY() const { return positionY; }
void Player::setPositionY(int startPositionY) { this->positionY = startPositionY; }

