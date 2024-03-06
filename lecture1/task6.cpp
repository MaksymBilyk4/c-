#include <iostream>
#include <vector>
#include <algorithm>

auto sumOfTwo(std::vector<int> vec, int val) -> bool {

    std::ranges::sort(vec);

    int leftPointer = 0;
    int rightPointer = vec.size() - 1;

    auto sum = int();

    while (leftPointer < rightPointer) {
        sum = vec[leftPointer] + vec[rightPointer];

        if (sum > val) rightPointer--;
        else if (sum < val) leftPointer++;
        else if (sum == val) {
            std::cout << "Found elements at indexes: [" << leftPointer << "] [" << rightPointer << "] \n";
            return true;
        }
    }

    return false;
}

auto main() -> int {

    using namespace std;
    auto vec = vector<int>{2, 4, 5, 8, 9, 11, 13, 15};


    bool  result = sumOfTwo(vec, 100);

    if (result) cout << "Indexes are found!";
    else cout << "Oops. Indexes are not found!";

    return 0;
}