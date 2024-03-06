#include <iostream>
#include <vector>


auto printVector(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) std::cout << vec[i] << " ";
    std::cout << "\n";
}

auto areVectorsEqual(std::vector<int> vec1, std::vector<int> vec2) -> bool {
    std::ranges::sort(vec1);
    std::ranges::sort(vec2);

    return vec1 == vec2;
}

auto main() -> int {

    using namespace std;

    auto vec1 = vector<int>();
    auto vec2 = vector<int>();

    auto userData = int();

    cout << "Input 10 numbers: \n";
    for (int i = 0; i < 10; i++) {
        cout << "#" << i + 1 << " ----> ";
        cin >> userData;
        if (i <= 4) {
            vec1.push_back(userData);
        }else vec2.push_back(userData);
    }

    cout << "Your vectors look like that: \n";
    printVector(vec1);
    printVector(vec2);

    cout << "Result ----> " << areVectorsEqual(vec1, vec2);

}