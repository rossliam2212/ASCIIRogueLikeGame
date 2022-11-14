//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_GOLDCOIN_H
#define CODE_GOLDCOIN_H

#include "Item.h"

class GoldCoin : public Item {
public:
    static const std::string goldCoinName;
    GoldCoin(const Point& position);
};


#endif //CODE_GOLDCOIN_H
