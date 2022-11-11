//
// Created by Liam on 10/11/2022.
//

#include "Point.h"

Point::Point() : Point(0, 0) {
}

Point::Point(int x, int y) : x{x}, y{y} {
}

Point& Point::operator=(const Point& rhs) {
    if (this == &rhs)
        return *this;

    x = rhs.x;
    y = rhs.y;
    return *this;
}

bool Point::operator==(const Point& rhs) const {
    return x == rhs.x && y == rhs.y;
}

void Point::setXY(int newX, int newY) {
    x = newX;
    y = newY;
}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
