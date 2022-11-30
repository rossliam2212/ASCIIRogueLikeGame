//
// Created by Liam on 30/10/2022.
//

#include "Skeleton.h"
#include "Player.h"

Skeleton::Skeleton(Player* player, const GameMap& map, int level, const Point& position)
    : Monster(player, map, level, skeletonHealth, skeletonDeathXP, skeletonFollowDistance, skeletonDeathGold, position) {
    name = skeletonName;
    setStrength(skeletonStrength);
}

/**
 * Update - called continuously until the Skeleton is dead.
 */
void Skeleton::update() {
    if (!isDead()) {
        checkInFollowRange();

        if(move != Idle) {
            switch(move) {
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
}

/**
 * Renders the Skeleton in the correct xy position whenever he moves.
 */
void Skeleton::render() {
    if (newPosition == player->getPosition()) {
        utility::gotoScreenPosition(position);
        std::cout << GameMap::skeletonChar;
        map.setXY(position, GameMap::skeletonChar);
    }
    else {
        utility::gotoScreenPosition(position);
        std::cout << " ";
        map.setXY(position, GameMap::defaultChar);

        utility::gotoScreenPosition(newPosition);
        std::cout << GameMap::skeletonChar;
        map.setXY(newPosition, GameMap::skeletonChar);

        position = newPosition;
    }
    Sleep(120);
}

/**
 * @return The Skeletons strength when he is attacking.
 */
int Skeleton::attack() {
    return strength;
}

