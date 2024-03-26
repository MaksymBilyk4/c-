#include <fmt/core.h>
#include <fmt/ranges.h>
#include <algorithm>
#include <vector>
#include <string>

namespace pjc {
    namespace ranges {
//        template<typename T>
//        auto sort(T container) -> T;
//
//        template<typename T>
//        auto reverse(T) -> T;

        auto sort(std::vector<int> vec) -> std::vector<int>;

        auto reverse(std::vector<int> vec) -> std::vector<int>;
    }

    auto example(std::vector<std::string> left, std::vector<std::string> right) -> std::vector<std::string>;
}

auto main() -> int {

    using namespace std;

    auto vec = vector<int>{6, 3, 7, 1, 5};
    auto vecReversed = pjc::ranges::reverse(vec);
    auto vecSorted = pjc::ranges::sort(vec);


    fmt::println("Reversed -> {}", vecReversed);
    fmt::println("Sorted -> {}", vecSorted);

    auto strs1 = vector<string> {"10", "5", "2", "4"};
    auto strs2 = vector<string> {"10", "5", "2", "4", "7", "5", "2", "8", "1"};

    fmt::println("{}", strs2);
    auto res = pjc::example(strs1, strs2);
    fmt::println("{}", res);

    return 0;
}

namespace pjc {

    namespace ranges {

        auto sort(std::vector<int> vec) -> std::vector<int> {
            auto size = vec.size();
            auto sorted = std::vector<int>();

            for (int i = 0; i < size; i++) {
                auto minVal = std::ranges::min(vec);

                sorted.push_back(minVal);

                auto toRemoveIter = std::ranges::find_if(
                        vec.begin(), vec.end(),
                        [&minVal](int val) { return val == minVal; }
                );

                vec.erase(toRemoveIter, toRemoveIter + 1);
            }

            return sorted;
        }

        auto reverse(std::vector<int> vec) -> std::vector<int> {
            auto tmp = 0;
            auto vecSize = vec.size();
            for (auto i = 0; i < vecSize / 2; i++) {
                if (vec[i] != vec[vecSize - i - 1]) {
                    tmp = vec[i];
                    vec[i] = vec[vecSize - i - 1];
                    vec[vecSize - i - 1] = tmp;
                }
            }

            return vec;
        }

    }

    auto example(
            std::vector<std::string> left, std::vector<std::string> right
    ) -> std::vector<std::string> {

        auto removeDuplicates = [](std::vector<std::string> &vec) -> void {
            std::ranges::sort(vec);
            auto duplicates = std::ranges::unique(vec);
            vec.erase(duplicates.begin(), duplicates.end());
        };

        removeDuplicates(left);
        removeDuplicates(right);

        auto leftSize = left.size();
        auto rightSize = right.size();


        if (leftSize < rightSize) {
            std::ranges::sort(left);
            return right;
        } else {
            std::ranges::sort(right);
            return left;
        }
    }

}