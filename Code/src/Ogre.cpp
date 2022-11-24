//
// Created by Liam on 18/11/2022.
//

#include "Ogre.h"
#include "Player.h"

Ogre::Ogre(Player* player, const GameMap& map, const Point& position)
    : Monster{player, map, ogreStrength, ogreHealth, ogreDeathXP, ogreFollowDistance, position} {
    name = ogreName;
}

/**
 * Update - called continuously until the Ogre is dead.
 */
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

/**
 * Renders the Ogre in the correct xy position whenever he moves.
 */
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

/**
 * @return The Ogres strength when he is attacking.
 */
int Ogre::attack() {
    return strength;
}