#include "fmt/core.h"

auto printString(std::string& str) -> void {
    fmt::println("{}", str);
}

auto printInteger(int n) -> void {
    fmt::println("{}", n);
}

auto printDouble(double d) -> void {
    fmt::println("{}", d);
}