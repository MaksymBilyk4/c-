#include <filesystem>
#include <fmt/core.h>


namespace files {

    namespace fs = std::filesystem;

    auto backup(std::string &fromPath, std::string &toPath) -> bool;

    auto processBackup(fs::path &source, fs::path &target) -> void;

}

auto main() -> int {

    auto source = std::string();
    auto destination = std::string();

    source = "/Users/maksymbilyk/Desktop/programming/PJAIT/C++/core/lec4/fromPath";
    destination = "/Users/maksymbilyk/Desktop/programming/PJAIT/C++/core/lec4/toPath";

    auto backupResult = files::backup(source, destination);

    fmt::println("Backup result: {}", backupResult);

    return 0;
}

namespace files {

    namespace fs = std::filesystem;

    auto processBackup(fs::path &source, fs::path &target) -> void {
        if (!fs::exists(target) && !fs::create_directories(target)) {
            fmt::print("Can't create : {}\n", target.string());
            return;
        }

        for (const auto &entry: fs::directory_iterator(source)) {

            if (entry.is_directory()) {
                auto sourcePath = entry.path();
                auto targetPath = target / (entry.path().filename().string() + "_backup");
                files::processBackup(sourcePath, targetPath);
            } else if (entry.is_regular_file()) {
                auto replacedExtension = entry.path().filename().stem().string() + "_backup" + entry.path().extension().string();
                auto destination = target / replacedExtension;
                fs::copy(entry.path(), destination);
            }
        }
    }

    auto backup(std::string &fromPath, std::string &toPath) -> bool {
        namespace fs = std::filesystem;

        if (!fs::exists(fromPath) || !fs::exists(toPath)) {
            fmt::println("Provided path does not exist");
            return false;
        }

        if (!fs::is_directory(fromPath) || !fs::is_directory(toPath)) {
            fmt::println("Provided path is not directory");
            return false;
        }

        auto source = fs::path(fromPath);
        auto target = fs::path(toPath);

        files::processBackup(source, target);

        return true;

    }

}