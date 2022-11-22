//
// Created by Liam on 11/16/2022.
//

#include "BuyMenu.h"

BuyMenu::BuyMenu(int currentLevel, int playersXPLevel)
    : currentLevel{currentLevel},
      playersXPLevel{playersXPLevel} {
    createWeapons();
}

BuyMenu::~BuyMenu() {
    for (auto* w : weapons) {
        delete w;
    }
}

void BuyMenu::createWeapons() {
    int minStrength;
    int maxStrength;

    switch(currentLevel) {
        case 1:
            minStrength = level1WeaponStrengthMin;
            maxStrength = level1WeaponStrengthMax;
            break;
        case 2:
            minStrength = level2WeaponStrengthMin;
            maxStrength = level2WeaponStrengthMax;
            break;
        case 3:
            minStrength = level3WeaponStrengthMin;
            maxStrength = level3WeaponStrengthMax;
            break;
    }

    for (int i = 0; i < numberOfWeapons; i++) {
        auto name = buyMenuWeaponNames[Weapon::randomNum(0, (int)buyMenuWeaponNames.size() - 1)];
        auto strength = Weapon::randomNum(minStrength, maxStrength);
        auto cost = getWeaponCost(strength);

        weapons.emplace_back(new Weapon{name, strength, cost});
    }
}

void BuyMenu::displayWeapons() {
    std::cout << "Buy Menu:\n";
    for (int i = 0; i < numberOfWeapons; i++) {
        std::cout << "\t" << (i+1) << " - " << *weapons[i] << "\n";
    }
}

Weapon* BuyMenu::pickWeapon(int choice) {
    return weapons[choice-1];
}

int BuyMenu::getWeaponCost(int weaponStrength) const {
    int cost;

    switch(currentLevel) {
        case 1:
            if (weaponStrength <= 25)
                cost = 10;
            else
                cost = 15;
            break;
        case 2:
            if (weaponStrength <= 40)
                cost = 20;
            else
                cost = 25;
            break;
        case 3:
            if (weaponStrength <= 55)
                cost = 30;
            else
                cost = 35;
            break;
    }
    return playersXPLevel >= 3 ? cost - 5 : cost; // 5 coin discount if players xp level is 3 or above
}