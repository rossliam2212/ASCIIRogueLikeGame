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

public:
    Inventory();
    void pickUpGoldCoin();

    int getNumGoldCoins() const;
};


#endif //CODE_INVENTORY_H
