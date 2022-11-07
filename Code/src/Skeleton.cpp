//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"

Skeleton::Skeleton(const GameMap& map, int startPositionX, int startPositionY)
    : Monster(map, skeletonStrength, skeletonHealth, skeletonDeathXP, skeletonFollowDistance, startPositionX, startPositionY) {
    name = "Skeleton";
}

void Skeleton::update() {
    render();

}

void Skeleton::render() {
    utility::gotoScreenPosition(positionX, positionY);
    std::cout << " ";

    utility::gotoScreenPosition(newPositionX, newPositionY);
    std::cout << GameMap::skeletonChar;

    positionX = newPositionX;
    positionY = newPositionY;

    Sleep(120);
}

void Skeleton::attack() {
    std::cout << "Skeleton Attack\n";
}

