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

void Inventory::pickUpWeapon() {
    if (weapons.size() >= maxNumberOfWeapons)
        return;

    weapons.emplace_back(Weapon{}); }

void Inventory::nextWeapon() {
    if (weapons.size() == 1) return;

    currentWeapon++;

    if (currentWeapon > weapons.size()-1) {
        currentWeapon = 0;
    }
}

Weapon Inventory::getCurrentWeapon() {
    return weapons[currentWeapon];
}

bool Inventory::weaponSlotsFull() {
    return weapons.size() == maxNumberOfWeapons;
}

void Inventory::removeGoldCoin() {
    if (goldCoins > 0)
        goldCoins--;
}

void Inventory::removeHealthPotion() {
    if (healthPotions > 0)
        healthPotions--;
}

void Inventory::removeCurrentWeapon() {
    auto weapon = weapons[currentWeapon];
    auto iter = std::find(weapons.begin(), weapons.end(), weapon);

    weapons.erase(iter);
}

int Inventory::getNumGoldCoins() const { return goldCoins; }
int Inventory::getNumHealthPotions() const { return healthPotions; }
std::vector<Weapon> Inventory::getWeapons() const { return weapons; }

