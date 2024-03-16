#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


auto wordReverse(std::string str) -> std::string;

auto wordReverseOptimized(std::string &str) -> void;

auto main() -> int {

    auto str = std::string("hel  world");
//    std::cout << "Input some string: ";
//    std::getline(std::cin, str);

//    auto reversed = wordReverse(str);
//    std::cout << "Reversed string ---> " << reversed;

    wordReverseOptimized(str);


    return 0;
}

auto wordReverse(std::string str) -> std::string {

    auto vec = std::vector<std::string>{};

    bool isSpace = false;
    auto beginPtr = str.begin();
    auto endPtr = str.begin();

    while (true) {
        if (endPtr == str.end()) {
            vec.push_back(std::string(beginPtr, endPtr));
            break;
        }

        if (*endPtr == ' ' && !isSpace) {
            vec.push_back(std::string(beginPtr, endPtr));
            beginPtr = endPtr;
            isSpace = true;
        }

        if (*endPtr != ' ' && isSpace) {
            vec.push_back(std::string(beginPtr, endPtr));
            beginPtr = endPtr;
            isSpace = false;
        }

        // przesuwam
        endPtr++;
    }

    std::ranges::reverse(vec);
    auto res = std::string();

    for (auto el: vec)
        res += el;

    return res;
}

auto wordReverseOptimized(std::string &str) -> void {

    using namespace std;

    auto temp1 = string();
    auto temp2 = string();

    auto iterStart = true;
    auto iterEnd = true;

    auto i = 0;
    auto k = 0;


    auto j = str.size() - 1;
    auto x = str.size() - 1;

    cout << str << "\n";

    while (true) {

        if (iterStart && str[i] == ' ') {
            iterStart = false;
            temp1 = str.substr(k, i);
        }

        if (iterEnd && str[j] == ' ') {
            iterEnd = false;
            temp2 = str.substr(j, x);
        }

        if (iterStart) {
            i++;
        }

        if (iterEnd) {
            j--;
        }

        if (!iterStart && !iterEnd) {
            str.replace(k, i, temp2);
            str.replace(j + temp2.size() - temp1.size(), x - k, temp1);
            break;
//            k = i;
//            x = j;

        }

    }

    cout << str << "\n";

}