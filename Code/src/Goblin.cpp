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
    checkInFollowRange();

    if (move != Idle) {
        switch (move) {
            case Up:
                newPosition.setXY(position.getX(), position.getY() - 1);
                break;
            case Down:
                newPosition.setXY(position.getX(), position.getY() + 1);
                break;
            case Right:
                newPosition.setXY(position.getX() + 1, position.getY());
                break;
            case Left:
                newPosition.setXY(position.getX() - 1, position.getY());
                break;
            default:
                break;
        }
        render();
    }
}

void Goblin::render() {
    utility::gotoScreenPosition(position);
    std::cout << " ";
    map.setXY(position, GameMap::defaultChar);

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::goblinChar;
    map.setXY(newPosition, GameMap::goblinChar);

    position = newPosition;

    Sleep(120);
}

void Goblin::attack() {
    std::cout << "Goblin Attack\n";
}