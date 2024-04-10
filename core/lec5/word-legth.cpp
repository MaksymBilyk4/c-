#include <fmt/ranges.h>
#include <fmt/core.h>
#include <map>
#include <set>
#include <iostream>

auto main() -> int {

    auto userWord = std::string();

    auto groupedWords = std::map<int, std::set<std::string>>();

    while (true) {
        fmt::print("Type down some word: ");
        std::cin >> userWord;
        if (userWord == "stop") break;
        groupedWords[userWord.size()].insert(userWord);
    }

    for (auto &entry: groupedWords)
        fmt::println("{}", entry.second);

    return 0;
}