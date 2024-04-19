#pragma once

#include <iostream>

struct Point {
private:
    int x;
    int y;


public:
    Point(int x, int y);

    auto distanceToOrigin() -> double;

    auto toString() -> std::string ;
//    auto format_as(Point p) -> std::string;

    auto getX() -> int;

    auto getY() -> int;

};

