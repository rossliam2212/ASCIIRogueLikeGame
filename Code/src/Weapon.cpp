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

/**
 * Overloaded = operator.
 * @param rhs The object on the right hand side to assign to the left.
 * @return A reference to the new object.
 */
Weapon& Weapon::operator=(const Weapon &rhs) {
    if (this != &rhs) {
        Item::operator=(rhs); // Compares the item part of the weapon
        damageAmount = rhs.damageAmount;
    }
    return *this;
}

/**
 * Called when the player uses the weapon to attack.
 * The number of attacks that the weapon has is decremented.
 * @return The damageAmount of the weapon.
 */
int Weapon::attack() {
    numberOfAttacks--;
    return damageAmount;
}

/**
 * Checks if the weapon is broken or not.
 * A weapon os considered broken if it has no attacks remaining.
 * @return
 */
bool Weapon::isBroken() const {
    return numberOfAttacks <= 0;
}

/**
 * Getter for the number of attacks remaining on the weapon.
 * @return The number of attacks remaining on the weapon.
 */
int Weapon::getAttacksRemaining() const {
    return numberOfAttacks;
}

/**
 *
 * @param os The output stream.
 * @return A reference to the output stream.
 */
std::ostream& Weapon::write(std::ostream& os) const {
    os << std::left << std::setw(8) << name << ": " << damageAmount << " damage (" << numberOfAttacks << " attacks)";
    return os;
}

/**
 *
 * @param item The weapon to compare to.
 * @return True if the weapons are equal, False otherwise.
 */
bool Weapon::isEqual(const Item& item) const {
    auto v = dynamic_cast<const Weapon&>(item);
    return Item::isEqual(v) && v.damageAmount == damageAmount;
}

/**
 * Getter for the price, in gold coins, of the weapon.
 * @return The number of attacks remaining on the weapon.
 */
int Weapon::getPrice() const { return price; }

/**
 * This function generates random stats for the weapon when it is first created.
 */
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

/**
 * Generates a random number between the inputted min and max.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return A random number between the min and max.
 */
int Weapon::randomNum(int min, int max) {
    std::random_device rd;
    std::mt19937 mt{rd()};
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}