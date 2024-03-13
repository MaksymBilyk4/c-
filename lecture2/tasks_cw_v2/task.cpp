#include <fmt/core.h>
#include <fmt/ranges.h>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
// std::ranges::fill(start, end, val)

namespace task {

    auto minMaxRemove(std::vector<int> &vec) -> void;

    auto suffix(std::set<int> &s, std::vector<int> &vec) -> bool;

    auto isPalindrome(std::string str) -> bool;

    auto isPalindromeV2(std::string str) -> bool;

    auto sortBiggerHalf(std::vector<int> &vec) -> void;

    auto removingDuplicates(std::vector<std::string> &vec) -> void;

}

auto main() -> int {

    using namespace std;

    // TASK 1 Eliminowanie największej i najmniejszej wartości =======================================================

        auto vec1 = vector<int>{1, -100, 3, 4, 5, 100, 7, 8};
        task::minMaxRemove(vec1);

    // TASK 4 Największe elementy zbioru ==============================================================================

        auto vec2 = vector<int>{7, 6, 5, 8};
        auto s = set<int>{1, 2, 3, 4, 5, 6, 7};

        auto equality = task::suffix(s, vec2);
        fmt::println("Equality: {}", equality);

    // TASK 5 Palindromy ==============================================================================================
        fmt::println(
                "{}\n{}\n{}",
                task::isPalindromeV2("KajaK"),
                task::isPalindromeV2("ala"),
                task::isPalindromeV2("programowanie")
        );

    // TASK 6 Sortowanie wybranej połowy wektora ======================================================================
        auto firstHalfBigger = std::vector<int>{3, 2, 1, 0, 1, 0};
        auto secondHalfBigger = std::vector<int>{3, 2, 1, 6, 5, 4};
        auto bothHalvesSame = std::vector<int>{5, 4, 5, 4};
        task::sortBiggerHalf(firstHalfBigger);
        task::sortBiggerHalf(secondHalfBigger);
        task::sortBiggerHalf(bothHalvesSame);

    // TASK 7 Usuwanie duplikatów =====================================================================================
    auto vec3 = vector<string>{"Adam", "Illia", "Ewa", "Anastasia", "Illia", "Ewa", "Illia", "Maciej", "Adam",
                              "Natalia"};

    fmt::println("non-unique: {}", vec3);
    task::removingDuplicates(vec3);

    return 0;
}

namespace task {

    auto minMaxRemove(std::vector<int> &vec) -> void {
        auto minIter = vec.begin(), maxIter = vec.begin();

        for (auto iter = vec.begin(); iter != vec.end(); iter++) {
            if (*iter > *maxIter) maxIter = iter;
            if (*iter < *minIter) minIter = iter;
        }

        fmt::println("{}", vec);

        if (minIter > maxIter) {
            vec.erase(minIter);
            vec.erase(maxIter);
        } else {
            vec.erase(maxIter);
            vec.erase(minIter);
        }

        fmt::println("{}", vec);

    }

    auto suffix(std::set<int> &s, std::vector<int> &vec) -> bool {

        fmt::println("{}\n{}", s, vec);

        if (vec.size() > s.size()) return false;
        std::ranges::sort(vec);
        fmt::println("Sorted vec: {}", vec);

        auto dif = s.size() - vec.size();
        auto setStartPos = s.begin();

        for (int i = 0; i < dif; i++) setStartPos++;

        auto equality = std::ranges::equal(
                vec.begin(), vec.end(),
                setStartPos, s.end()
        );

        return equality;
    }

    auto isPalindrome(std::string str) -> bool {

        auto isPalindrome = true;

        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - i - 1]) {
                isPalindrome = false;
                break;
            }
        }

        return isPalindrome;

    }

    auto isPalindromeV2(std::string str) -> bool {
        std::string cpy = str;
        std::ranges::reverse(cpy);

        return std::ranges::equal(
                str.begin(), str.end(),
                cpy.begin(), cpy.end()
        );
    }

    auto sortBiggerHalf(std::vector<int> &vec) -> void {

        fmt::println("\n");
        auto firstHalfSum = vec[0];
        auto secondHalfSum = vec[vec.size() - 1];
        auto mid = vec.size() / 2;

        for (auto i = 1; i < mid; i++) {
            firstHalfSum += vec[i];
            secondHalfSum += vec[vec.size() - 1 - i];
        }

        fmt::println("First half sum: {}\nSecond half sum: {}", firstHalfSum, secondHalfSum);
        fmt::println("{}", vec);

        firstHalfSum > secondHalfSum ?
        std::ranges::sort(vec.begin(), vec.begin() + mid) :
        std::ranges::sort(vec.begin() + mid, vec.end());

        fmt::println("{}", vec);
    };

    auto removingDuplicates(std::vector<std::string> &vec) -> void {

        auto uniqueValues = std::set<std::string>(vec.begin(), vec.end());
        fmt::println("unique values: {}", fmt::join(uniqueValues, " "));

    }

}