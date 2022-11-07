//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_INVENTORY_H
#define CODE_INVENTORY_H

#include <vector>
#include "Weapon.h"

class Inventory {
public:
    static constexpr int healthPotionIncrease{25};

private:
    int goldCoins;
    int healthPotions;

    // Weapons
    std::vector<Weapon> weapons;

public:
    Inventory();
    void pickUpGoldCoin();
    void pickUpHealthPotion();
    void pickUpWeapon();

    void removeGoldCoin();
    void removeHealthPotion();

    int getNumGoldCoins() const;
    int getNumHealthPotions() const;
    std::vector<Weapon> getWeapons() const;
};


#endif //CODE_INVENTORY_H
