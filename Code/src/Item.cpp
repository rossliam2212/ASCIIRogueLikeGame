//
// Created by Liam on 11/11/2022.
//

#include "Item.h"

Item::Item(const std::string& name, const Point& position)
    : name{name},
      position{position} {
}

Item::Item(const std::string&& name, const Point& position)
        : name{name},
          position{position} {
}

std::string Item::getName() const { return name; }
Point Item::getPosition() const { return position; }