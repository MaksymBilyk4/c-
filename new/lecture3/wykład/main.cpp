#include <fmt/core.h>
#include <fmt/ranges.h>
#include <vector>
#include <string>

auto test(int a) -> void;

auto test(double a) -> int;

namespace prep {
    auto bothContainsMax(std::vector<int> &) -> bool;
}

auto main() -> int {

//    auto vec = std::vector<int>{3, 1, 8, 5, 10};
//
//    auto data = vec.front() = 10;
//    fmt::println("{}, {}", data, vec[0]);

//    auto vec = std::vector<int>{1, 2, 3, 3, 2, 1};
//    std::ranges::sort(vec.begin(), vec.begin() + vec.size() / 2);
//    std::ranges::sort(vec.begin() + vec.size() / 2, vec.end());
//    fmt::println("{}", std::ranges::equal(vec.begin(), vec.begin() + vec.size() / 2, vec.begin() + vec.size() / 2,
//                                          vec.end()));

    auto vector = std::vector<int>{1, 2, 3, 0, 10, 1, 6, 8, 0, 2, 0, 9, 9, 1, 4, 5, 6};

    auto data = std::vector<int>{9, 1, 5, 9, 10, 4, 5};
    auto strings = std::vector<std::string>{"hello", "world", "there", "and"};
//    std::ranges::sort(data, [](int left, int right) -> bool { return right < left; });
//    std::ranges::sort(strings, [](std::string left, std::string right) -> bool {
//        if (left.size() < right.size()) {
//            return true;
//        } else {
//            return right < left;
//        }
//    });
//    fmt::println("{}", data);
//    fmt::println("{}", strings);
//    strings.erase(std::ranges::min_element(strings, {}, std::ranges::size));
//    fmt::println("{}", strings);
//    data.erase(data.begin());
//    fmt::println("{}", data);
//
//    auto something = std::ranges::find_if(strings, [](std::string el) -> bool { return el.size() == 5; });
//    fmt::println("{}", *something);

//    fmt::println("{}", prep::bothContainsMax(vector));

//    auto is_even = [](int number) -> bool { return number % 2 == 0; };
//    is_even(5);
    auto stringsSize = std::vector<int>(strings.size());

    std::ranges::transform(strings, stringsSize.begin(), [](std::string& el) -> int{
        return el.size();
    });

    fmt::println("{}", stringsSize);



    return 0;
}

namespace prep {

    auto bothContainsMax(std::vector<int> &vec) -> bool {
        if (vec.size() < 2) return false;

        auto max = std::ranges::max(vec);
        fmt::println("Max value: {}. Vector: {}", max, vec);

        auto mid = vec.size() / 2;

        auto firstHalfIter = std::ranges::find(vec.begin(), vec.begin() + mid, max);

        if (*firstHalfIter != max) {
            return false;
        }

        auto secondHalfIter = std::ranges::find(vec.begin() + mid, vec.end(), max);
        if (*secondHalfIter != max) {
            return false;
        }

        return true;
    }

}