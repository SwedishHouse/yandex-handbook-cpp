
/*
Пароль от некоторого сервиса должен удовлетворять таким ограничениям:

состоять из символов таблицы ASCII с кодами от 33 до 126;
быть не короче 8 символов и не длиннее 14;
из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле должны присутствовать не менее трёх любых.
Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.
*/

#include <iostream>
#include <string>

int main()
{

    std::string password;
    bool is_small_letter = false, is_big_letters = false, is_digits = false, is_other_symbols = false;
    unsigned short type_counter = 0;
    std::getline(std::cin, password);

    // Check for correct length
    if (password.size() < 8 || password.size() > 14)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    // Check for correct ASCII symbol
    for (size_t i = 0; i < password.size(); i++)
    {
        /* code */
        if (static_cast<int>(password[i]) < 33 || static_cast<int>(password[i]) > 126)
        {
            /* code */
            std::cout << "NO" << std::endl;
            return 0;
        }
        else
        {
            if (static_cast<int>(password[i]) > 0x2F && static_cast<int>(password[i]) < 0x3A)
            {
                is_digits = true;
            }
            else if (static_cast<int>(password[i]) > 0x40 && static_cast<int>(password[i]) < 0x5B)
            {
                is_big_letters = true;
            }
            else if (static_cast<int>(password[i]) > 0x60 && static_cast<int>(password[i]) < 0x7B)
            {
                is_small_letter = true;
            }
            else
            {
                is_other_symbols = true;
            }
        }
        
    }

    type_counter = static_cast<short>(is_big_letters) + static_cast<short>(is_small_letter) + static_cast<short>(is_digits) + static_cast<short>(is_other_symbols);
    
    if (type_counter < 3)
    {
        std::cout << "NO" << std::endl;
    }
    else
    {
        std::cout << "YES" << std::endl;
    }
    

    return 0;
}
