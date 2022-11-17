//
// Created by Liam on 11/16/2022.
//

#ifndef CODE_BUYMENU_H
#define CODE_BUYMENU_H

#include <vector>
#include "Weapon.h"

class BuyMenu {
private:
    static constexpr int numberOfWeapons{3};

    int currentLevel;
    int playersXPLevel;
    std::vector<Weapon*> weapons;

    const std::array<std::string, 7> buyMenuWeaponNames {
        "Machete",
        "Stiletto",
        "Katana",
        "Karambit",
        "Bayonet",
        "Tomahawk",
        "Balisong"
    };

public:
    BuyMenu(int currentLevel, int playersXPLevel);

private:
    void createWeapons();
    void displayWeapons();
};


#endif //CODE_BUYMENU_H
