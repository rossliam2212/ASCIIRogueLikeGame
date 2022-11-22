//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_MONSTER_H
#define CODE_MONSTER_H

#include <string>
#include "GameMap.h"

class Player;

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
    Player* player;

    int strength;
    int health;
    int deathXP;
    int followDistance;

    bool attacking{false};
    bool dead{false};

    Point position;
    Point newPosition;
    MoveState move{Idle};

public:
    Monster(Player* player, const GameMap& map, int strength, int health, int deathXP, int followDistance, Point startPosition);
    virtual ~Monster() = default;

    bool operator==(const Monster& rhs) const;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void attack() = 0;

    void takeDamage(int damageAmount);
    bool isDead();
    void setIsDead();

    std::string getName() const;
    int getStrength() const;
    int getHealth() const;
    int getDeathXP() const;
    Point getPosition() const;

    bool getIsAttacking() const;
    void setAttacking();

protected:
    void checkInFollowRange();

};


#endif //CODE_MONSTER_H
