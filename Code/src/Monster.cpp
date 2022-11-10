//
// Created by Liam on 19/10/2022.
//

#include "Monster.h"

Monster::Monster(const GameMap& map, int strength, int health, int deathXP, int followDistance, Point startPosition)
    : map{map},
      strength{strength},
      health{health},
      deathXP{deathXP},
      followDistance{followDistance},
      position{startPosition},
      newPosition{startPosition}{
}

bool Monster::operator==(const Monster& rhs) const {
    return position == rhs.position;
}

void Monster::checkInFollowRange() {

    if (map.getXY(position.getX(), position.getY() +1) == GameMap::playerChar ||
        map.getXY(position.getX(), position.getY() + 2) == GameMap::playerChar ||
        map.getXY(position.getX(), position.getY() + 3) == GameMap::playerChar) {
        utility::gotoScreenPosition(position);
        std::cout << "Player in range \n";
        move = Down;
    } else
        move = Idle;

//    for (int i = 1; i <= followDistance; i++) {
//        // Checking positions above
//        if (map.getXY(positionX, positionY - i) == GameMap::playerChar) {
//            move = Up;
//            utility::gotoScreenPosition((short)positionX,(short)positionY);
//            std::cout << "Player in range - " << i << "\n";
//        }
//
//        // Checking positions below
//        if (map.getXY(positionX, positionY + i) == GameMap::playerChar) {
//            move = Down;
//            utility::gotoScreenPosition((short)positionX,(short)positionY);
//            std::cout << "Player in range - " << i << "\n";
//        }
//
//        // Checking positions to the right
//        if (map.getXY(positionX + i, positionY) == GameMap::playerChar) {
//            move = Right;
//            utility::gotoScreenPosition((short)positionX,(short)positionY);
//            std::cout << "Player in range - " << i << "\n";
//        }
//
//        // Checking positions left
//        if (map.getXY(positionX - i, positionY) == GameMap::playerChar) {
//            move = Left;
//            utility::gotoScreenPosition((short)positionX,(short)positionY);
//            std::cout << "Player in range - " << i << "\n";
//        }
//    }
}

bool Monster::inFollowRange() {
    for (int i = 1; i <= followDistance; i++) {
        if (map.getXY(position.getX(), position.getY() - i) == GameMap::playerChar ||
            map.getXY(position.getX(), position.getY() + i) == GameMap::playerChar ||
            map.getXY(position.getX() - i, position.getY()) == GameMap::playerChar ||
            map.getXY(position.getX() + i, position.getY()) == GameMap::playerChar) {
            return true;
        }
    }
    return false;
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
