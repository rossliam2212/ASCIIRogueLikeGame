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
#include "HistoryLogger.h"

class Player {
    static constexpr int maxHealth{100};
    static constexpr int defaultStrength{20};
    static constexpr int defaultHealth{50};
    static constexpr int defaultXP{0};
    static constexpr int defaultStartPositionX{5};
    static constexpr int defaultStartPositionY{5};

private:
    HistoryLogger historyLogger;
    Inventory inventory;
    GameMap map; // Needs access to map for boundary checking
    std::vector<Monster*>& monsters;
    std::vector<Item*>& items;

    int strength;
    int health;
    int xp;

    Point position;
    Point newPosition;

    bool attacking{false};

    bool removeItemPressed{false};
    bool nextWeaponPressed{false};
    bool removeCurrentWeaponPressed{false};

public:
    Player(const GameMap& map, std::vector<Monster*>& monsters, std::vector<Item*>& items, const HistoryLogger& hl);
    Player(const GameMap& map, Point& startPosition, std::vector<Monster*>& monsters, std::vector<Item*>& items, const HistoryLogger& hl);

    void update();

    void increaseXP(int amount);
    void takeDamage(int amount);
    bool isDead() const;

    int getStrength() const;
    int getHealth() const;
    int getXP() const;
    Point getPosition() const;
    Inventory getInventory() const;

    bool getRemoveItemPressed() const;
    void resetRemoveItemPressed();

    bool getNextWeaponPressed() const;
    void resetNextWeaponPressed();

    bool getRemoveCurrentWeaponPressed() const;
    void resetRemoveCurrentWeaponPressed();


private:
    void handleInput();
    void renderPlayer();
    void checkCollisions();
    void attack(Monster* monster);
    void checkMonster(int x, int y);
    void checkItem(int x, int y);
};


#endif //CODE_PLAYER_H
