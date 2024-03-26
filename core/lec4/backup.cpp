#include <filesystem>
#include <fmt/core.h>


namespace files {

    auto backup(std::string &fromPath, std::string &toPath) -> bool;

}

auto main() -> int {

    auto source = std::string();
    auto destination = std::string();

    source = "#";
    destination ="#";

    auto backupResult = files::backup(source, destination);

    fmt::println("Back result: {}", backupResult);

    return 0;
}

namespace files {

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

        for (auto &entry: fs::recursive_directory_iterator(fromPath)) {


            auto relative = fs::relative(entry.path(), fromPath);
            auto targetPath = fs::path(toPath) / relative;

            if (entry.is_regular_file()) {
                fs::copy_file(entry.path(), fs::path(targetPath));
            }

            if (entry.is_directory()) {
                fs::create_directory(targetPath);
            }

        }

        return true;

    }

}