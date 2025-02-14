/*
Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.

Формат ввода
Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126, длина строки не превосходит 100.

Формат вывода
Напечатайте строки в отсортированном по убыванию порядке. 
Для сравнения строк друг с другом достаточно использовать стандартные операторы сравнения, определённые для std::string.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<std::string> lines;
    std::string input;
    while (std::getline(std::cin, input))
    {
        /* code */
        if (input.empty())
        {
            /* code */
            break;
        }
        lines.push_back(input);
    }

    std::sort(lines.rbegin(), lines.rend());

    for (size_t i = 0; i != lines.size(); ++i)
    {
        /* code */
        std::cout << lines[i] << std::endl;
    }
    
    return 0;
}

