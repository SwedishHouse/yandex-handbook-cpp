/*
На мероприятие приглашены n гостей. Им предлагают занять места с номерами от 1 до 
n в зале. Гости занимают эти места в произвольном порядке. Известно, на каком месте сел очередной гость.

Выпишите для каждого очередного места номер гостя, который на него сел.

Число n не превосходит 20000.
*/

#include <iostream>
#include <vector>

int main()
{
    unsigned int amount = 0;

    std::cin >> amount;

    std::vector<unsigned int> input_places, result;
    input_places.resize(amount + 1);
    result.resize(amount + 1);
    
    for (size_t i = 0; i != amount; ++i)
    {
        /* code */
        std::cin >> input_places[i];
    }

    for (size_t i = 0; i != amount; ++i)
    {
        result[input_places[i] - 1] = i + 1;
    }
    
    
    for (size_t i = 0; i != amount; ++i)
    {
        /* code */
        std::cout << result[i] << ' ';
    }

    return 0;
}
