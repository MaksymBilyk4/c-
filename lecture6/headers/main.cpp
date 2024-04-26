#include "fmt/core.h"
#include "fmt/ranges.h"
#include "utils/math/maths.hpp"
#include "utils/printer/printer.hpp"
#include "entity/point/point.hpp"
#include <functional>

#include <set>
#include <map>

template<typename T>
auto merged(std::set<T> &s1, std::set<T> &s2) -> std::vector<T> {
    auto combined = std::vector<T>(s1.begin(), s1.end());
    for (auto &el: s2) combined.push_back(el);
    return combined;
}

template<typename T>
auto rarest(const std::vector<T> &data) -> T {
    auto frequencies = std::map<T, int>();
    for (const auto &el: data)
        frequencies[el] += 1;

    // Находим элемент с минимальной частотой
    auto min_it = std::ranges::min_element(frequencies.begin(), frequencies.end(), [](auto &a, auto &b) -> bool {
        return a.second < b.second;
    });

    return min_it->first;
}

template<typename E>
auto filtered(const std::vector<E> &vec, auto predicate) -> std::vector<E> {
    std::vector<E> filtered;
    for (const auto &el: vec) {
        if (predicate(el)) {
            filtered.push_back(el);
        }
    }

    return filtered;
}

template<typename T>
auto something(T &collection) -> std::ranges::range_value_t<T> {

    auto sum = std::ranges::range_value_t<T>();


    for (auto iter = collection.begin(); iter != collection.end(); iter++)
        sum += *iter;

    return sum;
}

template<typename T>
auto contains(std::vector<T> &vec, T el) -> bool {
    auto iter_el = std::ranges::find_if(vec.begin(), vec.end(), [el](auto vec_el) { return el == vec_el; });
    return iter_el != vec.end();
}

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

    Point point = Point(1, 2);
    fmt::println("{}", point.toString());

    auto s1 = std::set<int>{1, 2, 3, 4, 5};
    auto s2 = std::set<int>{6, 7, 8, 9, 10};
    fmt::println("{}", merged(s1, s2));

//    auto map = std::map<std::string, int>();
//    map["a"] = 1;
//    map["b"] = 2;
//    map["c"] = 4;
//    map["d"] = 3;
//
//    map.insert(std::make_pair("hello", 121212121));
//    for (auto &el : map) {
//        fmt::println("{} - {}", el.first, el.second);
//    }

    auto test = std::vector<int>{1, 2, 2, 2, 1, 4, 4, 4, 4, 2, 10, 10, 10, 5};
//
//    auto d = std::ranges::find_if(data, [](auto &el) -> bool {
//        if (el % 3 == 0) return el;
//    });
//
//    fmt::println("{}", *d);

    auto t = rarest(test);
    fmt::println("{}", t);

    auto pred = [](auto el) -> bool { return el % 2 == 0; };
    auto res = filtered(test, pred);
    fmt::println("{}", res);

    auto vector = std::vector<std::string>{"hello", " ", " world", " ", "fdhfgdsjkfdsgh"};
    auto set = std::set<int>{1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 5};
    auto result = something(vector);
    fmt::println("{}", result);
    fmt::println("{}", something(set));

    auto sss = std::vector<int>{1, 2, 3, 4, 5};
    fmt::println("{}", contains(sss, 10));
    return 0;
}