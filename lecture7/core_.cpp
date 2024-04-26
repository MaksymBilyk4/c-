#include <fmt/core.h>
#include "Matrix.hpp"
#include <vector>

auto main() -> int {

//    auto m1 = Matrix<int>(3, 3, 1);
//    auto m2 = Matrix<int>(3, 3, 2);
//
//    m1.printFormattedMatrix();
//    m2.printFormattedMatrix();
//
//    auto m3 = m1 + m2;
//    m3.printFormattedMatrix();
//
//    m1 = m1 - m3;
//
//    m1.printFormattedMatrix();
//
//
//    auto test1 = std::vector<std::vector<int>>{
//            {1, 1, 1, 3},
//            {2, 1, 5, 4},
//            {0, 4, 1, 2}
//    };
//
//    auto test2 = std::vector<std::vector<double>>{
//            {1.01, 0,    1.06},
//            {2.1,  2.4,  2.5},
//            {3.9,  6.2,  1.24},
//            {2.00, 1.00, 4.4}
//    };
//
//    auto testMa1 = Matrix(test1);
//    auto testMa2 = Matrix(test2);
//
//    auto res = testMa1 * testMa2;
//    res.printFormattedMatrix();
//
//
    auto test1 = std::vector<std::vector<float>>{
            {3.5, 0.5},
            {2.1, 1.2},
    };

    auto test2 = std::vector<std::vector<int>>{
            {3, 1, 1},
            {2, 0, 4},
    };
    auto obj1 = Matrix(test1);
    auto obj2 = Matrix(test2);

    fmt::println("mnożenie: ");
    auto mult = obj1 * obj2;
    mult.printFormattedMatrix();

    auto test3 = std::vector<std::vector<int>>{
            {1, 2, 3},
            {3, 2, 1},
            {4, 5, 6}
    };

    auto test4 = std::vector<std::vector<double>>{
            {4.5, 3.1, 6.9},
            {4.2, 3.9, 0.2},
            {1.8, 3.1, 3.3}
    };

    auto matrix1 = Matrix(test3);
    auto matrix2 = Matrix(test4);


    auto res1 = matrix1 + matrix2;
    auto res2 = matrix2 - matrix1;

    res1.printFormattedMatrix();
    res2.printFormattedMatrix();

    return 0;

}