//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_PLAYER_H
#define CODE_PLAYER_H

#include <algorithm>
#include "GameMap.h"
#include "Inventory.h"
#include "utility.h"
#include "Monster.h"
#include "Skeleton.h"
#include "Zombie.h"


class Player {
    static constexpr int defaultStrength{20};
    static constexpr int defaultHealth{50};
    static constexpr int defaultXP{0};
    static constexpr int defaultStartPositionX{5};
    static constexpr int defaultStartPositionY{5};

private:
    Inventory inventory;
    GameMap map; // Needs access to map for boundary checking
    std::vector<Monster*>& monsters;

    int strength;
    int health;
    int xp;

    int positionX;
    int positionY;
    int newPositionX;
    int newPositionY;

    bool attacking{false};

public:
    Player(const GameMap& map, std::vector<Monster*>& monsters);
    Player(const GameMap &map, int startPositionX, int startPositionY, std::vector<Monster*>& monsters);
    void update();

    void increaseXP(int amount);
    bool isDead() const;

    int getStrength() const;
    int getHealth() const;
    int getXP() const;
    int getPositionX() const;
    int getPositionY() const;

    Inventory getInventory() const;

private:
    void handleInput();
    void renderPlayer();
    void checkCollisions();
    void attack(Monster *monster);
    void checkMonster(int x, int y);
};


#endif //CODE_PLAYER_H
