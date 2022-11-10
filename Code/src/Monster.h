//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_MONSTER_H
#define CODE_MONSTER_H

#include <string>
#include "GameMap.h"

enum MoveState {
    Idle,
    Up,
    Down,
    Left,
    Right
};

class Monster {
protected:
    std::string name;
    GameMap map;

    int strength;
    int health;
    int deathXP;

    int followDistance;
    bool followingPLayer{false};
    MoveState move{Idle};

    Point position;
    Point newPosition;

public:
    Monster(const GameMap& map, int strength, int health, int deathXP, int followDistance, Point startPosition);
    virtual ~Monster() = default;

    bool operator==(const Monster& rhs) const;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void attack() = 0;

    void checkInFollowRange();
    bool inFollowRange();
    void takeDamage(int damageAmount);
    bool isDead() const;

    std::string getName() const;
    int getStrength() const;
    int getHealth() const;
    int getDeathXP() const;
    Point getPosition() const;
};


#endif //CODE_MONSTER_H
