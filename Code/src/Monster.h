//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_MONSTER_H
#define CODE_MONSTER_H

#include "GameMap.h"

class Monster {
    static constexpr int defaultStrength{50};
    static constexpr int defaultHealth{100};
    static constexpr int defaultXP{0};
    static constexpr int defaultFollowDistance{0};

protected:
    GameMap map;

    int strength;
    int health;
    int xp;

    int followDistance;

public:
    explicit Monster(const GameMap& map);
    Monster(const GameMap& map, int strength, int health, int xp, int followDistance);
    virtual ~Monster() = default;

    void takeDamage(int damageAmount);
    bool isDead() const;

    int getStrength() const;
    int getHealth() const;
    int getXP() const;
};


#endif //CODE_MONSTER_H
