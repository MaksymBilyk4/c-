#include <iostream>
#include <vector>
#include <set>

auto printVector(std::vector<int> &vec) {
    for (int el: vec)
        std::cout << el << " ";

    std::cout << "\n";
}

auto printVectorIter(std::vector<int> &vec) {
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

auto main() -> int {

    using namespace std;

//    cout << "Begin iterator:\n";


//    auto iteratorBegin = data.begin();
//    cout << *iteratorBegin << " ";
//    iteratorBegin++;
//    cout << *iteratorBegin << "\n";

//    auto data = set<int>{1, 3, 8, 10, 12};
//    auto iteratorEnd = data.end();
//    cout << "Iterator from end: \n";
//    iteratorEnd--;
//    cout << *iteratorEnd << " ";


//    auto vec = vector<int>{3, 5, 1, 4, 2};
//
//    auto iterator = vec.begin();
//    cout << *iterator << " - first element\n";
//
//    iterator = vec.end() - 1;
//    *iterator = 90;
//    cout << *iterator << " - last element\n";
//    printVector(vec);
//    vec.push_back(0);
//    iterator = vec.begin();
//
//    std::ranges::sort(vec.begin(), vec.begin() + vec.size() / 2);
//    std::ranges::reverse(vec.begin() + vec.size() / 2, vec.end());
//
//    printVector(vec);

//    auto vec = vector<int>{3, 5, 1, 4, 2, 0};
//
//    ranges::sort(vec.begin(), vec.begin() + vec.size() / 2);
//    ranges::reverse(vec.begin() + vec.size() / 2, vec.end());
//
//    printVector(vec);

//    auto data = vector<int>{100, 30, 1, 3232, 23, 8, 5};

//    auto iterator = data.begin();
//    cout << "Before: " << *iterator << "\n";
//    *iterator = 100;
//    cout << "After: " << *iterator << "\n";
//
//    *iterator++;
//    cout << *iterator;

    /*
         reset pointer
         iterator = vec.begin();
         * - current pointer address
         ++ - go to next address
         -- - return back to previous address
         begin() - sets pointer to first element
         end() - sets pointer to last element
         front() - value of FIRST element
         back() - value of LAST element
     */

//    auto iter = data.begin() + data.size() / 2;
//    cout << "Middle value: " << *iter << "\n";
//    printVector(data);
//    std::ranges::sort(data.begin(), data.begin() + data.size() / 2);
//    std::ranges::reverse(data.begin() + data.size() / 2, data.end());
//    printVector(data);
    // [x, y) ---> the end of one subrange is automatically the beginning of the next.

//    auto beginIter = data.begin();
//    auto someIter = data.begin() + 4;

//    cout << "Begin iter: " << *beginIter << "\n";
//    cout << "Some iter: " << *someIter << "\n";
//    printVector(data);
//    std::ranges::reverse(beginIter, someIter);
//    printVector(data);
//    cout << 7 / 2;

//    auto vec = vector<int>{11, 22, 33, 22, 33, 11};
//
//    printVector(vec);
//
//    auto middle = vec.begin() + vec.size() / 2 ;
//
//    std::ranges::sort(vec.begin(), middle);
//    std::ranges::sort(middle, vec.end());
//
//    printVector(vec);
//
//    std::ranges::reverse(middle, vec.end());
//
//    printVector(vec);
//
//    auto bothHalvesEqual = std::ranges::equal(
//            vec.begin(), middle,
//            middle, vec.end()
//    );
//
//    cout << bothHalvesEqual;


    auto vec = vector<char>{'h', 'e', 'l', 'l', 'o'};
    auto str = string("hello");

    auto isEquals = std::ranges::equal(
            vec.begin(), vec.end(),
            str.begin(), str.end()
    );
    cout << isEquals << "\n";
    auto test = vector<int>{1, 2, 3, 4, 5, 6, 7};
    printVectorIter(test);

    return 0;
}