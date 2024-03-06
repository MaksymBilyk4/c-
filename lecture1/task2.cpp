#include <iostream>
#include <string>
#include <algorithm>

auto main() -> int {

    using namespace std;

    string userData = "";

    cout << "Input some string: ";
    cin >> userData;

    cout << "First letter -> " << userData[0] << "\n";
    cout << "Last letter -> '" << userData[userData.size() - 1] << "'\n";
    cout << "Length -> " << userData.size() << "\n";
    cout << "Middle element -> " << userData[userData.size() / 2] << "\n";
    cout << "[ " << userData << " ]\n";

    ranges::sort(userData);

    cout << "Sorted -> " << userData;


}