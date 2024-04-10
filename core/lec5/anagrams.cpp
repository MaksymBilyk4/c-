#include <fmt/ranges.h>
#include <fmt/core.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

auto largestAnagramGroupsFrom(std::string &text) -> std::vector<std::string> {

    // iter init
    auto start = text.begin();
    auto end = text.end();

    // words map
    auto words = std::map<std::string, std::set<std::string>>();

    // current countable word
    auto currentWord = std::string();

    while (start != end) {
        if (*start >= 'a' && *start <= 'z' || *start >= 'A' && *start <= 'Z') {
            currentWord.push_back(*start);
        } else {
            auto cpy = currentWord;
            std::ranges::sort(currentWord);
            words[currentWord].insert(cpy);
            currentWord.clear();
        }

        start++;
    }

    auto max = std::ranges::max_element(
            words.begin(),
            words.end(),
            {},
            [](auto& entry) -> int {return entry.second.size();}
    );

    fmt::println("{}", words);

    return {max->second.begin(), max->second.end()};
}

auto main() -> int {
    fmt::println("{}", "yessir");

    auto megaText = std::string();
    megaText = "In life, we find ourselves perplexed\n"
               "By twists and turns, and what comes next\n"
               "We wonder where our path will lead\n" // evol
               "And hope for guidance, in our need\n"
               "But sometimes all we need to do\n"
               "Is simply change our point of view\n"
               "For “listen” can become “silent” too\n"
               "And “love” can turn into “vole” anew\n"
               "There’s “evil” hiding in “live”\n"
               "And “cinema” in “iceman” lives\n"
               "To look for the positive, and let our hearts be lighter\n"
               "But let’s focus on the good, and be a little kinder\n"
               "We can find “heart” in “earth” below\n"
               "And “care” in “race” - it’s apropos\n"
               "“Strained” can be “disrate,” and that’s okay\n"
               "For tomorrow is a brand new day\n"
               "So let’s embrace the twists and turns\n"
               "And all the lessons that life confirms\n"
               "For every problem, there’s a clue\n"
               "And an anagram to guide us through.\n"
               "For completeness, let’s add few more,\n"
               "made-up, words: elov arce\n";

    auto result = largestAnagramGroupsFrom(megaText);
    fmt::println("{}", result);

    return 0;
}