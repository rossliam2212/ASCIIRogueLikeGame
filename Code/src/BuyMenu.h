//
// Created by Liam on 11/16/2022.
//

#ifndef CODE_BUYMENU_H
#define CODE_BUYMENU_H

#include <vector>
#include "utility.h"
#include "Weapon.h"

class BuyMenu {
private:
    static constexpr int numberOfWeapons{3};

    static constexpr int level1WeaponStrengthMin{15};
    static constexpr int level1WeaponStrengthMax{35};

    static constexpr int level2WeaponStrengthMin{30};
    static constexpr int level2WeaponStrengthMax{45};

    static constexpr int level3WeaponStrengthMin{40};
    static constexpr int level3WeaponStrengthMax{60};

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
    ~BuyMenu();
    void displayWeapons();
    void clearBuyMenu();
    Weapon* pickWeapon(int choice);

private:
    void createWeapons();
    int getWeaponCost(int weaponStrength) const;
};


#endif //CODE_BUYMENU_H
