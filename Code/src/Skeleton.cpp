//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"

Skeleton::Skeleton(const GameMap& map, Point position)
    : Monster(map, skeletonStrength, skeletonHealth, skeletonDeathXP, skeletonFollowDistance, position) {
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
    utility::gotoScreenPosition(position);
    std::cout << " ";

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::skeletonChar;

    position = newPosition;

    Sleep(1000);
}

void Skeleton::attack() {
    std::cout << "Skeleton Attack\n";
}

