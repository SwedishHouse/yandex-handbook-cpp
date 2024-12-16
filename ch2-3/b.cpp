#include <iostream>

int main()
{
    unsigned int num1 , num2, num3;
    std::cin >> num1 >> num2 >> num3;

    if(num1 + num2 <= num3 || num2 + num3 <= num1 || num3 + num1 <= num2)
    {
        std::cout << "UNDEFINED" <<std::endl; 
    } else {
        if (num1 * num1 + num2 * num2 == num3 * num3 || num1 * num1 + num3 * num3 == num2 * num2 || num3 * num3 + num2 * num2 == num1 * num1)
        {
           std::cout << "YES" << std::endl;
        }else
        {
            std::cout << "NO" << std::endl;
        }
        
    }
    return 0;
}
