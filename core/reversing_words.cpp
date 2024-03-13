#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


auto wordReverse(std::string str) -> std::string;

auto main() -> int {

    auto str = std::string();
    std::cout << "Input some string: ";
    std::getline(std::cin, str);

    auto reversed = wordReverse(str);
    std::cout << "Reversed string ---> " << reversed;

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