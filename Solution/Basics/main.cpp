#include "handbook_tasks.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <utility>


std::map<int, std::set<std::string>> D(const std::vector<std::pair<int, std::string>>& input)
{
    std::map<int, std::set<std::string>> result;

    for (const auto& line : input)
    {
        int page = line.first;
        std::string word = line.second;
        result[page].insert(word);
    }

    return result;
}
int main()
{
    int number_lines;

    std::cin >> number_lines;

    std::vector<std::pair<int, std::string>> lines;
    lines.reserve(number_lines);

    for (int i = 0; i < number_lines; ++i)
    {
        std::pair<int, std::string> inp;

        std::cin >> inp.second >> inp.first;
        lines.push_back(inp);
    }

    const std::map<int, std::set<std::string>> result = D(lines);

    for (const auto& [index, values] : result)
    {
        std::cout << index;
        for (const auto& value : values)
            std::cout << ' ' << value;
        std::cout << '\n';
    }

    return 0;
}