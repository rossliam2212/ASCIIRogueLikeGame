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

/**
 * Adds an item to the players inventory.
 * The item is checked to see if it is a weapon. If the item is a weapon, then it is
 * added to the one of the players weapon slots, otherwise it is added to the main inventory.
 * @param item The item to add.
 */
void Inventory::addItem(Item* item) {
    if (item->getName() == GoldCoin::goldCoinName)
        goldCoins++;
    else if (item->getName() == HealthPotion::healthPotionName)
        healthPotions++;
    else {
        if (!weaponSlotsFull())
            weapons.emplace_back(item);
        return;
    }
    items.emplace_back(item);
}

/**
 * Cycles through the players weapon slots.
 * Called when the player presses the Right Arrow.
 */
void Inventory::nextWeapon() {
    if (weapons.size() == 1) return;

    currentWeapon++;

    if (currentWeapon > weapons.size()-1) {
        currentWeapon = 0;
    }
}

/**
 * Getter for he players current weapon.
 * @return The players current weapon.
 */
Weapon* Inventory::getCurrentWeapon() {
    auto cw = dynamic_cast<Weapon*>((weapons[currentWeapon]));
    return cw;
}

/**
 * Checks if the players weapon slots are full.
 * @return True if the players weapon slots are full, False otherwise.
 */
bool Inventory::weaponSlotsFull() {
    return weapons.size() == maxNumberOfWeapons;
}

/**
 * Removes a gold coin from the players inventory.
 * Called when the players buy a weapon with their gold coins from the buy menu.
 */
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

/**
 * Removes a health potion from the players inventory.
 * Called when the player presses 'R' to use a health potion.
 */
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

/**
 * Removes the players current weapon from their inventory.
 * Called when the player presses 'Q' to drop their current weapon.
 */
void Inventory::removeCurrentWeapon(bool weaponBroken) {
    auto weapon = weapons[currentWeapon];
    currentWeapon = 0;

    if (!weaponBroken)
        historyLogger.logUsedItem(weapon);
    else
        historyLogger.logWeaponBroke(weapon);

    removeItem(weapon, true);
}

/**
 * Removes an item from the players inventory.
 * @param item The item to remove.
 * @param isWeapon True if the item is a weapon, False otherwise.
 */
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

// Getters & Setters
int Inventory::getNumGoldCoins() const { return goldCoins; }
int Inventory::getNumHealthPotions() const { return healthPotions; }
std::vector<Item*> Inventory::getWeapons() const { return weapons; }


