//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_ITEM_H
#define CODE_ITEM_H

#include <string>
#include "Point.h"

class Item {
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend bool operator==(const Item& lhs, const Item& rhs);

protected:
    std::string name;
    Point position;
    bool used;

public:
    Item(const std::string& name, const Point& position);
    Item(const std::string&& name, const Point& position);
    ~Item() = default;

    virtual std::ostream& write(std::ostream& os) const;
    virtual bool isEqual(const Item& item) const;

    std::string getName() const;
    Point getPosition() const;
    bool isUsed() const;
};


#endif //CODE_ITEM_H
