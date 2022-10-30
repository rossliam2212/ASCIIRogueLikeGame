//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"

Skeleton::Skeleton(const GameMap& map)
    : Monster(map, skeletonStrength, skeletonHealth, skeletonXP, skeletonFollowDistance) {
}

Skeleton::Skeleton(const GameMap& map, int strength, int health, int xp)
    : Monster(map, strength, health, xp, skeletonFollowDistance) {
}

