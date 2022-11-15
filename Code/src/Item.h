//
// Created by Liam on 11/11/2022.
//

#ifndef CODE_ITEM_H
#define CODE_ITEM_H

#include <string>
#include "Point.h"

class Item {
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend bool operator==(const Item& lhs, const Item& rhs); // https://stackoverflow.com/questions/1691007/whats-the-right-way-to-overload-operator-for-a-class-hierarchy

protected:
    std::string name;
    Point position;
    bool used;

public:
    Item(const std::string& name, const Point& position);
    Item(const std::string&& name, const Point& position);
    virtual ~Item() = default;

    Item& operator=(const Item& rhs);
    virtual std::ostream& write(std::ostream& os) const; // https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
    virtual bool isEqual(const Item& item) const;

    std::string getName() const;
    Point getPosition() const;
    bool isUsed() const;
    void use();
};


#endif //CODE_ITEM_H
