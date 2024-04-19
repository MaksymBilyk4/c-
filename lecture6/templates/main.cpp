
#include <fmt/core.h>
#include <fmt/format.h>
#include <sstream>

template<typename T, typename U, typename V>
struct Triple {

    T first;
    U second;
    V third;

    Triple() = default;

    Triple(T first, U second, V third) : first(first), second(second), third(third) {}
    Triple(T first, U second) : first(first), second(second) {}

    auto overwrite(Triple<T, U, V> triple) -> void {
        first = triple.first;
        second = triple.second;
        third = triple.third;
    }

    template<typename T_Other, typename U_Other, typename V_Other>
    auto equals(Triple<T_Other, U_Other, V_Other> other) -> bool {
        return other.first == first && other.second == second && other.third == third;
    }

    auto toString() -> std::string {
        auto sstream = std::stringstream();
        sstream << "( " << first << ", " << second << ", " << third << " )";
        return sstream.str();
    }

};

//template<typename T, typename U, typename V>
//auto format_as(Triple<T, U, V> triple) -> std::string {
//    return fmt::format("( {}, {}, {} )", triple);
//}

auto main() -> int {

    auto x = Triple<int, int, int>(1, 2, 3);
    auto y = Triple<int, int, int>(1, 2, 3);
    auto z = Triple<int, int, int>(3, 2, 1);

    auto xD = Triple<int, double, int>(1, 2.0, 3);
    auto yD = Triple<double, int, double>(1.0, 2, 3.0);

    fmt::println("{} {} {}", x.equals(y), y.equals(z), z.equals(x));
    fmt::println("{}", xD.equals(yD));

    return 0;
}