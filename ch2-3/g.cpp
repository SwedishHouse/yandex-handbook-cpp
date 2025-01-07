/*
вывести сумму первых слагаемых натурального логарифма
*/

#include <iostream>
#include <cmath>

int main()
{
    double result = 0;
    int n;
    std::cin >> n;
    while (n)
    {
        result += static_cast<double>(std::pow(-1, n + 1))/(n);
        n--;
    }
    std:: cout << result;
    
    return 0;
}