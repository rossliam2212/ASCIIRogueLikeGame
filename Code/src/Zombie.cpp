//
// Created by Liam on 30/10/2022.
//

#include "Zombie.h"
#include "Player.h"

Zombie::Zombie(Player* player, const GameMap& map, int level, const Point& position)
    : Monster(player, map, level, zombieHealth, zombieDeathXP, zombieFollowDistance, zombieDeathGold, position) {
    name = zombieName;
    setStrength(zombieStrength);
}

/**
 * Update - called continuously until the Zombie is dead.
 */
void Zombie::update() {
    if (!isDead()) {
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
}

/**
 * Renders the Zombie in the correct xy position whenever he moves.
 */
void Zombie::render() {
    if (newPosition == player->getPosition()) {
        utility::gotoScreenPosition(position);
        std::cout << GameMap::zombieChar;
        map.setXY(position, GameMap::zombieChar);
    }
    else {
        utility::gotoScreenPosition(position);
        std::cout << " ";
        map.setXY(position, GameMap::defaultChar);

        utility::gotoScreenPosition(newPosition);
        std::cout << GameMap::zombieChar;
        map.setXY(newPosition, GameMap::zombieChar);

        position = newPosition;
    }
    Sleep(120);
}

/**
 * @return The Zombies strength when he is attacking.
 */
int Zombie::attack() {
    return strength;
}