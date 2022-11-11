//
// Created by Liam on 22/10/2022.
//

#ifndef CODE_WEAPON_H
#define CODE_WEAPON_H

#include "Item.h"
#include <iostream>
#include <string>
#include <random>
#include <array>

class Weapon : public Item {
    static constexpr int minWeaponDamage{10};
    static constexpr int maxWeaponDamage{30};

    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon);

private:
    int damageAmount;

    std::array<std::string, 11> weaponNames {
        "Bayonet",
        "Karambit",
        "Club",
        "Dagger",
        "Halberd",
        "Lance",
        "Pike",
        "Quarterstaff",
        "Sabre",
        "Sword",
        "Tomahawk"
    };

public:
    Weapon(const Point& position);
    bool operator==(const Weapon& rhs) const;
    int attack() const;

private:
    void generateStats();
    static int randomNum(int min, int max);
};


#endif //CODE_WEAPON_H
