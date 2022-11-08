//
// Created by Liam on 30/10/2022.
//

#include "Zombie.h"

Zombie::Zombie(const GameMap& map, int startPositionX, int startPositionY)
    : Monster(map, zombieStrength, zombieHealth, zombieDeathXP, zombieFollowDistance, startPositionX, startPositionY) {
    name = "Zombie";
}

void Zombie::update() {
//    render();

    // Check if the player is near
    // If he is
    //  Then move towards the player
    // Else
    //  Skeleton stays still
}

void Zombie::render() {}

void Zombie::attack() {
    std::cout << "Zombie Attack\n";
}