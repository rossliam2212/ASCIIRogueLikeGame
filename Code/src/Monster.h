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
    static constexpr int strengthLevelIncrease{5}; // The amount the strength increases every level

    std::string name;
    GameMap map;
    Player* player;

    int level;
    int strength;
    int health;
    int deathXP;
    int followDistance;
    int deathGold;

    bool attacking{false};
    bool dead{false};

    Point position;
    Point newPosition;
    MoveState move{Idle};

public:
    Monster(Player* player, const GameMap& map, int level, int health, int deathXP, int followDistance, int deathGold, Point startPosition);
    virtual ~Monster() = default;

    bool operator==(const Monster& rhs) const;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual int attack() = 0;

    void takeDamage(int damageAmount);
    bool isDead();
    void setIsDead();

    std::string getName() const;
    int getStrength() const;
    int getHealth() const;
    int getDeathXP() const;
    int getDeathGold() const;
    Point getPosition() const;

    bool getIsAttacking() const;
    void setAttacking();

protected:
    void checkInFollowRange();
    void setStrength(int defaultStrength);
};


#endif //CODE_MONSTER_H
