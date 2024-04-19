#include <fmt/core.h>

template<typename T>
struct Hasher {

    auto compute(T t) -> int {
        return t;
    }

};

auto main() -> int {

    auto intHash = Hasher<int>();

    auto h1 = intHash.compute(3232);
    auto h2 = intHash.compute(-199432);

    fmt::println("{}, {}", h1, h2);

    return 0;
}