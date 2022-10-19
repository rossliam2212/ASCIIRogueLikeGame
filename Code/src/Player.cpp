//
// Created by Liam on 17/10/2022.
//

#include "Player.h"

Player::Player()
    : strength{defaultStrength},
      health{defaultHealth},
      xp{defaultXP},
      positionX{defaultStartPositionX},
      positionY{defaultStartPositionY},
      newPositionX{defaultStartPositionX},
      newPositionY{defaultStartPositionY} {
}

Player::Player(int startPositionX, int startPositionY)
    : strength{defaultStrength},
      health{defaultHealth},
      xp{defaultXP},
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

int Player::getStrength() const { return  strength; }
int Player::getXP() const { return xp; }
int Player::getHealth() const { return health; }
int Player::getGoldCoins() const { return goldCoins; }

