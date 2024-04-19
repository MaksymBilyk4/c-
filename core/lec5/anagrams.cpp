#include <fmt/ranges.h>
#include <fmt/core.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

auto largestAnagramGroupsFrom1(std::string &text) -> std::vector<std::set<std::string>> {

    // iter init
    auto start = text.begin();
    auto end = text.end();

    // words map
    auto words = std::map<std::string, std::set<std::string>>();

    // current countable word
    auto currentWord = std::string();

    auto maxFrequenciesSize = 0;

    while (start != end) {
        if (*start >= 'a' && *start <= 'z' || *start >= 'A' && *start <= 'Z') {
            currentWord.push_back(*start);
        } else {
            auto cpy = currentWord;
            std::ranges::sort(currentWord);
            words[currentWord].insert(cpy);
            if (words[currentWord].size() > maxFrequenciesSize) maxFrequenciesSize = words[currentWord].size();
            currentWord.clear();
        }

        start++;
    }

    auto maxFrequenciesVec = std::vector<std::set<std::string>>();

    for (auto &entry: words) {
        if (entry.second.size() == maxFrequenciesSize)
            maxFrequenciesVec.push_back(entry.second);
    }

    return maxFrequenciesVec;
}

auto largestAnagramGroupsFrom(std::string &text) -> std::vector<std::set<std::string>> {

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

    auto frequenciesVec = std::vector<std::set<std::string>>();

    for (auto &entry: words) {
        if (entry.second.size() > 1)
            frequenciesVec.push_back(entry.second);
    }

    return frequenciesVec;
}


auto main() -> int {
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

    auto anagrams = largestAnagramGroupsFrom(megaText);
    for (auto &anagramsSet: anagrams)
        fmt::println("{}", fmt::join(anagramsSet, ", "));


    return 0;
}