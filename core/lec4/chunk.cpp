#include <iostream>
#include <algorithm>
#include <fmt/ranges.h>
#include <set>

namespace pjc {
    template<typename T>
    auto chunk(T &collection, int n) -> std::vector<std::vector<std::ranges::range_value_t<T>>>;
}

auto main() -> int {

    auto v1 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto v2 = std::vector<std::string>{"a", "b", "c", "d", "e", "f"};
    auto v3 = std::set<float>{1.41, 1.61, 1.73, 2.72, 3.14};

    auto v1by3 = pjc::chunk(v1, 3);
    auto v1by2 = pjc::chunk(v1, 2);

    auto v2by5 = pjc::chunk(v2, 5);
    auto v2by1 = pjc::chunk(v2, 1);

    auto v3by2 = pjc::chunk(v3, 2);
    auto v3by3 = pjc::chunk(v3, 3);

    fmt::println("{}", v1by3);
    fmt::println("{}", v1by2);
    fmt::println("{}", v2by5);
    fmt::println("{}", v2by1);
    fmt::println("{}", v3by2);
    fmt::println("{}", v3by3);


    return 0;
}

namespace pjc {
    template<typename T>
    auto chunk(T &collection, int n) -> std::vector<std::vector<std::ranges::range_value_t<T>>> {

        auto collectionMatrix = std::vector<std::vector<std::ranges::range_value_t<T>>>();

        auto cpy = std::vector<std::ranges::range_value_t<T>>();

        auto count = 1;
        auto ptr = collection.begin();

        for (; ptr != collection.end(); ptr++) {
            cpy.push_back(*ptr);
            if (count % n == 0) {
                collectionMatrix.push_back(cpy);
                cpy.clear();
            }
            count++;
        }

        if (!cpy.empty()) collectionMatrix.push_back(cpy);
        cpy.clear();

        return collectionMatrix;
    }
}