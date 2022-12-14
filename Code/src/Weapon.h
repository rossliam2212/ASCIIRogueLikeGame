//
// Created by Liam on 22/10/2022.
//

#ifndef CODE_WEAPON_H
#define CODE_WEAPON_H

#include <iostream>
#include <iomanip>
#include <random>
#include <array>

#include "Item.h"

class Weapon : public Item {
private:
    static constexpr int defaultNumberOfAttacks{3};
    static constexpr int minWeaponDamage{10};
    static constexpr int maxWeaponDamage{20};

    int damageAmount;
    int price;
    int numberOfAttacks;

    static const std::array<std::string, 9> meleeWeaponNames;

public:
    Weapon();
    explicit Weapon(const Point& position);
    Weapon(const std::string &name, int damageAmount, int price, int numberOfAttacks);
    ~Weapon() override = default;

    Weapon& operator=(const Weapon& rhs);

    std::ostream& write(std::ostream& os) const override;

    int attack() const;
    void useWeapon();
    bool isBroken() const;
    int getAttacksRemaining() const;

    bool isEqual(const Item& item) const override;
    int getPrice() const;
    static int randomNum(int min, int max);

private:
    void generateStats();
};

#endif //CODE_WEAPON_H