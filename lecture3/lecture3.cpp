#include <iostream>
#include <vector>
#include <algorithm>

#include <fmt/ranges.h>

// std::ranges::find(container, searchValue)
// std::ranges::find(startIter, endIter, searchValue)
// returns iterator pointing to searchValue or endIter

// std::ranges::max(container) - returns COPY of found max value
// std::ranges::max_element(container) - returns iterator to max element
// std::ranges::min(container) - returns COPY of found min value
// std::ranges::min_element(container) - returns iterator to max element

// std::ranges::swap()
// std::ranges::swap_iter() -> better to working with this one

namespace test {

    auto displayMinMax(std::vector<int> &vec) -> void;
    auto swapMinMax(std::vector<int> &vec) -> void;

}

auto main() -> int {

    using namespace std;

    auto vec = vector<int>{0, 12, 3, 0, 5, 4, 100, 99, 2, 0, 1, 2, 32, 1, 43, 53, -20, 222};

//    for (auto i = 0; i < vec.size(); i++) {
//        cout << "#" << i + 1 << " Enter a number: ";
//        cin >> vec[i];
//    }

    fmt::println("{}", vec);

    auto zeroCount = 0;
    for (auto start = vec.begin(); start != vec.end(); start += 3) {

        auto end = start + 3;

        auto zeroIter = ranges::find(start, end, 0);

        if (zeroIter != end) zeroCount++;

    }

    fmt::println("Zeros amount (in 3 sub ranges) -> {}", zeroCount);

    test::displayMinMax(vec);
    test::swapMinMax(vec);


    return 0;
}

namespace test {

    auto displayMinMax(std::vector<int> &vec) -> void {

        auto min = std::ranges::min(vec);
        auto max = std::ranges::max(vec);

        auto minIter = std::ranges::min_element(vec);
        auto maxIter = std::ranges::max_element(vec);

        fmt::println("Min element: {}\nMax element: {}", min, max);
        fmt::println("Min element (iter): {}\nMax element(iter): {}", *minIter, *maxIter);


    }

    auto swapMinMax(std::vector<int> &vec) -> void {

        auto maxIter = std::ranges::max_element(vec);
        auto minIter = std::ranges::min_element(vec);

        fmt::println("before swap: {}", vec);

//        fmt::println("Min: {} Max: {}", *minIter, *maxIter);
//        std::ranges::swap(minIter, maxIter);
//        fmt::println("Min: {} Max: {}", *minIter, *maxIter);

        std::ranges::iter_swap(minIter, maxIter);

        fmt::println("after swap: {}", vec);

    }

}