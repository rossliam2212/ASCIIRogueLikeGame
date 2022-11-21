//
// Created by Liam on 19/10/2022.
//

#include "Monster.h"
#include "Player.h"

Monster::Monster(Player* player, const GameMap& map, int strength, int health, int deathXP, int followDistance, Point startPosition)
    : player{player},
      map{map},
      strength{strength},
      health{health},
      deathXP{deathXP},
      followDistance{followDistance},
      position{startPosition},
      newPosition{startPosition}{
}

bool Monster::operator==(const Monster& rhs) const {
    return position == rhs.position && name == rhs.name;
}

void Monster::checkInFollowRange() {
    if (!player->getAttacking()) {
        // Up
        if (position.getX() == player->getPosition().getX() && position.getY() - 3 == player->getPosition().getY()) {
            move = Up;
        }
            // Down
        else if (position.getX() == player->getPosition().getX() &&
                 position.getY() + 3 == player->getPosition().getY()) {
            move = Down;
        }
            // Right
        else if (position.getX() + 3 == player->getPosition().getX() &&
                 position.getY() == player->getPosition().getY()) {
            move = Right;
        }
            // Left
        else if (position.getX() - 3 == player->getPosition().getX() &&
                 position.getY() == player->getPosition().getY()) {
            move = Left;
        }
            // Idle
        else {
            move = Idle;
        }
    }
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
Point Monster::getPosition() const { return position; }
