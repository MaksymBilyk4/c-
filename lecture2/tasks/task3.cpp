#include <iostream>
#include <fmt/ranges.h>
#include <vector>
#include <set>

auto iterateOver(std::vector<int> &, int) -> void;

auto iterateOver(std::set<int> &, int) -> void;

auto main() -> int {

    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iterateOver(v1, 3);
    std::set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iterateOver(s1, 3);

    return 0;
}

auto iterateOver(std::vector<int> &vec, int n) -> void {

    if (n < 0) {
        std::cout << "'n' should equals or be bigger than 0'";
        return;
    }

    auto iterator = vec.begin();
    while (iterator < vec.end()) {
        std::cout << *iterator << " ";
        iterator += n;
    }
    std::cout << "\n";

}

auto iterateOver(std::set<int> &set, int n) -> void {

    if (n < 0) {
        std::cout << "'n' should equals or be bigger than 0'";
        return;
    }

    for (auto iterator = set.begin(); iterator != set.end();) {
        std::cout << *iterator << " ";
        std::advance(iterator, n);
        if (std::distance(iterator, set.end()) < n - 1) break; // If fewer than n-1 elements remain, stop the loop
    }
    std::cout << "\n";

}