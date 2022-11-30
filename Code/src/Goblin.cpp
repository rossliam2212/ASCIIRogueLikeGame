//
// Created by Liam on 18/11/2022.
//

#include "Goblin.h"
#include "Player.h"

Goblin::Goblin(Player* player, const GameMap& map, int level, const Point& position)
    : Monster{player, map, level, goblinHealth, goblinDeathXP, goblinFollowDistance, goblinDeathGold,position} {
    name = goblinName;
    setStrength(goblinStrength);
}

/**
 * Update - called continuously until the Goblin is dead.
 */
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

/**
 * Renders the Goblin in the correct xy position whenever he moves.
 */
void Goblin::render() {
    if (newPosition == player->getPosition()) {
        utility::gotoScreenPosition(position);
        std::cout << GameMap::goblinChar;
        map.setXY(position, GameMap::goblinChar);
    }
    else {
        utility::gotoScreenPosition(position);
        std::cout << " ";
        map.setXY(position, GameMap::defaultChar);

        utility::gotoScreenPosition(newPosition);
        std::cout << GameMap::goblinChar;
        map.setXY(newPosition, GameMap::goblinChar);

        position = newPosition;
    }
    Sleep(120);
}

/**
 * @return The Goblins strength when he is attacking.
 */
int Goblin::attack() {
    return strength;
}