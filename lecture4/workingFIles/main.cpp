#include <filesystem>
#include <fstream>
#include <string>

#include "fmt/core.h"

auto numberOfLines(std::filesystem::path &path) -> int;

auto main() -> int {

    namespace fs = std::filesystem;
    auto nameOfFileWithMostLines = std::string();
    auto mostLinesInFile = 0;

    auto path = fs::path("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/lecture4/files");

    for (auto &entry: fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry)) {
            auto entryPath = entry.path();
            auto linesInThisFile = numberOfLines(entryPath);
            if (linesInThisFile > mostLinesInFile) {
                mostLinesInFile = linesInThisFile;
                auto thisFileName = entryPath.filename().string();
                nameOfFileWithMostLines = thisFileName;
            }
        }
    }

    fmt::println(
            "File with most lines is \"{}\" and it contains {} lines",
            nameOfFileWithMostLines, mostLinesInFile
    );

    return 0;
}

auto numberOfLines(std::filesystem::path &path) -> int {
    auto file = std::fstream(path);
    auto line = std::string();

    auto lineCount = 0;

    while (std::getline(file, line)) lineCount++;

    return lineCount;

}