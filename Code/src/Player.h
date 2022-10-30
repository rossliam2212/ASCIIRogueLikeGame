//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_PLAYER_H
#define CODE_PLAYER_H

#include "GameMap.h"
#include "Inventory.h"
#include "utility.h"

class Player {
    static constexpr int maxHealth{100};
    static constexpr int defaultStrength{20};
    static constexpr int defaultHealth{50};
    static constexpr int defaultXP{0};
    static constexpr int defaultStartPositionX{5};
    static constexpr int defaultStartPositionY{5};

private:
//    const char playerSymbol{'@'};

    int strength;
    int health;
    int xp;

    int positionX;
    int positionY;
    int newPositionX;
    int newPositionY;

    Inventory inventory;
    GameMap map; // Needs access to map for boundary checking

public:
    explicit Player(const GameMap& map);
    Player(const GameMap& map, int startPositionX, int startPositionY);
    void update();

    void increaseXP(int amount);

    int getStrength() const;
    int getHealth() const;
    int getXP() const;

    Inventory getInventory() const;

private:
    void handleInput();
    void renderPlayer();
};


#endif //CODE_PLAYER_H
