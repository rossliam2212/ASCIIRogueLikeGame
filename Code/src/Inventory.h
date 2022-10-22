//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_INVENTORY_H
#define CODE_INVENTORY_H

#include <vector>
#include "Weapon.h"

class Inventory {
private:
    int numGoldCoins;
    int numHealthPotion;

    // Weapons
    std::vector<Weapon> weapons;

public:
    Inventory();
    void pickUpGoldCoin();
    void pickUpWeapon();

    int getNumGoldCoins() const;
    std::vector<Weapon> getWeapons() const;
    Weapon getRecentPickedUpWeapon() const;
};


#endif //CODE_INVENTORY_H
