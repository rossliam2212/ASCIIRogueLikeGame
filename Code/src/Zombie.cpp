//
// Created by Liam on 30/10/2022.
//

#include "Zombie.h"

const std::string Zombie::zombieName = "Zombie";

Zombie::Zombie(Player* player, const GameMap& map, const Point& position)
    : Monster(player, map, zombieStrength, zombieHealth, zombieDeathXP, zombieFollowDistance, position) {
    name = zombieName;
}

void Zombie::update() {
    // Check if the player is near
    // If he is
    //  Then move towards the player
    // Else
    //  Skeleton stays still

    checkInFollowRange();

//    utility::gotoScreenPosition(position);
    if (move != Idle) {
        switch (move) {
            case Up:
//                std::cout << "Up   \n";
                newPosition.setXY(position.getX(), position.getY() - 1);
                break;
            case Down:
//                std::cout << "Down \n";
                newPosition.setXY(position.getX(), position.getY() + 1);
                break;
            case Right:
//                std::cout << "Right\n";
                newPosition.setXY(position.getX() + 1, position.getY());
                break;
            case Left:
//                std::cout << "Left \n";
                newPosition.setXY(position.getX() - 1, position.getY());
                break;
            default:
//                std::cout << "Idle \n";
                break;
        }
        render();
    }
}

void Zombie::render() {
    utility::gotoScreenPosition(position);
    std::cout << " ";

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::zombieChar;

    position = newPosition;

    Sleep(120);
}

void Zombie::attack() {
    std::cout << "Zombie Attack\n";
}