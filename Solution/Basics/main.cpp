#include "handbook_tasks.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>


std::vector<std::pair<std::string, int>> E(const std::vector<std::string>& words, const int gramm_length)
{
    std::unordered_map<std::string, int> freq;

    for (const std::string& word : words)
    {
        for (size_t i = gramm_length; i <= word.size(); i++)
        {
            ++freq[word.substr(i - gramm_length, gramm_length)];
        }
    }

    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());

    std::sort(sorted.begin(), sorted.end(), [](const auto& p1, const auto& p2) {
        return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
        });

    return sorted;
}

int main()
{
    int m, n;

    std::cin >> m >> n;

    std::vector<std::string> words;
    words.reserve(m);
    std::string word;

    for (int i = 0; i < m; i++)
    {
        std::cin >> word;
        words.push_back(word);
    }

    std::vector<std::pair<std::string, int>> result = E(words, n);

    for (const auto& value : result)
        std::cout << value.first << " - " << value.second << std::endl;

    return 0;
}