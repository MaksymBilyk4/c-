#include <iostream>
#include <fstream>
#include <filesystem>
#include "fmt/core.h"
#include "fmt/std.h"
#include <cmath>
#include <sstream>


namespace analysis {

    auto calculate_digits_in_file(std::string &path) -> int;

    auto calculate_numbers_in_file(std::string &path) -> int;

    auto find_armstrong_numbers_in_file(std::string &path) -> void;

}

auto main() -> int {


    auto path = std::string();
    std::cin >> path;

//    auto res = analysis::calculate_digits_in_file(path);
//    fmt::println("Numbers in a file: {}", res);
//    std::cout << "\n";
//    auto res2 = analysis::calculate_numbers_in_file(path);
//    fmt::println("Total numbers: {}", res2);

    analysis::find_armstrong_numbers_in_file(path);

    return 0;
}

namespace analysis {

    auto calculate_digits_in_file(std::string &path) -> int {

        namespace fs = std::filesystem;

        if (!fs::exists(path)) {
            fmt::println("Provided path does not exist");
            return 0;
        }

        auto count = int();

        auto file = std::fstream(path);
        auto data = std::string();

        auto digitCounter = [](std::string &str) -> int {
            auto digits = 0;
            for (int i = 0; i < str.size(); i++)
                if (str[i] >= '0' && str[i] <= '9')
                    digits++;

            return digits;
        };

        while (file >> data) {
            count += digitCounter(data);
        }

        return count;

    }

    auto calculate_numbers_in_file(std::string &path) -> int {
        namespace fs = std::filesystem;

        if (!fs::exists(path)) {
            fmt::println("Provided path does not exist");
            return 0;
        }

        auto file = std::fstream(path);

        auto count = 0;

        auto isNumber = [](std::string &str) -> int {
            auto flag = 1;

            for (char ch: str) {
                if (ch < '0' || ch > '9') {
                    flag = 0;
                    break;
                }
            }

            return flag;
        };

        auto currentWord = std::string();

        while (file >> currentWord) {
            if (isNumber(currentWord)) {
                count++;
                fmt::println("Found number: {}", currentWord);
            }
        }

        return count;
    }

    auto find_armstrong_numbers_in_file(std::string &path) -> void {

        namespace fs = std::filesystem;

        if (!fs::exists(path)) {
            fmt::println("Provided path does not exist");
            return;
        }

        auto isNumber = [](std::string &str) -> int {
            auto flag = 1;

            for (char ch: str) {
                if (ch < '0' || ch > '9') {
                    flag = 0;
                    break;
                }
            }

            return flag;
        };

        auto isArmstrong = [](std::string &number) -> bool {
            auto sum = int();

            for (int i = 0; i < number.size(); i++)
                sum += (int) std::pow((double) (number[i] - '0'), number.size());


            return std::to_string(sum) == number;
        };

        auto file = std::fstream(path);
        auto word = std::string();

        while (file >> word) {
            if (isNumber(word)) {
                if (isArmstrong(word)) {
                    fmt::println("Found Armstrong's number: {}", word);
                }
            }
        }

    }

}