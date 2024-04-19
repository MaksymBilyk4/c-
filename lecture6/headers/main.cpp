#include "fmt/core.h"
#include "utils/math/maths.hpp"
#include "utils/printer/printer.hpp"
#include "entity/point/point.hpp"

auto main() -> int {

    fmt::println("hello world");

    fmt::println("isEven(3) -> {}", isEven(3));
    fmt::println("isEven(2) -> {}", isEven(2));

    fmt::println("{}", plus(1, 2));
    fmt::println("{}", minus(1, 2));
    fmt::println("{}", square(10));

    auto s = std::string();
    s = "hello";
    printString(s);
    printInteger(square(100));
    printDouble(10.28);

    Point point = Point(1,2);
    fmt::println("{}", point.toString());


    return 0;
}