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
    static constexpr int minNumberOfAttacks{1};
    static constexpr int maxNumberOfAttacks{4};

    static constexpr int level1WeaponStrengthMin{20};
    static constexpr int level1WeaponStrengthMax{29};

    static constexpr int level2WeaponStrengthMin{30};
    static constexpr int level2WeaponStrengthMax{39};

    static constexpr int level3WeaponStrengthMin{40};
    static constexpr int level3WeaponStrengthMax{49};

    static constexpr int level4WeaponStrengthMin{50};
    static constexpr int level4WeaponStrengthMax{59};

    static constexpr int level5WeaponStrengthMin{60};
    static constexpr int level5WeaponStrengthMax{70};

    static constexpr int discountXPLevel{3}; // The XP level the player needs to be to get a discount on weapons
    static constexpr int discount{5}; // The discount the players gets on weapons

    int currentLevel;
    int playersXPLevel;
    std::vector<Weapon*> weapons;

    static const std::array<std::string, 7> buyMenuWeaponNames;

public:
    BuyMenu(int currentLevel, int playersXPLevel);
    ~BuyMenu();
    void displayWeapons();
    static void clearBuyMenu();
    Weapon* pickWeapon(int choice);

private:
    void createWeapons();
    int getWeaponCost(int weaponStrength) const;
};


#endif //CODE_BUYMENU_H
