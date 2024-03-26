#include <iostream>
#include <fstream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <ios>
#include <fmt/ostream.h>
#include <algorithm>

namespace util {

    auto remove_lines(std::string &path, std::vector<int> &vecLinesToRemove) -> void;

}

auto main() -> int {

    auto path = std::string();
//    std::cout << "Enter a path to file: ";
//    std::cin >> path;
//
//    auto linesToRemove = std::vector<int>();
//    auto userInput = int();
//
//    while (userInput != -1) {
//        std::cout << "Enter a number: ";
//        std::cin >> userInput;
//        linesToRemove.push_back(userInput);
//    }

    path = "/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/task5/task5.txt";
    auto linesToRemove = std::vector<int>{1, 9, 20, 3, 6};
    util::remove_lines(path, linesToRemove);

}

namespace util {

    auto remove_lines(std::string &path, std::vector<int> &vecLinesToRemove) -> void {

        if (vecLinesToRemove.size() < 2) {
            fmt::println("Provided vector should be minimum of size 2");
            return;
        }

        auto left = vecLinesToRemove[vecLinesToRemove.size() - 2]; // begin of remove range
        auto right = vecLinesToRemove[vecLinesToRemove.size() - 1]; // end of remove range

        auto removeLinesNoConflict = std::vector<int>();

        for (int i = left; i <= right; i++) {
            removeLinesNoConflict.push_back(i);
        }

        if (vecLinesToRemove.size() > 2) {
            removeLinesNoConflict.insert(removeLinesNoConflict.end(), vecLinesToRemove.begin(),
                                         vecLinesToRemove.end() - 2);
        }

        std::ranges::sort(removeLinesNoConflict);
        auto duplicates = std::ranges::unique(removeLinesNoConflict);
        removeLinesNoConflict.erase(duplicates.begin(), duplicates.end()); // line's number
        fmt::println("{}", removeLinesNoConflict);

        // ===========================================================================================================

        auto file = std::fstream(path);
        if (!file.is_open()) {
            fmt::println("Provided path does not exist");
            return;
        }


        auto readLine = std::string();
        auto fileLines = std::vector<std::string>(); // lines from file

        while (getline(file, readLine)) {
            fileLines.push_back(readLine);
        }

        file.close();

        // ===========================================================================================================

        auto fileWrite = std::fstream(path, std::ios::out);

        fmt::println("{}", fileLines);

        auto lineNotToWrite = removeLinesNoConflict.begin();

        for (auto i = 1; i < fileLines.size() + 1; i++) {
            if (i != *lineNotToWrite) {
                fmt::println(fileWrite, "{}", fileLines[i - 1]);
            } else {
                if (*lineNotToWrite != removeLinesNoConflict[removeLinesNoConflict.size() - 1]) lineNotToWrite++;
            }
        }


    }

}