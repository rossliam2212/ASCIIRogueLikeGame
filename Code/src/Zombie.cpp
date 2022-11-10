//
// Created by Liam on 30/10/2022.
//

#include "Zombie.h"

Zombie::Zombie(const GameMap& map, Point position)
    : Monster(map, zombieStrength, zombieHealth, zombieDeathXP, zombieFollowDistance, position) {
    name = "Zombie";
}

void Zombie::update() {
    // Check if the player is near
    // If he is
    //  Then move towards the player
    // Else
    //  Skeleton stays still

    checkInFollowRange();

//    if (move != Idle) {
//        switch (move) {
//            case Up:
//                newPositionY = positionY - 1;
//                break;
//            case Down:
//                newPositionY = positionY + 1;
//                break;
//            case Right:
//                newPositionX = positionX + 1;
//                break;
//            case Left:
//                newPositionX = positionX - 1;
//                break;
//        }
//        render();
//    }
}

void Zombie::render() {
    utility::gotoScreenPosition(position);
    std::cout << " ";

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::zombieChar;

    position = newPosition;

    Sleep(1000);
}

void Zombie::attack() {
    std::cout << "Zombie Attack\n";
}