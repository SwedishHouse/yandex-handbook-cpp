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
    std::string word;

    const std::vector<std::vector<char>> letters = {{'b', 'f', 'p', 'v'}, 
                                                {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'},
                                                {'d', 't'},
                                                {'l'},
                                                {'m', 'n'},
                                                {'r'}};
    const std::vector<char> charactersToRemove = {'a', 'e', 'h', 'i', 'o', 'u', 'w'};
    // std::cout << "Size: "<< letters.size() << std::endl;

    // std::getline(std::cin, word);
    std::cin >> word;
    // Remove characters
    for (size_t i = 1; i != word.size(); ++i)
    {
        /* code */
        if (std::find(charactersToRemove.begin(), charactersToRemove.end(), word[i]) != charactersToRemove.end())
        {
            /* code */
            word[i] = ' ';
        }
        
    }
    
    word.erase(std::remove(word.begin() + 1, word.end(), ' '), word.end());
    // replace characters on digits
    for (size_t i = 1; i != word.size(); ++i)
    {
        for (size_t j = 0; j != letters.size(); ++j)
        {
            /* code */
            if(std::find(letters[j].begin(), letters[j].end(), word[i]) != letters[j].end())
            {
                word[i] = static_cast<char>(static_cast<int>('0') + j + 1);
                break;
            }
        }// end for j
    }// end for i
    
    // Deleting consecutive characters 
    
    auto new_word = std::unique(word.begin(), word.end());
    word.erase(new_word, word.end());

    while (word.size() < 4)
    {
        word.push_back('0');
    }
    if (word.size() > 4)
    {
        word.resize(4);
    }
    
    
    
    std::cout << word << std::endl;
    return 0;
}
