//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_MONSTER_H
#define CODE_MONSTER_H

#include "GameMap.h"

class Monster {
protected:
    GameMap map;

    int strength;
    int health;
    int deathXP;

    int followDistance;

    int positionX;
    int positionY;
    int newPositionX;
    int newPositionY;

public:
    Monster(const GameMap& map, int strength, int health, int deathXP, int followDistance, int startPositionX, int startPositionY);
    virtual ~Monster() = default;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void attack() = 0;

    int playerInRange();
    void takeDamage(int damageAmount);
    bool isDead() const;

    int getStrength() const;
    int getHealth() const;
    int getDeathXP() const;
};


#endif //CODE_MONSTER_H
