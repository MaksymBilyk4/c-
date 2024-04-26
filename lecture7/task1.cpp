#include <fmt/core.h>
#include <fmt/ranges.h>
#include <string>
#include <vector>
#include <type_traits>
#include <initializer_list>

auto operator*(std::string const &s, int n) -> std::string {
    auto res = std::string();

    for (int i = 0; i < n; i++)
        res += s;

    return res;
}

auto operator*(int n, std::string const &s) -> std::string {
    auto res = std::string();
    for (int i = 0; i < n; i++)
        res += s;
    return res;
}

auto operator/(std::string const &str, int splitStep) -> std::vector<std::string> {
    auto splitted = std::vector<std::string>();

    if (splitStep >= str.size()) {
        splitted.push_back(str);
        return splitted;
    }

    for (int i = 0; i < str.size();) {
        splitted.push_back(str.substr(i, splitStep));
        i += splitStep;
    }

    return splitted;

}

template<typename T, typename U>
auto operator*(std::vector<T> const &vec1, std::vector<U> const &vec2) -> std::common_type<T, U>::type {
    if (vec1.size() != vec2.size()) return 0;


    auto res = typename std::common_type<T, U>::type();

    for (auto i = 0; i < vec1.size(); i++) {
        res += (vec1[i] * vec2[i]);
    }

    return res;
}

template<typename T>
class VectorAppender {
private:
    std::vector<T> &vec;

public:
    VectorAppender(std::vector<T> &v) : vec(v) {}

    auto operator,(T value) -> VectorAppender& {
        vec.push_back(value);
        return *this;
    }
};

template<typename T>
auto operator+=(std::vector<T> &vec, T value) -> VectorAppender<T> {
    vec.push_back(value);
    return VectorAppender<T>(vec);
}

auto main() -> int {

    auto string = std::string();
    string = "some_string";

    auto data1 = string * 2;
    auto data2 = 3 * string;

    fmt::println("{}", data1);
    fmt::println("{}", data2);

    auto toSplit = std::string();
    toSplit = "it is splitter121";

    fmt::println("{}", toSplit / 5);

    auto vec1 = std::vector<double>{1.3, 2.0, 3.1};
    auto vec2 = std::vector<int>{1, 2, 3};
    fmt::println("{}", vec1 * vec2);


    vec2 += 4, 5, 6;
    fmt::println("Here: {}", vec2);

    return 0;
}