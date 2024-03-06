#include <iostream>
#include <string>
#include <random>
#include <math.h>

auto printVector(const std::vector<int> &data) -> void {
    for (int i: data) std::cout << i << " ";
    std::cout << "\n";
}

auto greeting() -> void {
    using namespace std;

    string username;

    cout << "Enter your name: ";
    cin >> username;

    cout << (username == "Einstein" ? "I know you" : "Greetings!");
}

auto guessNumber() -> void {

    using namespace std;
    random_device rd; // Получает случайное начальное число
    mt19937 gen(rd()); // Инициализирует генератор Мерсенна

    // Определение диапазона случайных чисел от 0 до 100
    uniform_int_distribution<> distrib(0, 100);

    int randomNumber = distrib(gen);
    cout << "Generated number ---> " << randomNumber << "\n";

    int guessedUserNumber = -1;

    while (randomNumber != guessedUserNumber) {
        cout << "Try to guess the number: ";
        cin >> guessedUserNumber;

        if (guessedUserNumber > randomNumber) cout << "Your number is bigger\n";
        else if (guessedUserNumber < randomNumber) cout << "Your number is lower\n";
    }

    cout << "Congratulations!\n";
}

auto isPrime(int number) -> bool {
    if (number < 2) return false;

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }

    return true;
}

auto primeNumbers() -> void {

    using namespace std;

    auto iterations = int();
    cout << "Input amount of iterations: ";
    cin >> iterations;

    auto vec = vector<int>();
    auto userNumber = int();

    if (iterations > 0) {
        for (int i = 0; i < iterations; i++) {
            cout << "(#" << i + 1 << ") Input number: ";
            cin >> userNumber;
            if (userNumber == -1) break;
            vec.push_back(userNumber);
        }
        printVector(vec);

        bool isPrimeNumber;
        for (int currentNum : vec) {
            isPrimeNumber = isPrime(currentNum);
            if (isPrimeNumber) cout << "Number " << currentNum << " is prime!!!!\n";
            else cout << "Number " << currentNum << " is NOT prime!!!!\n";
        }
    } else cout << "Bye!";

}


auto main() -> int {

//    greeting();
//    guessNumber();
//    primeNumbers();


    return 0;
}