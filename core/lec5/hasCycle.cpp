#include <map>
#include <string>
#include <set>
#include <fmt/core.h>
#include <fmt/ranges.h>

auto DFS(std::map<std::string, std::set<std::string>> &graph, std::set<std::string> &passed,
         std::string currentKey) -> void {

    fmt::println("{}", currentKey);

    auto currentNode = graph[currentKey];
    passed.insert(currentKey);

    for (auto el: currentNode) {
        if (!passed.contains(el))
            DFS(graph, passed, el);
    }

}

auto DFSNoCycle(
        std::map<std::string, std::set<std::string>> &graph,
        std::set<std::pair<std::string, std::string>> &passed,
        std::string currentKey
) -> bool {
    auto node = graph[currentKey];

    for (auto value: node) {
        if (!passed.contains({currentKey, value})) {
            passed.insert({currentKey, value});
            return DFSNoCycle(graph, passed, value);
        } else return true;
    }

    return false;
}

auto hasCycle(std::map<std::string, std::set<std::string>> &graph, std::string startKey) -> bool {
    auto passed = std::set<std::pair<std::string, std::string>>();
    return DFSNoCycle(graph, passed, startKey);
}

auto main() -> int {

    auto graph = std::map<std::string, std::set<std::string>>();
    graph["A"] = {"B", "C"};
    graph["B"] = {"E"};
    graph["C"] = {"D"};
    graph["D"] = {"B"};
    graph["E"] = {"C"};

    auto cycle = hasCycle(graph, "A");
    fmt::println("{}", cycle);

    return 0;
}