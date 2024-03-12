#include <vector>
#include <fmt/ranges.h>
#include <iostream>
#include <set>
#include <string>

auto printSet(std::set<std::string> &data) -> void {
    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

auto printVectorInt(std::vector<int> &vec) -> void {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

auto printVector(std::vector<std::string> &vec) -> void {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

auto main() -> int {

    using namespace std;

//    auto vec = vector<string>{"Maksym", "Andrii", "Andrii", "Bohdan", "Alex", "Alex"};
//    auto s = set<string>(vec.begin(), vec.end());
//
//    cout << "Vector: \n";
//    printVector(vec);
//
//    cout << "\n" << "Set: \n";
//    printSet(s);
//
//    s.insert("Artem");
//    s.insert("Den");
//    printSet(s);
//
//    cout << "\nUnique vector: \n";
//    vec = vector<string>(s.begin(), s.end());
//    printVector(vec);

    // UNIQUE, ERASE

    // (5, 1) - create 1 - 5 times
//    auto vec = vector<int>{1, 2, 3, 4, 5, 6, 7};

    // ERASE
//    printVectorInt(vec);
//    vec.erase(vec.begin());
//    printVectorInt(vec);
//    vec.erase(vec.end() - 1);
//    printVectorInt(vec);
//    vec.erase(vec.begin(), vec.end() - 1);
//    printVectorInt(vec);

    auto vec1 = vector<int>{1, 2, 3, 1, 2, 3, 4, 4, 3};

    ranges::sort(vec1);
    printVectorInt(vec1);
    auto duplicates = ranges::unique(vec1.begin(), vec1.end());
    vec1.erase(duplicates.begin(), duplicates.end());
    printVectorInt(vec1);



//    cout << "Before removing duplicates: \n";
//    printVectorInt(vec1);
//    auto duplicates = ranges::unique(vec1.begin(), vec1.end());
//    vec1.erase(duplicates.begin(), duplicates.end());
//    cout << "After removing duplicates: \n";
//    printVectorInt(vec1);

    cout << "Duplicates:\n";
    for (int duplicate: duplicates) {
        cout << duplicate << " ";
    }

}