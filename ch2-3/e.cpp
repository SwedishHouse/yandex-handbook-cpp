/*
Напечатайте месяц из календаря по заданному начальному дню и количеству дней. Ваш ответ должен выглядеть примерно так:

                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31
Формат ввода
Вводится два числа: n — номер дня недели первого числа месяца (целое число от 1 до 7) и k — количество дней в этом месяце (целое число от 1 до 99). 
n≤k.Обратите внимание, что число дней в месяце не обязательно должно быть таким же, как в привычном календаре.
*/

#include <iostream>
#include <iomanip> // Для std::setw

int main()
{
    unsigned short weekday;
    unsigned int amount_days, counter = 0, position = 1;

    std::cin >> weekday >> amount_days;

    for (int i = 1; i < weekday; i++)
    {
        /* code */
        std::cout << "   ";
        position++;
    }

    while (amount_days != counter)
    {   
        std::cout << std::setw(2) << std::right << ++counter << " ";
        if((position) % 7 == 0)
        {
            std::cout << std::endl;
        }
        position++;
    }
    
    

    return 0;
}