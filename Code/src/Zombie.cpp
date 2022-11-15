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

    utility::gotoScreenPosition(position);
    switch(move) {
        case Idle:
//            std::cout << "Idle\n";
            break;
        case Down:
            std::cout << "Down\n";
            render();
            break;
    }

//    if (move != Idle) {
//        switch (move) {
//            case Up:
//                newPosition.setXY(position.getX(), position.getY() - 1);
//                break;
//            case Down:
//                newPosition.setXY(position.getX(), position.getY() + 1);
//                break;
//            case Right:
//                newPosition.setXY(position.getX() + 1, position.getY());
//                break;
//            case Left:
//                newPosition.setXY(position.getX() - 1, position.getY());
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