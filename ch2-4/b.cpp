/*
Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию.
На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:

Первая буква слова сохраняется.
В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
b, f, p, v: 1
c, g, j, k, q, s, x, z: 2
d, t: 3
l: 4
m, n: 5
r: 6
Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
Итоговая строка обрезается до первых четырёх символов.
Если длина строки получилась меньше четырёх символов, в конце добавляются нули.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


int main()
{   
    std::string word, result;

    const std::vector<std::vector<char>> letters = {{'b', 'f', 'p', 'v'}, 
                                                {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'},
                                                {'d', 't'},
                                                {'l'},
                                                {'m', 'n'},
                                                {'r'}};
    const std::vector<char> charactersToRemove = {'a', 'e', 'h', 'i', 'o', 'u', 'w'};

    std::cin >> word;

    result.push_back(word[0]);

    // Remove characters
    for (size_t i = 1; i != word.size(); ++i)
    {
        if (std::find(charactersToRemove.begin(), charactersToRemove.end(), word[i]) != charactersToRemove.end())
            continue;
        else
            result.push_back(word[i]);
    }

    for (size_t i = 1; i != result.size(); ++i)
    {
        for (size_t j = 0; j != letters.size(); ++j)
        {
            /* code */
            if(std::find(letters[j].begin(), letters[j].end(), result[i]) != letters[j].end())
            {
                // word[i] = static_cast<char>(static_cast<int>('0') + j + 1);
                result[i] = (static_cast<char>(static_cast<int>('0') + j + 1));
                break;
            }
        }// end for j
    }// end for i
    
    auto new_word = std::unique(result.begin(), result.end());
    result.erase(new_word, result.end());

    while (result.size() < 4)
    {
        result.push_back('0');
    }
    if (result.size() > 4)
    {
        result.resize(4);
    }
    
    
    std::cout << result << std::endl;
    return 0;
}
