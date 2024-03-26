#include <filesystem>   // std::filesystem
#include "fmt/core.h"
#include "fmt/std.h"

#include "fmt/core.h"

auto main() -> int {

    namespace fs = std::filesystem;

//    auto path = fs::path("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/files/input.txt");
    auto path = fs::path(".");

    for (auto& entry : fs::directory_iterator(path)) {
        fmt::println("{}", entry.path().filename());
    }

    fmt::println("{}", fs::exists(path));
}