#include <iostream>
#include <vector>
#include <string>
#include <fmt/core.h>
#include <fstream>
#include <sstream>

template<typename T>
auto displayAnyVector(std::vector<T> &vec) -> void {
    for (auto el: vec)
        std::cout << el << " ";

    std::cout << "\n";
}

namespace pjc {
    template<typename T>
    auto count_if(std::vector<T> &source, auto predicate) -> int {
        auto counter = 0;

        for (auto &element: source) {
            if (predicate(element)) {
                counter += 1;
            }
        }

        return counter;
    }

    auto print_words_in_lines() -> void {
        auto file = std::fstream("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/files/line.txt");

        for (auto line = std::string(); std::getline(file, line);) {
            auto wordCount = 0;
            auto lineStream = std::stringstream(line);

            for (auto word = std::string(); lineStream >> word; wordCount++);
            fmt::println(
                    "Line \"{}\" contains {} words",
                    line, wordCount
            );

        }

    }
}


auto main() -> int {

    auto ints = std::vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 2};
    auto strings = std::vector<std::string>{"hello", "world", "!"};

    displayAnyVector(ints);
    displayAnyVector(strings);

    auto predicate = [](auto el) { return el % 2 == 0; };

    auto count = pjc::count_if(ints, predicate);
    fmt::println("{}", count);

    pjc::print_words_in_lines();

    return 0;

}