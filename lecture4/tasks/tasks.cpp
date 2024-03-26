#include <iostream>
#include <fstream>
#include <filesystem>
#include "fmt/core.h"
#include "fmt/std.h"

namespace task2 {

    auto calculate_files_in_directory(std::string &path) -> int;

    auto calculate_files_and_numbers(std::string &path) -> int;

    auto find_palindromes_in_file(std::string &path) -> int;

}


auto main() -> int {

    using namespace task2;

    fmt::println("Input an absolute path to folder: ");
    auto path = std::string();
    std::cin >> path;

//    auto data = calculate_files_in_directory(path);
//    auto data2 = calculate_files_and_numbers(path);
    auto data2 = find_palindromes_in_file(path);

    return 0;
}

namespace task2 {

    auto calculate_files_in_directory(std::string &path) -> int {
        namespace fs = std::filesystem;

        auto absolutePath = fs::path(path);

        auto filesCount = 0;

        if (!fs::exists(absolutePath)) {
            fmt::println("Provided path does not exist");
            return filesCount;
        }

        for (auto &entry: fs::directory_iterator(absolutePath)) {
            if (fs::is_regular_file(entry)) {
                filesCount++;
                fmt::println("{} File found: {}", filesCount, entry.path().filename().string());
            }
        }

        return filesCount;

    }

    auto calculate_files_and_numbers(std::string &path) -> int {
        namespace fs = std::filesystem;

        auto absolutePath = fs::path(path);

        if (!fs::exists(absolutePath)) {
            fmt::println("Provided path does not exist");
            return 0;
        }

        auto countNumbers = [](auto &filepath) -> int {
            auto file = std::fstream(filepath);

            auto character = char();
            auto sum = int();

            while (file >> character) {
                if (character >= '0' && character <= '9') {
                    sum += (int) (character - '0');
                }
            }

            return sum;
        };

        auto fileCount = 0;
        for (auto &entry: fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry)) {
                fmt::println("{} - sum: {}", entry.path().filename().string(), countNumbers(entry.path()));
                fileCount++;
            }
        }

        return fileCount;

    }

    auto find_palindromes_in_file(std::string &path) -> int {

        namespace fs = std::filesystem;

        auto absolutePath = fs::path(path);

        if (!fs::exists(absolutePath)) {
            fmt::println("Provided path does not exist");
            return 0;
        }

        auto palindromeCount = 0;

        auto isPalindrome = [](std::string word) -> bool {
            bool flag = true;
            for(int i = 0; i < word.size() / 2; i++) {
                if (word[i] != word[word.size() - 1 - i]) {
                    flag = false;
                    break;
                }
            }

            return flag;
        };

        for (auto &entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry)) {

                auto file = std::fstream(entry.path());
                auto wordInFile = std::string();

                while (file >> wordInFile) {
                    if (isPalindrome(wordInFile)) {
                        palindromeCount++;
                        fmt::println("File: {}. Found palindrome: {}", entry.path().string(), wordInFile);
                    }
                }
            }
        }

        fmt::println("Total palindrome count: {}", palindromeCount);

        return palindromeCount;
    }

}