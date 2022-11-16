//
// Created by Liam on 22/10/2022.
//

#include "Weapon.h"

Weapon::Weapon()
    : Weapon{Point{}} {
}

Weapon::Weapon(const Point& position)
    : Item{"DefaultItemName", position},
      damageAmount{} {
    generateStats();
}

Weapon& Weapon::operator=(const Weapon &rhs) {
    if (this != &rhs) {
        Item::operator=(rhs);
        damageAmount = rhs.damageAmount;
    }
    return *this;
}

int Weapon::attack() const { return damageAmount; }

std::ostream& Weapon::write(std::ostream& os) const {
    os << name << ": " << damageAmount << " damage";
    return os;
}

bool Weapon::isEqual(const Item& item) const {
    auto v = dynamic_cast<const Weapon&>(item);
    return Item::isEqual(v) && v.damageAmount == damageAmount;
}


void Weapon::generateStats() {
    name = weaponNames[randomNum(0, (int)weaponNames.size() - 1)];
    damageAmount = randomNum(minWeaponDamage, maxWeaponDamage);
}

int Weapon::randomNum(int min, int max) {
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}

