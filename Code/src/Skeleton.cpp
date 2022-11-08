//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"

Skeleton::Skeleton(const GameMap& map, int startPositionX, int startPositionY)
    : Monster(map, skeletonStrength, skeletonHealth, skeletonDeathXP, skeletonFollowDistance, startPositionX, startPositionY) {
    name = "Skeleton";
}

void Skeleton::update() {
//    render();


    // Check if the player is near
    // If he is
    //  Then move towards the player
    // Else
    //  Skeleton stays still
}

void Skeleton::render() {
    utility::gotoScreenPosition((short)positionX,(short)positionY);
    std::cout << " ";

    utility::gotoScreenPosition((short)newPositionX, (short)newPositionY);
    std::cout << GameMap::skeletonChar;

    positionX = newPositionX;
    positionY = newPositionY;

    Sleep(120);
}

void Skeleton::attack() {
    std::cout << "Skeleton Attack\n";
}

