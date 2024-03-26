#include <fstream>
#include <string>
#include "fmt/core.h"

int main() {

    auto file = std::fstream("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/files/data.txt");
    auto word = std::string();

    while (file >> word) {
        fmt::println("{}", word);
    }

    auto file1 = std::fstream("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/files/line.txt");
    auto line = std::string();

    while (std::getline(file1, line)) {
        fmt::println("{}", line);
    }

    return 0;
}
