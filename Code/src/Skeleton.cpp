//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"

const std::string Skeleton::skeletonName = "Skeleton";

Skeleton::Skeleton(Player* player, const GameMap& map, const Point& position)
    : Monster(player, map, skeletonStrength, skeletonHealth, skeletonDeathXP, skeletonFollowDistance, position) {
    name = skeletonName;
}

void Skeleton::update() {
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

void Skeleton::render() {
    utility::gotoScreenPosition(position);
    std::cout << " ";
    map.setXY(position, GameMap::defaultChar);

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::skeletonChar;
    map.setXY(newPosition, GameMap::skeletonChar);

    position = newPosition;

    Sleep(120);
}

void Skeleton::attack() {
    std::cout << "Skeleton Attack\n";
}

