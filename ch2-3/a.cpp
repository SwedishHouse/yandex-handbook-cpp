#include <iostream>
// #include <cmath>

int main()
{
    int col1, row1, col2, row2;

    std::cin >> col1;
    std::cin >> row1;
    std::cin >> col2;
    std::cin >> row2;
    if(row1 == row2 || col1 == col2 || std::abs(col2 - col1) == std::abs(row2 - row1))
    {
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
    }

    return 0;
}