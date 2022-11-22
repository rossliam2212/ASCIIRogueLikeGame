//
// Created by Liam on 30/10/2022.
//

#include "Zombie.h"

const std::string Zombie::zombieName = "Zombie";

Zombie::Zombie(Player* player, const GameMap& map, const Point& position)
    : Monster(player, map, zombieStrength, zombieHealth, zombieDeathXP, zombieFollowDistance, position) {
    name = zombieName;
}

void Zombie::update() {
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

void Zombie::render() {
    utility::gotoScreenPosition(position);
    std::cout << " ";
    map.setXY(position, GameMap::defaultChar);

    utility::gotoScreenPosition(newPosition);
    std::cout << GameMap::zombieChar;
    map.setXY(newPosition, GameMap::zombieChar);

    position = newPosition;

    Sleep(120);
}

void Zombie::attack() {
    std::cout << "Zombie Attack\n";
}