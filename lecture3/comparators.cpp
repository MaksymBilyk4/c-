#include <algorithm>
#include <vector>

#include <fmt/ranges.h>

// A comparator is a tool that allows you to control the sorting rule of elements in algorithms.

namespace sorting {

    auto sortAscending(std::vector<int> &vec) -> void;

    auto sortDescending(std::vector<int> &vec) -> void;

    auto sortAlphabeticAscending(std::vector<std::string> &vec) -> void;

    auto sortAlphabeticDescending(std::vector<std::string> &vec) -> void;

    auto sortWordSizeAscending(std::vector<std::string> &vec) -> void;

    auto sortWordSizeDescending(std::vector<std::string> &vec) -> void;

}

// std::ranges::sort(container, COMPARATOR, COMPARATOR_PERSPECTIVE);

auto main() -> int {

    auto vec = std::vector<int>{3, 5, 1, 6, 7, 10, -4};
    auto words = std::vector<std::string>{
            "those", "are", "extremely",
            "random", "words", "in",
            "this", "particular", "example"
    };

//    fmt::println("Before sort: {}", vec);
//
//    std::ranges::sort(vec, std::ranges::less());
//    std::ranges::sort(vec, std::ranges::greater());
//    fmt::println("After sort: {}", vec);
    fmt::println("{}", words);
    sorting::sortWordSizeAscending(words);
    fmt::println("{}", words);
    sorting::sortWordSizeDescending(words);
    fmt::println("{}", words);

    return 0;
}

namespace sorting {

    auto sortAscending(std::vector<int> &vec) -> void {
        std::ranges::sort(vec, std::ranges::less());
    }

    auto sortDescending(std::vector<int> &vec) -> void {
        std::ranges::sort(vec, std::ranges::greater());
    }

    auto sortAlphabeticAscending(std::vector<std::string> &vec) -> void {
        std::ranges::sort(vec, std::ranges::less());
    }

    auto sortAlphabeticDescending(std::vector<std::string> &vec) -> void {
        std::ranges::sort(vec, std::ranges::greater());
    }

    auto sortWordSizeAscending(std::vector<std::string> &vec) -> void {
        std::ranges::sort(vec, std::ranges::less(), std::ranges::size);
    }


    auto sortWordSizeDescending(std::vector<std::string> &vec) -> void {
        std::ranges::sort(vec, std::ranges::greater(), std::ranges::size);
    }

}