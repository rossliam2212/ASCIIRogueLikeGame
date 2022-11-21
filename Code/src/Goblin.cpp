//
// Created by Liam on 18/11/2022.
//

#include "Goblin.h"

const std::string Goblin::goblinName = "Goblin";

Goblin::Goblin(Player* player, const GameMap& map, const Point& position)
    : Monster{player, map, goblinStrength, goblinHealth, goblinDeathXP, goblinFollowDistance, position} {
    name = goblinName;;
}

void Goblin::update() {

}

void Goblin::render() {

}

void Goblin::attack() {

}