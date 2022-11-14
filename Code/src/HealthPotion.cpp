//
// Created by Liam on 11/11/2022.
//

#include "HealthPotion.h"


const std::string HealthPotion::healthPotionName = "Health Potion";

HealthPotion::HealthPotion(const Point& position)
    : Item(healthPotionName, position) {
}


