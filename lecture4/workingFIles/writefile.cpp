#include <iostream>
#include "fmt/core.h"
#include <fstream>
#include <vector>

#include "fmt/ostream.h"    // fmt::print() for std::fstream
#include "fmt/ranges.h"

auto main() -> int {

//    auto file = std::fstream("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/fileswrite.txt", std::ios::out | std::ios::trunc); // заменить
    auto file = std::fstream("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/files/write.txt", std::ios::out | std::ios::app); // добавить в конец

    auto vec = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
    fmt::println(file, "{}", vec);

    return 0;
}