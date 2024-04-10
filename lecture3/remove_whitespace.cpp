#include <iostream>

auto reduceAdjacentWhitespaces(std::string text) -> std::string {
    std::ranges::replace_if(text, [](char c) { return c == '\t' or c == '\n'; }, ' ');
    auto excessiveWhitespaces = std::ranges::unique(text, [](char left, char right) {
        return left == ' ' and right == ' ';
    });
    text.erase(excessiveWhitespaces.begin(), excessiveWhitespaces.end());
    return text;
}

auto main () -> int {
    return 0;
}