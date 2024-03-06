#include <iostream>

auto main() -> int {

    using namespace std;
    auto userNumber = int();

    cout << "Input a one digit-number: ";
    cin >> userNumber;

    switch(userNumber) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        case 7:
            cout << "Seven";
            break;
        case 8:
            cout << "Eight";
            break;
        case 9:
            cout << "Nine";
            break;
        default:
            cout << "Incorrect input! Try again by restarting the program";
            break;
    }

}