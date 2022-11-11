//
// Created by Liam on 22/10/2022.
//

#include "Weapon.h"

Weapon::Weapon(const Point& position)
    : Item{"DefaultItemName", position},
      damageAmount{} {
    generateStats();
}

bool Weapon::operator==(const Weapon &rhs) const {
    return damageAmount == rhs.damageAmount && name == rhs.name;
}

int Weapon::attack() const { return damageAmount; }

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

std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
    os << weapon.name << ": " << weapon.damageAmount << " damage";
    return os;
}
