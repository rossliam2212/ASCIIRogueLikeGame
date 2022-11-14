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

public:
    Inventory();
    void addItem(Item* item);



    // OLD METHODS

    void nextWeapon();
    Item getCurrentWeapon();

    bool weaponSlotsFull();

    void removeGoldCoin();
    void removeHealthPotion();
    void removeCurrentWeapon();

    int getNumGoldCoins() const;
    int getNumHealthPotions() const;
    std::vector<Item*> getWeapons() const;
};


#endif //CODE_INVENTORY_H
