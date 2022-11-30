//
// Created by Liam on 10/11/2022.
//

#include "Point.h"

Point::Point() : Point(0, 0) { }

Point::Point(int x, int y) : x{x}, y{y} { }

/**
 * Overloaded = operator.
 * @param rhs The object on the right hand side to assign to the left.
 * @return Thew newly assigned object.
 */
Point& Point::operator=(const Point& rhs) {
    if (this != &rhs) {
        x = rhs.x;
        y = rhs.y;
    }
    return *this;
}

/**
 * Overloaded == operator.
 * @param rhs The object on the right hand to compare to the left.
 * @return True if the objects are equal, False otherwise.
 */
bool Point::operator==(const Point& rhs) const {
    return x == rhs.x && y == rhs.y;
}

/**
 * Sets the x and y values to new values.
 * @param newX The new value for x.
 * @param newY The new value for y.
 */
void Point::setXY(int newX, int newY) {
    x = newX;
    y = newY;
}

// Getters & Setters
int Point::getX() const { return x; }
int Point::getY() const { return y; }

// Overloaded << operator - friend function
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
