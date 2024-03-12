#include <iostream>
#include <vector>
#include <algorithm>

namespace calculator {

    auto plus(double, double) -> double;

    auto minus(double, double) -> double;

    auto divide(double, double) -> double;

    auto multiply(double, double) -> double;

}

auto doSomething() -> void;

auto format(std::vector<int> &) -> void;

auto format(std::vector<int> &, std::string, std::string, std::string separator) -> void;


auto main() -> int {

    using namespace std;

    // EQUALS =======================================================================================================

    auto vec = vector<int>{1, 2, 3, 4, 4, 3, 2, 1};

    auto mid = vec.begin() + vec.size() / 2;

    fmt::println("{}", vec);
    ranges::sort(mid, vec.end());
    fmt::println("{}", vec);

    auto res = ranges::equal(
            vec.begin(), mid,
            mid, vec.end()
    );

    fmt::println("result of equality: {}", res);

    // REMOVE DUPLICATES ===========================================================================================
    ranges::sort(vec);

    auto duplicates = ranges::unique(vec);
    vec.erase(duplicates.begin(), duplicates.end());
    fmt::println("deleted duplicates: {}", vec);

    doSomething();


    format(vec, "@", "#", ", ");
    format(vec);


    auto operation = char();
    auto val1 = int(), val2 = int();

    cout << "Enter first number: ";
    cin >> val1;
    cout << "Enter second number: ";
    cin >> val2;
    cout << "Enter an operation: ( + | - | * | / |): ";
    cin >> operation;

    switch (operation) {
        case '+':
            fmt::println("{} + {} = {}", val1,val2, calculator::plus(val1, val2));
            break;
        case '-':
            fmt::println("{} - {} = {}", val1,val2, calculator::minus(val1, val2));
            break;
        case '/':
            fmt::println("{} / {} = {}", val1,val2, calculator::divide(val1, val2));
            break;
        case '*':
            fmt::println("{} * {} = {}", val1,val2, calculator::multiply(val1, val2));
            break;
        default:
            fmt::println("Oops. Unknown operation...");
            break;
    }

    return 0;
}

auto doSomething() -> void {
    fmt::println("Do something func");
}

auto format(std::vector<int> &vec) -> void {
    format(vec, "[", "]", ". ");
}

auto format(
        std::vector<int> &vec,
        std::string suffix,
        std::string prefix,
        std::string separator
) -> void {

    fmt::println("{} {} {}", suffix, fmt::join(vec, separator), prefix);

}

namespace calculator {

    auto plus(double val1, double val2) -> double {
        return val1 + val2;
    }

    auto minus(double val1, double val2) -> double {
        return val1 - val2;
    }

    auto divide(double val1, double val2) -> double {
        return val1 / val2;
    }

    auto multiply(double val1, double val2) -> double {
        return val1 * val2;
    }

}
