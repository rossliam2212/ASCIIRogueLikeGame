//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_HEALTHPOTION_H
#define CODE_HEALTHPOTION_H

#include "Item.h"

class HealthPotion : public Item {
public:
    static constexpr int healthPotionIncrease{25};

    HealthPotion(const Point& position);
};


#endif //CODE_HEALTHPOTION_H
