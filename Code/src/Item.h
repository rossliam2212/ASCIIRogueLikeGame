//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_ITEM_H
#define CODE_ITEM_H

#include <string>
#include "Point.h"

class Item {
protected:
    std::string name;
    Point position;

public:
    Item(const std::string& name, const Point& position);
    Item(const std::string&& name, const Point& position);
    ~Item() = default;

    std::string getName() const;
    Point getPosition() const;
};


#endif //CODE_ITEM_H
