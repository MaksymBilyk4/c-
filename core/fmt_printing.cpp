#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iostream>

auto displayMultipleTime(std::string, int) -> void;

auto displayReservedCharacters(std::string) -> void;

auto displayVector(std::vector<int> &, std::string separator = ", ", char prefix = '[', char suffix = ']') -> void;

auto main() -> int {

    auto vec = std::vector<int>{1, 7, 1, 3, 7};

    displayMultipleTime("hello", 3);
    displayReservedCharacters("The simplest C++ program is: \"auto main() -> int { }\".");
    displayVector(vec);
    displayVector(vec, " - ", '$', '$');

    fmt::println("{0}{1}{0}", '?', "I'm enclosed in question marks");

    auto val = 3.148194;
    fmt::println("{:.2f}", val);

    auto x = 74;
    fmt::println("Binary: {:b}. Decimal: {}. Hexadecimal: {:x}", x, x, x);

    // ===================================
//    std::string text = "cat";
//    std::string result = fmt::format("{0}{1:6}{0}{2:5}{0}", text, "#", "#");
//    fmt::println("{}\n", result);


    return 0;
};

auto displayMultipleTime(std::string value, int time) -> void {

    using namespace fmt;

    for (int i = 0; i < time; i++)
        print("({}) ", value);

    std::cout << "\n";
}

auto displayReservedCharacters(std::string value) -> void {
    fmt::print("{}", value);
    std::cout << "\n";
}

auto displayVector(std::vector<int> &vec, std::string separator, char prefix, char suffix) -> void {
    fmt::println("{} {} {}", prefix, fmt::join(vec, separator), suffix);
}