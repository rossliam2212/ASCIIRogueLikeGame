//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"

Skeleton::Skeleton(const GameMap& map, int startPositionX, int startPositionY)
    : Monster(map, skeletonStrength, skeletonHealth, skeletonDeathXP, skeletonFollowDistance, startPositionX, startPositionY) {
}

void Skeleton::update() {
    render();
    // check for attack
}

void Skeleton::render() {}

void Skeleton::attack() {
    std::cout << "Skeleton Attack\n";
}

