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
    if (!player->getAttacking() && !attacking) {
        auto playerX = player->getPosition().getX();
        auto playerY = player->getPosition().getY();

        for (int i = 0; i < followDistance; i++) {
            // Up
            if (position.getX() == playerX && position.getY() - i == playerY) {
                move = Up;
                break;
            }
            // Down
            else if (position.getX() == playerX && position.getY() + i == playerY) {
                move = Down;
                break;
            }
            // Right
            else if (position.getX() + i == playerX && position.getY() == playerY) {
                move = Right;
                break;
            }
            // Left
            else if (position.getX() - i == playerX && position.getY() == playerY) {
                move = Left;
                break;
            }
            // Idle
            else
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

bool Monster::getIsAttacking() const { return attacking; }
void Monster::setAttacking() { attacking = true; }
