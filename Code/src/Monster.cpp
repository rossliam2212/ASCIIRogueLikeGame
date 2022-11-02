//
// Created by Liam on 19/10/2022.
//

#include "Monster.h"

Monster::Monster(const GameMap& map, int strength, int health, int deathXP, int followDistance, int startPositionX, int startPositionY)
    : map{map},
      strength{strength},
      health{health},
      deathXP{deathXP},
      followDistance{followDistance},
      positionX{startPositionX},
      positionY{startPositionY},
      newPositionX{startPositionX},
      newPositionY{startPositionY} {
}

int Monster::playerInRange() {
    return 1;
}

void Monster::takeDamage(int damageAmount) {
    health -= damageAmount;
}

int Monster::getStrength() const { return strength; }
int Monster::getHealth() const { return health; }
int Monster::getDeathXP() const { return deathXP; }

bool Monster::isDead() const {
    return health <= 0;
}
