#include <algorithm>
#include <vector>

#include <fmt/ranges.h>
#include <fmt/core.h>

// The std::ranges::advance() algorithm moves the iterator passed as the first argument by the number of places specified in the second argument,
// but ensures that this advancement does not go beyond the third argument.
// Effectively, this is a safer alternative for scenarios where we are unsure whether the advancement would exceed the end of the range.
// You can’t define other functions inside a function. But you can declare and define variables. A lambda is an object that can behave like a function
auto main() -> int {

    using namespace std;

//    auto vec = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//    auto predicator = [](int el) -> bool { return el % 2 == 0; };
//
//    auto res = ranges::find_if(vec, predicator);
//
//    if (res != vec.end()) {
//        fmt::println("{}", *res);
//    }


    auto words = vector<string>{"hello", "world", "lambda", "comparator", "transform"};
    auto transformed = vector<string>(words.size(), "");
    auto sizable = vector<int>(words.size(), 0);
    auto reversed = vector<string>(words.size(), "");

    ranges::transform(words, transformed.begin(), [](std::string word) -> string {
        auto diff = 'a' - 'A';
        word.front() -= diff;
        return word;
    });

    ranges::transform(words, sizable.begin(), [](std::string word) -> int {
        return word.size();
    });

    ranges::transform(words, reversed.begin(), [](std::string word) -> std::string {
        std::ranges::reverse(word.begin(), word.end());
        return word;
    });

//    fmt::println("{}", words);
//    fmt::println("{}", transformed);
//    fmt::println("{}", reversed);

    auto vec1 = std::vector<int>{1, 20, 30};
    fmt::println("{}", vec1);
    auto maxVal = std::ranges::max(vec1.begin(), vec1.end());
    fmt::println("max -> {}", *maxVal);
    *maxVal = 999;
    fmt::println("{}", vec1);


    return 0;
}