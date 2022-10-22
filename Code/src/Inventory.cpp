//
// Created by Liam on 19/10/2022.
//

#include "Inventory.h"

Inventory::Inventory()
    : numGoldCoins{},
      numHealthPotion{},
      weapons{} {
}

void Inventory::pickUpGoldCoin() { numGoldCoins++; }
void Inventory::pickUpWeapon() { weapons.emplace_back(Weapon{}); }

int Inventory::getNumGoldCoins() const { return numGoldCoins; }
std::vector<Weapon> Inventory::getWeapons() const { return weapons; }
Weapon Inventory::getRecentPickedUpWeapon() const { return weapons[weapons.size()-1]; }

