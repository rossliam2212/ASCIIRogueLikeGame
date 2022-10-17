//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_PLAYER_H
#define CODE_PLAYER_H

#include "utility.h"


class Player {
private:
    const char playerSymbol{'@'};
    int health;
    int xp;

    int positionX;
    int positionY;
    int newPositionX;
    int newPositionY;

public:
    Player();
    Player(int startPositionX, int startPositionY);
    void update();

    // Getters & Setters
    int getXp() const;
    void setXp(int xp);

    int getHealth() const;
    void setHealth(int health);

    int getPositionX() const;
    void setPositionX(int startPositionX);

    int getPositionY() const;
    void setPositionY(int startPositionY);

private:
    void handleInput();
    void renderPlayer();
};


#endif //CODE_PLAYER_H
