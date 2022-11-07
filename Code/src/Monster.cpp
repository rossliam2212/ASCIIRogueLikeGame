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

bool Monster::operator==(const Monster& rhs) const {
    return positionX == rhs.positionX && positionY == rhs.positionY;
}

bool Monster::inFollowRange() {
    return true;
}

void Monster::takeDamage(int damageAmount) {
    health -= damageAmount;
}

bool Monster::isDead() const {
    return health <= 0;
}

std::string Monster::getName() const { return name; }
int Monster::getStrength() const { return strength; }
int Monster::getHealth() const { return health; }
int Monster::getDeathXP() const { return deathXP; }
int Monster::getPositionX() const { return positionX; }
int Monster::getPositionY() const { return positionY; }
