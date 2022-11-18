//
// Created by Liam on 22/10/2022.
//

#ifndef CODE_WEAPON_H
#define CODE_WEAPON_H

#include <iostream>
#include <string>
#include <random>
#include <array>

#include "Item.h"

class Weapon : public Item {
private:
    static constexpr int minWeaponDamage{10};
    static constexpr int maxWeaponDamage{30};

    int damageAmount;
    int price;

    const std::array<std::string, 10> meleeWeaponNames {
        "Club",
        "Knuckleduster",
        "Staff",
        "Pike",
        "Mace",
        "Tonfa",
        "Stick",
        "Pipe",
        "Hammer",
        "Baton"
    };

public:
    Weapon();
    explicit Weapon(const Point& position);
    Weapon(const std::string &name, int damageAmount, int price);
    ~Weapon() override = default;

    Weapon& operator=(const Weapon& rhs);

    int attack() const;

    std::ostream& write(std::ostream& os) const override;

    bool isEqual(const Item& item) const override;
    int getPrice() const;

private:
    void generateStats();
    static int randomNum(int min, int max);
};


#endif //CODE_WEAPON_H
