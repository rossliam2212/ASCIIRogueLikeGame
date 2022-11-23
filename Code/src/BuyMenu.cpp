//
// Created by Liam on 11/16/2022.
//

#include "BuyMenu.h"
#include "utility.h"

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

/**
 * Creates the purchasable weapons depending on the current level of the game
 * and players xp level.
 */
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
        case 4:
            minStrength = level4WeaponStrengthMin;
            maxStrength = level4WeaponStrengthMax;
            break;
        case 5:
            minStrength = level5WeaponStrengthMin;
            maxStrength = level5WeaponStrengthMax;
            break;
    }

    for (int i = 0; i < numberOfWeapons; i++) {
        auto name = buyMenuWeaponNames[Weapon::randomNum(0, (int)buyMenuWeaponNames.size() - 1)];
        auto strength = Weapon::randomNum(minStrength, maxStrength);
        auto cost = getWeaponCost(strength);

        weapons.emplace_back(new Weapon{name, strength, cost, 3});
    }
}

/**
 * Displays the weapons that the player can purchase.
 */
void BuyMenu::displayWeapons() {
    utility::gotoScreenPosition(0, 40);
    std::cout << "Buy Menu: (Level - " << currentLevel << ") {\n";
    for (int i = 0; i < numberOfWeapons; i++) {
        std::cout << "\t" << (i+1) << " - " << *weapons[i] << " - " << weapons[i]->getPrice() << " gold coins\n";
    }
    std::cout << "}";
}

/*
 * Clears the buy menu ui from the screen.
 */
void BuyMenu::clearBuyMenu() {
    utility::gotoScreenPosition(0, 40);
    std::cout << "                                                                             \n";
    std::cout << "                                                                             \n";
    std::cout << "                                                                             \n";
    std::cout << "                                                                             \n";
}

/**
 *
 * @param choice The weapon chosen by the player
 * @return The weapon at the given index.
 */
Weapon* BuyMenu::pickWeapon(int choice) {
    return weapons[choice-1];
}

/**
 * Sets the price of the created weapon depending on its strength and the current level
 * @param weaponStrength The strength of the weapon.
 * @return The price for the created weapon.
 */
int BuyMenu::getWeaponCost(int weaponStrength) const {
    int cost;

    switch(currentLevel) {
        case 1:
            if (weaponStrength <= 25) cost = 10;
            else cost = 12;
            break;
        case 2:
            if (weaponStrength <= 35) cost = 15;
            else cost = 18;
            break;
        case 3:
            if (weaponStrength <= 45) cost = 21;
            else cost = 24;
            break;
        case 4:
            if (weaponStrength <= 55) cost = 28;
            else cost = 32;
            break;
        case 5:
            if (weaponStrength <= 65) cost = 35;
            else cost = 40;
            break;
    }
    return playersXPLevel >= discountXPLevel ? cost - discount : cost; // 5 coin discount if players xp level is 3 or above
}
