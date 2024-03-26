#include <iostream>
#include <fstream>
#include <filesystem>
#include "fmt/ranges.h"


namespace util {

    template<typename T, typename Function, typename ReturnType = std::invoke_result_t<Function, T>>
    auto map(std::vector<T>& data, Function transformer) -> std::vector<ReturnType> {
        std::vector<ReturnType> mapped;

        for (const auto& el : data) {
            auto modified = transformer(el);
            mapped.push_back(modified);
        }

        return mapped;
    }


}

auto main() -> int {

    auto strings = std::vector<std::string>{"abc", "defghi", "jk", "lmno"};
    auto chars = util::map(
            strings,
            [](std::string s) { return s.front(); }
    );
    auto sizes = util::map(
            strings,
            [](std::string s) { return s.size(); }
    );

    fmt::println("{}", chars);
    fmt::println("{}", sizes);


    return 0;
}