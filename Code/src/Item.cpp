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

std::ostream& Item::write(std::ostream& os) const {
    os << std::boolalpha;

    os << "Name: " << name <<
          "\nPosition: " << position <<
          "\nIs Used: " << used;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return item.write(os);
}

bool Item::isEqual(const Item& item) const {
    return name == item.name && position == item.position;
}

bool operator==(const Item& lhs, const Item& rhs) {
    return typeid(lhs) == typeid(rhs) && lhs.isEqual(rhs);
}



std::string Item::getName() const { return name; }
Point Item::getPosition() const { return position; }
bool Item::isUsed() const { return used; }
