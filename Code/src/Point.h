//
// Created by Liam on 10/11/2022.
//

#ifndef CODE_POINT_H
#define CODE_POINT_H

#include <iostream>

class Point {
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);
    Point& operator=(const Point& rhs); // Copy assignment
    bool operator==(const Point& rhs) const; // Overloaded == operator

    void setXY(int newX, int newY);

    int getX() const;
    int getY() const;
};


#endif //CODE_POINT_H
