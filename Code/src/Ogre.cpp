//
// Created by Liam on 18/11/2022.
//

#include "Ogre.h"
#include "Player.h"

const std::string Ogre::ogreName = "Ogre";

Ogre::Ogre(Player* player, const GameMap& map, const Point& position)
    : Monster{player, map, ogreStrength, ogreHealth, ogreDeathXP, ogreFollowDistance, position} {
    name = ogreName;
}

void Ogre::update() {
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

void Ogre::render() {
    if (newPosition == player->getPosition()) {
        utility::gotoScreenPosition(position);
        std::cout << GameMap::ogreChar;
        map.setXY(position, GameMap::ogreChar);
    }
    else {
        utility::gotoScreenPosition(position);
        std::cout << " ";
        map.setXY(position, GameMap::defaultChar);

        utility::gotoScreenPosition(newPosition);
        std::cout << GameMap::ogreChar;
        map.setXY(newPosition, GameMap::ogreChar);

        position = newPosition;
    }
    Sleep(120);
}

void Ogre::attack() {
    std::cout << "Skeleton Attack\n";
}