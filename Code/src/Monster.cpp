//
// Created by Liam on 19/10/2022.
//

#include "Monster.h"
#include "Player.h"

Monster::Monster(Player* player, const GameMap& map, int strength, int health, int deathXP, int followDistance, int deathGold, Point startPosition)
    : player{player},
      map{map},
      strength{strength},
      health{health},
      deathXP{deathXP},
      followDistance{followDistance},
      deathGold{deathGold},
      position{startPosition},
      newPosition{startPosition}{
}

/**
 * Overloaded == operator.
 * @param rhs The object to compare to.
 * @return True if the objects are equal, False otherwise.
 */
bool Monster::operator==(const Monster& rhs) const {
    return position == rhs.position && name == rhs.name;
}

/**
 * Checks if the monster is within follow range to the player.
 */
void Monster::checkInFollowRange() {
    if (!player->getAttacking() && !attacking) {
        auto playerX = player->getPosition().getX();
        auto playerY = player->getPosition().getY();

        for (int i = 1; i < followDistance; i++) {
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

/**
 * Deals damage to to monster.
 * @param damageAmount The damage to deal.
 */
void Monster::takeDamage(int damageAmount) {
    health -= damageAmount;

    if (health <= 0) {
        health = 0;
        dead = true;
    }
}

/**
 * Checks if the monster is dead.
 * @return True if the monster is dea, false otherwise.
 */
bool Monster::isDead() {
    return dead;
}

/**
 * Sets the monsters dead flag to true - indicating that the monster is dead and wont be used anymore.
 * Used when a monster is either killed or on monsters that are still alive after the player moves to
 * the next level.
 */
void Monster::setIsDead() {
    dead = true;
}

// Getters & Setters
std::string Monster::getName() const { return name; }
int Monster::getStrength() const { return strength; }
int Monster::getHealth() const { return health; }
int Monster::getDeathXP() const { return deathXP; }
int Monster::getDeathGold() const { return deathGold; }
Point Monster::getPosition() const { return position; }

bool Monster::getIsAttacking() const { return attacking; }
void Monster::setAttacking() { attacking = true; }
