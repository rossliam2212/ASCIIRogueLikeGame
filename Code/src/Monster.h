//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_MONSTER_H
#define CODE_MONSTER_H

#include <string>
#include "GameMap.h"

class Monster {
protected:
    std::string name;
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

    bool operator==(const Monster& rhs) const;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void attack() = 0;

    bool inFollowRange();
    void takeDamage(int damageAmount);
    bool isDead() const;

    std::string getName() const;
    int getStrength() const;
    int getHealth() const;
    int getDeathXP() const;
    int getPositionX() const;
    int getPositionY() const;
};


#endif //CODE_MONSTER_H
