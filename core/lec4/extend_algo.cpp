#include <set>
#include <vector>
#include <fmt/ranges.h>
#include <fmt/core.h>
#include <utility>


namespace pjc::ranges {

    template<typename T>
    auto partition(T &collection,
                   auto predicate) -> std::pair<std::vector<std::ranges::range_value_t<T>>, std::vector<std::ranges::range_value_t<T>>>;

    template<typename T>
    auto drop(T &collection, int n) -> std::vector<std::ranges::range_value_t<T>>;

    template<typename T>
    auto dropLast(T &collection, int n) -> std::vector<std::ranges::range_value_t<T>>;

    template<typename T>
    auto flatten(T &collection) -> std::vector<std::ranges::range_value_t<std::ranges::range_value_t<T>>>;


}


auto main() -> int {

    auto testSet = std::set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto testVec = std::set<int>{2, 4, 6, 8, 10, 12, 14};

    auto droppedSet = pjc::ranges::drop(testSet, 5);
    auto droppedVec = pjc::ranges::drop(testVec, 3);

    auto droppedSetLast = pjc::ranges::dropLast(testSet, 5);
    auto droppedVecLast = pjc::ranges::dropLast(testVec, 3);

    fmt::println("{}", testSet);
    fmt::println("{}", droppedSet);
    fmt::println("\n");
    fmt::println("{}", testVec);
    fmt::println("{}", droppedVec);
    fmt::println("\n");
    fmt::println("{}", testSet);
    fmt::println("{}", droppedSetLast);
    fmt::println("\n");
    fmt::println("{}", testVec);
    fmt::println("{}", droppedVecLast);

    auto matrix = std::vector<std::set<int>>{
            {10},
            {1, 2, 3},
            {5, 6},
            {4},
            {7, 8, 9}
    };

    fmt::println("\n");
    auto flattened = pjc::ranges::flatten(matrix);
    fmt::println("{}", matrix);
    fmt::println("{}", flattened);

    auto testPartitionVec = std::vector<int>{10, 1, 2, 3, 50, 40, 20, 100, 101};
    auto predicate = [](auto val) -> bool { return val >= 10 && val < 100; };
    auto [t, f] = pjc::ranges::partition(testPartitionVec, predicate);

    fmt::println("true predicated: {}", t);
    fmt::println("false predicated: {}", f);

    return 0;
}


namespace pjc::ranges {

    template<typename T>
    auto partition(T &collection,
                   auto predicate) -> std::pair<std::vector<std::ranges::range_value_t<T>>, std::vector<std::ranges::range_value_t<T>>> {
        auto truePredicated = std::vector<std::ranges::range_value_t<T>>();
        auto falsePredicated = std::vector<std::ranges::range_value_t<T>>();

        for (auto &el: collection)
            predicate(el) ? truePredicated.push_back(el) : falsePredicated.push_back(el);

        return {truePredicated, falsePredicated};
    }

    template<typename T>
    auto drop(T &collection, int n) -> std::vector<std::ranges::range_value_t<T>> {
        auto filtered = std::vector<std::ranges::range_value_t<T>>();

        if (n >= collection.size()) {
            return filtered;
        }

        auto iter = collection.begin();

        // moving iterator
        for (int i = 0; i < n; i++)
            iter++;

        filtered.insert(filtered.end(), iter, collection.end());

        return filtered;

    }

    template<typename T>
    auto dropLast(T &collection, int n) -> std::vector<std::ranges::range_value_t<T>> {
        auto filtered = std::vector<std::ranges::range_value_t<T>>();

        if (n >= collection.size()) {
            return filtered;
        }

        auto iter = collection.end();

        // moving iter
        for (auto i = 0; i < n; i++)
            iter--;

        filtered.insert(filtered.end(), collection.begin(), iter);

        return filtered;
    }

    template<typename T>
    auto flatten(T &collection) -> std::vector<std::ranges::range_value_t<std::ranges::range_value_t<T>>> {
        auto vec = std::vector<std::ranges::range_value_t<std::ranges::range_value_t<T>>>();

        for (auto &inner: collection) {
            for (auto &innerItem: inner) {
                vec.push_back(innerItem);
            }
        }

        return vec;
    }

}
