#include <iostream>

bool is_a_leap_year(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
     else if (year % 4 == 0)
        return true;
    else 
        return false;
}

int main(void)
{
    unsigned int month, year;

    std:: cin >> month >> year;

    if(month < 7)
    {
        if(month % 2)
            std::cout << "31" << std::endl;
        else if(month != 2)
             std::cout << "30" << std::endl;
        else if(is_a_leap_year(year))
            std::cout << "29" << std::endl;
        else
            std::cout << "28" << std::endl;
    }
    else
    {
        if(month == 9 || month == 11)
            std::cout << "30" << std::endl;
        else
            std::cout << "31" << std::endl;
    }
    return 0;
}

