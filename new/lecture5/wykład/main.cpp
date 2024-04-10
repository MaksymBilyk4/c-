#include <fmt/core.h>
#include <fmt/ranges.h>
#include <map>
#include <utility>
#include <deque>

struct Point {
    int x;
    int y;

    auto distanceToOrigin() -> double {
        return std::hypot(x, y);    // 1
    }
};

enum class Number {
    One = 4, Two = 8, Four = 12, Five = 16
};

auto format_as(Point p) { return std::pair<int, int>(p.x, p.y); }


enum class Direction {
    North = 4, East = 8, South = 12, West = 16
};

enum class Ordering {
    REQUIRED,
    NOT_REQUIRED
};

template<typename T>
auto equalVectors(std::vector<T> &v1, std::vector<T> &v2, Ordering ordering) -> bool {
    return ordering == Ordering::REQUIRED ? v1 == v2 : std::ranges::is_permutation(v1, v2);
}

auto main() -> int {

    auto m = std::map<std::string, std::string>();

    m["hello"] = "world";
    m["sup"] = "you";
    m["key"] = "value";

    for (auto &entry: m) {
        fmt::println("{} : {}", entry.first, entry.second);
    }

    auto somePair = std::pair<std::string, int>("hello", 5);
    somePair.second = 999;
    auto [p1, p2] = somePair;
//    auto& [p1, p2] = somePair;
    fmt::println("pair: {}, {}.", p1, p2);
    p2 = 3;
    fmt::println("pair: {}, {}.", somePair.first, somePair.second);

    auto deque = std::deque<int>();
    deque.push_front(1);
    deque.push_front(2);
    deque.push_front(3);
    deque.push_front(4);
    deque.pop_back();
    fmt::println("{}", deque);

    auto array = std::array<int, 5>{1, 2, 3, 4, 5};
    std::ranges::reverse(array);
    fmt::println("{}", array);

    auto direction = Direction(5);
    fmt::print("direction value: {}\n", static_cast<int>(direction));

    auto vec1 = std::vector<int>{1, 2, 3, 4};
    auto vec2 = std::vector<int>{4, 3, 1, 2};

    fmt::println("{}", equalVectors(vec1, vec2, Ordering::NOT_REQUIRED));
    fmt::println("{}", equalVectors(vec1, vec2, Ordering::REQUIRED));
    std::ranges::sort(vec2);
    fmt::println("{}", equalVectors(vec1, vec2, Ordering::REQUIRED));

    auto points = std::vector<Point>{ {1, 2}, {0, 0}, {2, 0} };
    std::ranges::sort(points, [](Point left, Point right) {
        return left.distanceToOrigin() < right.distanceToOrigin();
    });
    fmt::println("{}", points);

    auto value = Number::One;
    fmt::println("{}", static_cast<int>(value));
    value = static_cast<Number>(8);
    if (value == Number::Four) {
        fmt::println("{}", static_cast<int>(value));
    }

    return 0;
}