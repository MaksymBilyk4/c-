#include <iostream>
#include <vector>
#include <fmt/ranges.h>
#include <algorithm>
#include <fmt/core.h>

namespace longestString {

    auto printLongestString1(std::vector<std::string> &vec) -> void;

    auto printLongestString2(std::vector<std::string> &vec) -> void;

    auto printLongestString3(std::vector<std::string> &vec) -> void;

    auto printLongestString4(std::vector<std::string> &vec) -> void;

}

namespace task {
    auto reduceAdjacentWhitespaces(std::string &str) -> void;
}

auto main() -> int {

//    auto nums = std::vector<int>(10, 0);
//
//    fmt::println("{}", nums);
//
//    for (auto &n:nums) {
//        std::cin >> n;
//    }
//
//    fmt::println("{}", nums);

    auto words = std::vector<std::string>{"hello", "min", "122221212121jkhdsakldhsa", "fdsfds"};
    longestString::printLongestString1(words);
    longestString::printLongestString2(words);
    longestString::printLongestString3(words);
    longestString::printLongestString4(words);

    std::ranges::sort(words, {}, std::ranges::size);
    fmt::println("{}", words);

}

namespace longestString {

    auto printLongestString1(std::vector<std::string> &vec) -> void {

        std::string maxElement = std::ranges::max(vec, {}, std::ranges::size);
        fmt::println("{}", maxElement);

    }

    auto printLongestString2(std::vector<std::string> &vec) -> void {
        auto maxIter = std::ranges::max_element(vec, {}, std::ranges::size);
        fmt::println("{}", *maxIter);
    }


    auto printLongestString3(std::vector<std::string> &vec) -> void {

        auto maxElement = std::ranges::min(
                vec,
                std::ranges::greater(),
                std::ranges::size
        );

        fmt::println("{}", maxElement);

    }

    auto printLongestString4(std::vector<std::string> &vec) -> void {

        auto maxIter = std::ranges::min_element(vec.begin(), vec.end(), std::ranges::greater(), std::ranges::size);

        fmt::println("{}", *maxIter);

    }

}

namespace task {
    auto reduceAdjacentWhitespaces(std::string &str) -> void {

//        std::ranges::transform(
//                str,
//                str.begin(),
//                [](std::string symbol) -> std::string {
//
//                }
//        );

    }
}