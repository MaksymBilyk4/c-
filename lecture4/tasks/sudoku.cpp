#include <iostream>
#include <fstream>
#include <filesystem>
#include "fmt/core.h"
#include "fmt/std.h"
#include "fmt/ranges.h"

namespace sudoku {

    auto write_correct_sudoku(std::string &path) -> void;

}

auto main() -> int {

    auto path1 = std::string();
    path1 = "/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/sudoku";
    sudoku::write_correct_sudoku(path1);

    return 0;
}

namespace sudoku {

    auto write_correct_sudoku(std::string &path) -> void {
        namespace fs = std::filesystem;

        if (!fs::exists(path)) {
            fmt::println("Provided path does not exists!");
            return;
        }

        auto isCorrectSudoku = [](std::string path) -> bool {
            auto flag = true;

            auto file = std::fstream(path, std::ios::in);
            auto matrix = std::vector<std::vector<int>>(9, std::vector<int>());
            auto digit = char();

            // fill matrix
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    file >> digit;
                    matrix[i].push_back((int) (digit - '0'));
                }
            }

            auto rowVector = std::vector<int>();
            auto columnVector = std::vector<int>();

            for (int i = 0; i < matrix.size(); ++i) {

                for (auto j = 0; j < matrix[i].size(); j++) {
                    rowVector.push_back(matrix[j][i]);
                    columnVector.push_back(matrix[i][j]);
                }

                std::ranges::sort(rowVector);
                std::ranges::sort(columnVector);

                auto rowDuplicates = std::ranges::unique(rowVector);
                auto columnDuplicates = std::ranges::unique(columnVector);

                if (!rowDuplicates.empty() || !columnDuplicates.empty()) {
                    flag = false;
                    break;
                }
                rowVector.clear();
                columnVector.clear();
            }

            return flag;
        };

        auto writeToFile = [](std::string writePath, std::string readPath) -> void {
            auto readFrom = std::fstream(readPath, std::ios::in);

            auto writeTo = std::fstream(writePath + "/solutions.txt", std::ios::app);

            if (!readFrom.is_open() || !writeTo.is_open()) {
                fmt::print("Failed to open file(s).\n");
                return;
            }

            auto line = std::string();

            while (std::getline(readFrom, line)) {
                fmt::println(writeTo, "{}", line);
            }
            writeTo << "\n";
        };

        for (auto &entry: fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry)) {
                if (isCorrectSudoku(entry.path().string())) {
                    fmt::println("found correct sudoku {}", entry.path());
                    writeToFile(path, entry.path().string());
                }
            }
        }

    }

}