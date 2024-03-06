#include <iostream>
#include <string>
#include <vector>


auto boxPrint(std::vector<std::string> vec, char character = '*') -> void {
    using namespace std;

    string maxElement = vec.size() > 0 ? vec[0] : "";
    int maxLength = vec.size() > 0 ? vec[0].length() : 0;

    for (int i = 1; i < vec.size(); i++) {
        if(maxLength < vec[i].length()) {
            maxLength = vec[i].length();
            maxElement = vec[i];
        }
    }

    cout << "Longest element ---> " << maxElement << "\n";

    cout << string(maxLength + 2, character) << "\n";

    auto diff = int();

    for (int i = 0; i < vec.size(); i++) {
        diff = maxLength - vec[i].size();
        cout << character << vec[i] << string(diff, ' ')<< character << "\n";
    }

    cout << string(maxLength + 2, character) << "\n" << "\n";

}

auto main() -> int {

    using namespace std;

    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmmm", ""});
    boxPrint({"", "", ""});

}