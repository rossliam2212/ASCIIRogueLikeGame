//
// Created by Liam on 11/11/2022.
//

#include "GoldCoin.h"

const std::string GoldCoin::goldCoinName = "Gold Coin";

GoldCoin::GoldCoin(const Point& position)
    : Item(goldCoinName, position) {
}