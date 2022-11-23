//
// Created by Liam on 11/11/2022.
//

#include "Item.h"

Item::Item(const std::string& name, const Point& position)
    : name{name},
      position{position},
      used{false} {
}

Item::Item(const std::string&& name, const Point& position)
    : name{name},
      position{position},
      used{false} {
}

/**
 * Overloaded = operator.
 * @param rhs The object on the right hand side to assign to the left hand side.
 * @return A reference to the new object.
 */
Item& Item::operator=(const Item& rhs) {
    if (this != &rhs) {
        name = rhs.name;
        position = rhs.position;
        used = rhs.used;
    }
    return *this;
}

/**
 *
 * @param os The output stream
 * @return A reference to the output stream
 */
std::ostream& Item::write(std::ostream& os) const {
    os << std::boolalpha; // So bool values show as true/false

    os << "Name: " << name <<
          "\nPosition: " << position <<
          "\nIs Used: " << used;
    return os;
}

/**
 * Overloaded << operator.
 * @param os The output stream.
 * @param item The item to output.
 * @return A reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Item& item) {
    return item.write(os);
}

/**
 * Checks if the items are equal to each other.
 * @param item The item to compare to.
 * @return True if the items are equal, False otherwise.
 */
bool Item::isEqual(const Item& item) const {
    return name == item.name && position == item.position;
}

/**
 * Overloaded == operator (friend function).
 * Calls isEqual() to compare the members.
 * @param lhs The object on the left hand side.
 * @param rhs The object on the right hand side.
 * @return True if the objects are equal, False otherwise.
 */
bool operator==(const Item& lhs, const Item& rhs) {
    return typeid(lhs) == typeid(rhs) && lhs.isEqual(rhs);
}

// Getters & Setters
std::string Item::getName() const { return name; }
Point Item::getPosition() const { return position; }
bool Item::isUsed() const { return used; }
void Item::use() { used = true; }
