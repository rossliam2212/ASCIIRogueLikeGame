//
// Created by Liam on 19/10/2022.
//

#include "Inventory.h"

Inventory::Inventory()
    : goldCoins{},
      healthPotions{},
      weapons{} {
}

void Inventory::pickUpGoldCoin() { goldCoins++; }
void Inventory::pickUpHealthPotion() { healthPotions++; }
void Inventory::pickUpWeapon() { weapons.emplace_back(Weapon{}); }

void Inventory::removeGoldCoin() {
    if (goldCoins > 0)
        goldCoins--;
}

void Inventory::removeHealthPotion() {
    if (healthPotions > 0)
        healthPotions--;
}

int Inventory::getNumGoldCoins() const { return goldCoins; }
int Inventory::getNumHealthPotions() const { return healthPotions; }
std::vector<Weapon> Inventory::getWeapons() const { return weapons; }

