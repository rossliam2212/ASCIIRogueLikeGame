//
// Created by Liam on 22/10/2022.
//

#include "Weapon.h"

Weapon::Weapon()
    : Weapon{Point{}} {
}

Weapon::Weapon(const Point& position)
    : Item{"DefaultItemName", position},
      damageAmount{},
      price{},
      numberOfAttacks{defaultNumberOfAttacks} {
    generateStats();
}

Weapon::Weapon(const std::string &name, int damageAmount, int price, int numberOfAttacks)
    : Item{name, Point{}},
      damageAmount{damageAmount},
      price{price},
      numberOfAttacks{numberOfAttacks} {
}

Weapon& Weapon::operator=(const Weapon &rhs) {
    if (this != &rhs) {
        Item::operator=(rhs);
        damageAmount = rhs.damageAmount;
    }
    return *this;
}

int Weapon::attack() {
    numberOfAttacks--;
    return damageAmount;
}

bool Weapon::isBroken() const {
    return numberOfAttacks <= 0;
}

int Weapon::getAttacksRemaining() const {
    return numberOfAttacks;
}

std::ostream& Weapon::write(std::ostream& os) const {
    os << std::left << std::setw(10) << name << ": " << damageAmount << " damage (" << numberOfAttacks << " attacks)";
    return os;
}

bool Weapon::isEqual(const Item& item) const {
    auto v = dynamic_cast<const Weapon&>(item);
    return Item::isEqual(v) && v.damageAmount == damageAmount;
}

int Weapon::getPrice() const { return price; }

void Weapon::generateStats() {
    name = meleeWeaponNames[randomNum(0, (int)meleeWeaponNames.size() - 1)];
    damageAmount = randomNum(minWeaponDamage, maxWeaponDamage);

    if (damageAmount >= 10 && damageAmount <= 15)
        price = 3;
    else if (damageAmount > 15 && damageAmount <= 25)
        price = 8;
    else
        price = 12;
}

int Weapon::randomNum(int min, int max) {
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}


