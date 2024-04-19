#include "point.hpp"

#include <cmath>
#include "fmt/format.h"
#include <sstream>

auto Point::getX() -> int {
    return x;
}

auto Point::getY() -> int {
    return y;
}

auto Point::distanceToOrigin() -> double {
    return sqrt(x * x + y * y);
}

Point::Point(int x, int y) : x(x), y(y) {}

auto Point::toString() -> std::string {
    auto str = std::stringstream();
    str << "( " << x << "; " << y << " )";
    return str.str();
}

//auto Point::format_as(Point p) -> std::string {
//    return fmt::format("( {}, {} )", p.getX(), p.getY());
//}