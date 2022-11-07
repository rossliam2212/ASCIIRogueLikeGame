//
// Created by Liam on 30/10/2022.
//

#include "Zombie.h"

Zombie::Zombie(const GameMap& map, int startPositionX, int startPositionY)
    : Monster(map, zombieStrength, zombieHealth, zombieDeathXP, zombieFollowDistance, startPositionX, startPositionY) {
    name = "Zombie";
}

void Zombie::update() {
    render();
    // check for checkMonster
}

void Zombie::render() {}

void Zombie::attack() {
    std::cout << "Zombie Attack\n";
}