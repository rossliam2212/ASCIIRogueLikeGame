//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_INVENTORY_H
#define CODE_INVENTORY_H

#include <algorithm>
#include <vector>
#include "Item.h"
#include "GoldCoin.h"
#include "HealthPotion.h"
#include "Weapon.h"
#include "HistoryLogger.h"

class Player;

class Inventory {
public:
    static constexpr int maxNumberOfWeapons{3};

private:
    // Items
    std::vector<Item*> items;
    int goldCoins;
    int healthPotions;

    // Weapons
    std::vector<Item*> weapons;
    int currentWeapon{};

    HistoryLogger historyLogger;

public:
    Inventory(const HistoryLogger& historyLogger);
    void addItem(Item* item);

    void nextWeapon();
    Weapon* getCurrentWeapon();
    bool weaponSlotsFull();

    void removeGoldCoin();
    void removeHealthPotion();
    void removeCurrentWeapon(bool weaponBroken);

    int getNumGoldCoins() const;
    int getNumHealthPotions() const;
    std::vector<Item*> getWeapons() const;

private:
    void removeItem(Item* item, bool isWeapon);
};


#endif //CODE_INVENTORY_H
