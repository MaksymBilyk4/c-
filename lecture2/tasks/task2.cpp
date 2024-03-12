#include <iostream>
#include <fmt/ranges.h>

auto dotProduct(std::vector<int> &, std::vector<int> &) -> int;

auto main() -> int {

    std::vector v1 = {1,2,3};
    std::vector v2 = {1,2,3};
    int d = dotProduct(v1, v2);
    fmt::println("{}", d);

    return 0;
}

auto dotProduct(std::vector<int> &v1, std::vector<int> &v2) -> int {

    auto res = int(-1);
    if (v1.size() != v2.size()) return res;

    for (int i = 0; i < v1.size(); i++) {
        res += v1[i] * v2[i];
    }

    return res;
}