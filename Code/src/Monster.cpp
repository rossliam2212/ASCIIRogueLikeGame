//
// Created by Liam on 19/10/2022.
//

#include "Monster.h"

Monster::Monster(const GameMap& map)
    : Monster(map, defaultStrength, defaultHealth, defaultXP, defaultFollowDistance) {
}

Monster::Monster(const GameMap& map, int strength, int health, int xp, int followDistance)
    : map{map},
      strength{strength},
      health{health},
      xp{xp},
      followDistance{defaultFollowDistance} {
}

void Monster::takeDamage(int damageAmount) {
    health -= damageAmount;
}

int Monster::getStrength() const { return strength; }
int Monster::getHealth() const { return health; }
int Monster::getXP() const { return xp; }

bool Monster::isDead() const {
    return health <= 0;
}
