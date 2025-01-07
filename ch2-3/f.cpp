
/*Вычислите сумму цифр неотрицательного целого числа.

Формат ввода
На вход подаётся одно неотрицательное целое число, не превосходящее 
10^9

Формат вывода
Выведите сумму цифр этого числа.*/

#include <iostream>

int main()
{
    unsigned long long value, result=0;
    std::cin >> value;
    
    while (value)
    {
        /* code */
        result += value % 10;
        value /= 10;
    }
    std:: cout << result;
    return 0;
}

