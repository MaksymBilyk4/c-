#include <iostream>
#include <fstream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/ostream.h>
#include <ios>

auto replace(std::string &filePath, std::string &replaceStr) -> void;

namespace utils {

    auto replace_number_if(std::vector<std::string> &vec, std::string &word, auto &predicate) -> void;

    auto split(std::string &str) -> std::vector<std::string>;

}


auto main() -> int {

    auto path = std::string();
    auto str = std::string();
    std::cin >> path;
    str = "bla";
    replace(path, str);

    return 0;
}

auto replace(std::string &filePath, std::string &replaceStr) -> void {

    auto file = std::fstream(filePath);

    if (!file.is_open()) {
        fmt::println("Provided path does not exist");
        return;
    }


    auto word = std::string();
    auto wordMatrix = std::vector<std::vector<std::string>>();

    auto isNumber = [](std::string &word) -> bool {
        auto flag = true;
        for (auto ch: word) {
            if (!(ch >= '0' && ch <= '9')) {
                flag = false;
                break;
            }
        }

        return flag;
    };

    for (auto i = 0; getline(file, word); ++i) {
        wordMatrix.push_back(utils::split(word));
        utils::replace_number_if(wordMatrix[i], replaceStr, isNumber);
    }

    file.close();

    file = std::fstream(filePath, std::ios::out);

    for (auto &vec: wordMatrix) {
        fmt::println(file, "{}", fmt::join(vec, ""));
    }
}

namespace utils {

    auto replace_number_if(std::vector<std::string> &vec, std::string &word, auto &predicate) -> void {
        for (auto &w: vec) {
            if (predicate(w)) {
                w = word;
            }
        }
    }

    auto split(std::string &str) -> std::vector<std::string> {

        auto splitted = std::vector<std::string>();

        auto startPtr = str.begin();
        auto endPtr = str.begin();
        auto isSpace = str.starts_with(' ');

        for (; endPtr != str.end(); ++endPtr) {
            if (!isSpace && *endPtr == ' ') {
                isSpace = true;
                splitted.push_back(std::string(startPtr, endPtr));
                startPtr = endPtr;
            }

            if (isSpace && *endPtr != ' ') {
                isSpace = false;
                splitted.push_back(std::string(startPtr, endPtr));
                startPtr = endPtr;
            }
        }

        splitted.push_back(std::string(startPtr, str.end()));

        return splitted;
    }

}
