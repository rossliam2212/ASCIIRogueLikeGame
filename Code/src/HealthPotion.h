//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_HEALTHPOTION_H
#define CODE_HEALTHPOTION_H

#include "Item.h"

class HealthPotion : public Item {
public:
    static const std::string healthPotionName;
//    static constexpr int healthPotionIncrease{25};

    explicit HealthPotion(const Point& position);
    ~HealthPotion() override = default;
};


#endif //CODE_HEALTHPOTION_H
