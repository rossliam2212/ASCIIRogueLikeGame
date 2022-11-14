//
// Created by Liam on 19/10/2022.
//

#include "Inventory.h"

Inventory::Inventory()
    : goldCoins{},
      healthPotions{},
      items{},
      weapons{} {
}

void Inventory::addItem(Item* item) {
    if (item->getName() != GoldCoin::goldCoinName)
        goldCoins++;
    else if (item->getName() != HealthPotion::healthPotionName)
        healthPotions++;
    else {
        weapons.emplace_back(item);
        return;
    }
    items.emplace_back(item);
}

void Inventory::nextWeapon() {
    if (weapons.size() == 1) return;

    currentWeapon++;

    if (currentWeapon > weapons.size()-1) {
        currentWeapon = 0;
    }
}

Item Inventory::getCurrentWeapon() {
    return *(weapons[currentWeapon]);
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
std::vector<Item*> Inventory::getWeapons() const { return weapons; }

