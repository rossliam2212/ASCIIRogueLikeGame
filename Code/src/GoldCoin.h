//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_GOLDCOIN_H
#define CODE_GOLDCOIN_H

#include "Item.h"

class GoldCoin : public Item {
public:
    static constexpr const char* goldCoinName = "Gold Coin";

    explicit GoldCoin(const Point& position);
    ~GoldCoin() override = default;
};


#endif //CODE_GOLDCOIN_H
