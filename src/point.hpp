#pragma once
#include <cmath>



class Point {
public:
    Point(): x{}, y{} {}
    Point(const Point& p): x{p.x}, y{p.y} {}
    Point(int16_t x, int16_t y): x{x}, y{y} {}

    double distance(const Point& p) const {
        return sqrt((p.x - x)*(p.x - x) +
                    (p.y - y)*(p.y - y));
    }

    bool adjast(const Point& p) const {
        if((p.x - x == 1) or
           (p.y - y == 1)) {
            return true;
        }
        return false;
    }

    int16_t x, y;
};
