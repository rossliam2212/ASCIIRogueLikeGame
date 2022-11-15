//
// Created by Liam on 19/10/2022.
//

#include "Inventory.h"
#include "Player.h"

Inventory::Inventory(const HistoryLogger& historyLogger)
    : goldCoins{},
      healthPotions{},
      items{},
      weapons{},
      historyLogger{historyLogger} {
}

void Inventory::addItem(Item* item) {
    if (item->getName() == GoldCoin::goldCoinName)
        goldCoins++;
    else if (item->getName() == HealthPotion::healthPotionName)
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

Weapon Inventory::getCurrentWeapon() {
    auto cw = dynamic_cast<Weapon&>(*(weapons[currentWeapon]));
    return cw;
}

bool Inventory::weaponSlotsFull() {
    return weapons.size() == maxNumberOfWeapons;
}

void Inventory::removeGoldCoin() {
    if (goldCoins > 0) {
        goldCoins--;

        for (auto* item: items) {
            if (item->getName() == GoldCoin::goldCoinName && !item->isUsed()) {
                item->use();
                historyLogger.logUsedItem(item);
//                removeItem(item, false);
                break;
            }
        }
    }
}

void Inventory::removeHealthPotion() {
    if (healthPotions > 0) {
        healthPotions--;

        for (auto* item: items) {
            if (item->getName() == HealthPotion::healthPotionName && !item->isUsed()) {
                item->use();
                historyLogger.logUsedItem(item);
//                removeItem(item, false);
                break;
            }
        }
    }
}

void Inventory::removeCurrentWeapon() {
    auto weapon = weapons[currentWeapon];
    historyLogger.logUsedItem(weapon);
    removeItem(weapon, true);
}

void Inventory::removeItem(Item* item, bool isWeapon) {
    if (isWeapon) {
        auto iter = std::find(std::begin(weapons), std::end(weapons), item);
        if (iter != std::end(weapons)) {
            weapons.erase(iter);
            return;
        }
    } else {
        auto iter = std::find(std::begin(items), std::end(items), item);
        if (iter != std::end(items)) {
            weapons.erase(iter);
            return;
        }
    }
}

int Inventory::getNumGoldCoins() const { return goldCoins; }
int Inventory::getNumHealthPotions() const { return healthPotions; }
std::vector<Item*> Inventory::getWeapons() const { return weapons; }

