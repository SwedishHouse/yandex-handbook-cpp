/*
Дана строка из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом без учета пробелов.

Формат ввода
На вход подается одна строка. В строке могут быть пробелы. Подряд может идти произвольное число пробелов. Длина строки не превосходит 100.

Формат вывода
Представьте, что из строки удалили все пробелы. Необходимо вывести YES, если полученная строка — палиндром, и NO в противном случае.
*/

#include <iostream>
#include <string>


int main()
{
    std::string line;
    std::getline(std::cin, line);

    int left = 0, right = line.size();
    bool result = true;
    if (line.empty())
    {
        /* code */
        result = true;
    }
    right--;
    while (right - left > 0)
    {
        /* code */
        if (line[left] == ' ')
        {
            /* code */
            left++;
            continue;
        }
        if (line[right] == ' ')
        {
            /* code */
            right--;
            continue;
        }
        if (line[left] == line[right])
        {
            /* code */
            left++;
            right--;
        }
        else{
            result = false;
            break;
        }
        
    }
    
    if (result)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    

    return 0;
}
