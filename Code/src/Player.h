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
#include "BuyMenu.h"

class Player {
public:
    static constexpr int defaultMaxHealth{100};
    static constexpr int defaultStrength{10};
    static constexpr int defaultHealth{50};

    static constexpr int xpLevelUpValue{70}; // Amount of xp needed to level up
    static constexpr int maxXPLevel{5};
    static constexpr int defaultXP{0};

    static constexpr int xpLevelUpHealthIncrease{10}; // Amount the health increases when the player levels up their xp
    static constexpr int xpLevelUpStrengthIncrease{5}; // Amount the strength increases when the player levels up their xp

    static constexpr int defaultStartPositionX{5};
    static constexpr int defaultStartPositionY{5};

private:
    HistoryLogger historyLogger;
    Inventory inventory;
    GameMap map; // Needs access to map for boundary checking
    std::vector<Monster*>& monsters; // Reference to vector of monsters from GameManager
    std::vector<Item*>& items; // Reference to vector of items from GameManager

    int strength;
    int health;
    int maxHealth;
    int xpLevel;
    int xp;
    int& gameLevel; // Reference to game level from GameManager

    Point position;
    Point newPosition;

    bool attacking{false};
    bool levelChange{false};
    bool buyMenu{false};
    bool boughtWeapon{false};

    bool removeItemPressed{false};
    bool nextWeaponPressed{false};
    bool removeCurrentWeaponPressed{false};

public:
    Player(const GameMap& map, std::vector<Monster*>& monsters, std::vector<Item*>& items, const HistoryLogger& hl, int& gameLevel);
    Player(const GameMap& map, Point& startPosition, std::vector<Monster*>& monsters, std::vector<Item*>& items, const HistoryLogger& hl, int& gameLevel);

    void update();

    void levelUp();
    void increaseXP(int amount);
    void takeDamage(int amount);
    bool isDead() const;
    void setPosition(const Point& newPos);

    int getStrength() const;
    int getHealth() const;
    int getXP() const;
    int getXPLevel() const;
    bool getAttacking() const;
    bool getBuyMenu() const;
    Point getPosition() const;
    Inventory getInventory() const;

    bool getLevelChange() const;
    void resetLevelChange();

    bool getNextWeaponPressed() const;
    void resetNextWeaponPressed();

    bool getRemoveCurrentWeaponPressed() const;
    void resetRemoveCurrentWeaponPressed();

    bool getBoughtWeapon() const;
    void resetBoughtWeapon();


private:
    void handleInput();
    void renderPlayer();
    void checkCollisions();
    void attack(Monster* monster);
    void addMonsterDeathGold(int gold);
    void checkMonster(int x, int y);
    void checkItem(int x, int y);
    void openBuyMenu();
    static void clearAttackUI(int y);
};


#endif //CODE_PLAYER_H
