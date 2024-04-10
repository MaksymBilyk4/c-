#include <fmt/format.h>
#include <fmt/core.h>
#include <math.h>
#include <iostream>

struct Point {

    int x;
    int y;

    Point(int initX, int initY) : x(initX), y(initY) {}

    auto calculateDistance(Point destination) -> double {
        return std::hypot(x - destination.x, y - destination.y);
    }

    auto changeCoordinates(Point point) -> void {
        x = point.x;
        y = point.y;
    }

};
auto format_as(Point p) { return fmt::format("[ {}, {} ]", p.x, p.y); }

struct Rectangle {

    Point bottomLeft;

    Point bottomRight;

    Point topLeft;

    Point topRight;

    Rectangle(Point bl, Point br, Point tl, Point tr) : bottomLeft(bl), bottomRight(br), topLeft(tl), topRight(tr) {}

    auto print() -> void {
        fmt::println("{} {} {} {}", bottomLeft, topRight, topLeft, topRight);
    }

};

auto main() -> int {

    auto point = Point(1, 1);
    fmt::println("Here is a point: {}", point);
    fmt::println("");

    Point destination = Point(4, 5);
    double distance = point.calculateDistance(destination);
    fmt::println("Distance between {} and {} ---> {}", point, destination, distance);

    int x = 99, y = 100;
//    fmt::print("Update x: ");
//    std::cin >> x;
//    fmt::print("Update y: ");
//    std::cin >> y;
    point.changeCoordinates({x, y});
    fmt::println("");
    fmt::println("Point after coordinates change: {}", point);

    fmt::println("");
    auto rectangle = Rectangle({1, 1}, {2, 1}, {1, 2}, {2, 2});
    rectangle.print();

    return 0;
}