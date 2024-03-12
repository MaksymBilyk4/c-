#include <iostream>
#include <fmt/ranges.h>
#include <algorithm>

auto task1() -> void;

auto task1_updated() -> void;

auto main() -> int {
    task1_updated();
}

auto task1() -> void {
    using namespace std;

    auto nums = vector<int>();

    auto userNumber = int();
    for (int i = 0; i < 7; i++) {
        cout << "#" << (i + 1) << " Enter a number: ";
        cin >> userNumber;
        nums.push_back(userNumber);
    }

    cout << "Input data:\n";
    fmt::println("{}", nums);

    int minIndex = 0, maxIndex = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[minIndex] > nums[i]) minIndex = i;
        if (nums[maxIndex] < nums[i]) maxIndex = i;
    }

    if (minIndex > maxIndex) {
        nums.erase(nums.begin() + maxIndex);
        nums.erase(nums.begin() + minIndex - 1);
    } else if (minIndex < maxIndex) {
        nums.erase(nums.begin() + minIndex);
        nums.erase(nums.begin() + maxIndex - 1);
    }

    cout << "After deleting min and max elements:\n";
    fmt::println("{}", nums);
}

auto task1_updated() -> void {

    auto nums = std::vector<int>();
    auto userNumber = int();

    for (int i = 0; i < 7; i++) {
        std::cout << i + 1 << "# Input number: ";
        std::cin >> userNumber;
        nums.push_back(userNumber);
    }

    fmt::println("{}", nums);

    auto minIterator = std::min_element(nums.begin(), nums.end());
    nums.erase(minIterator);
    auto maxIterator = std::max_element(nums.begin(), nums.end());
    nums.erase(maxIterator);

    fmt::println("{}", nums);
}