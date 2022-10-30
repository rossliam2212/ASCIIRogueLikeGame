//
// Created by Liam on 19/10/2022.
//

#include "Inventory.h"

Inventory::Inventory()
    : numGoldCoins{},
      numHealthPotion{} {
}

void Inventory::pickUpGoldCoin() { numGoldCoins++; }

int Inventory::getNumGoldCoins() const { return numGoldCoins; }

