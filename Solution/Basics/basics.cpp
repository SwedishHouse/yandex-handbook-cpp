#include "basics.h"

#include <iostream>
#include <iomanip> // Äëÿ std::setw



void FirstSteps::a()
{
	std::string s = "C++ is a general-purpose programming language with a bias towards systems programming that\n  - is a better C\n  - supports data abstraction\n  - supports object-oriented programming\n  - supports generic programming.";

	std::cout << s << std::endl;
}

void FirstSteps::b(int a, int b)
{
	std::cout << a + b << std::endl;
}

double DataTypes::a(double cent)
{
	return  cent / 2.54;
}

unsigned long long int DataTypes::b(unsigned long long int n)
{
	return n * (n + 1) / 2;
}

bool BranchesAndCycles::is_a_leap_year(int year)
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

std::string BranchesAndCycles::a(int col1, int row1, int col2, int row2)
{
    if (row1 == row2 || col1 == col2 || std::abs(col2 - col1) == std::abs(row2 - row1))
       return "YES";
    else
        return "NO";
}

std::string BranchesAndCycles::b(int num1, int num2, int num3)
{
    if (num1 + num2 <= num3 ||
        num2 + num3 <= num1 ||
        num3 + num1 <= num2)
        return "UNDEFINED";
    else {
        if (num1 * num1 + num2 * num2 == num3 * num3 ||
            num1 * num1 + num3 * num3 == num2 * num2 ||
            num3 * num3 + num2 * num2 == num1 * num1)
            return "YES";
        else
            return "NO";

    }
}

std::string BranchesAndCycles::c(int year)
{
    if (year % 400 == 0)
        return "YES" ;
    else if (year % 100 == 0)
        return "NO";
    else if (year % 4 == 0)
        return "YES";
    else
        return "NO" ;
}

int BranchesAndCycles::d(int month, int year)
{
    if (month < 7)
    {
        if (month % 2)
            return 31;
        else if (month != 2)
            return 30;
        else if (is_a_leap_year(year))
            return 29;
        else
            return 28;
    }
    else
    {
        if (month == 9 || month == 11)
            return 30;
        else
            return 31;
    }
}

void BranchesAndCycles::e(int weekday, int amount_days)
{
    int counter = 0, position = 1;
    for (int i = 1; i < weekday; i++)
    {
        /* code */
        std::cout /*<< std::setw(2) << std::right */ << "   ";
        position++;
    }

    // std::cout.setf(std::ios::)
    while (amount_days != counter)
    {
        std::cout << std::setw(2) << std::right << ++counter << " ";
        if ((position) % 7 == 0)
        {
            std::cout << std::endl;
        }
        position++;
    }
}

int BranchesAndCycles::f(int value)
{
	unsigned int result = 0;
    while (value)
    {
        /* code */
        result += value % 10;
        value /= 10;
    }
	return result;
}

double BranchesAndCycles::g(int n)
{
    double result = 0;
    while (n)
    {
        result += static_cast<double>(std::pow(-1, n + 1)) / (n);
        n--;
    }
	return result;
}

std::string VectorsAndStrings::a(const std::string& password)
{
    bool is_small_letter = false, is_big_letters = false, is_digits = false, is_other_symbols = false;
    unsigned short type_counter = 0;

    // Check for correct length
    if (password.size() < 8 || password.size() > 14)
    {
        return "NO";
    }

    // Check for correct ASCII symbol
    for (size_t i = 0; i < password.size(); i++)
    {
        if (static_cast<int>(password[i]) < 33 ||
            static_cast<int>(password[i]) > 126)
            return "NO";

        if (static_cast<int>(password[i]) > 0x2F &&
            static_cast<int>(password[i]) < 0x3A)
            is_digits = true;
        else if (static_cast<int>(password[i]) > 0x40 &&
            static_cast<int>(password[i]) < 0x5B)
            is_big_letters = true;
        else if (static_cast<int>(password[i]) > 0x60 &&
            static_cast<int>(password[i]) < 0x7B)
            is_small_letter = true;
        else
            is_other_symbols = true;

        type_counter = static_cast<short>(is_big_letters) + static_cast<short>(is_small_letter) +
            static_cast<short>(is_digits) + static_cast<short>(is_other_symbols);
    }

    if (type_counter < 3)
        return "NO";
    else
        return "YES";
}

std::string VectorsAndStrings::b(const std::string& word)
{
    const std::vector<std::vector<char>> letters = { {'b', 'f', 'p', 'v'},
                                                {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'},
                                                {'d', 't'},
                                                {'l'},
                                                {'m', 'n'},
                                                {'r'} };
    const std::vector<char> charactersToRemove = { 'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y' };
    
    std::string result;
    result.push_back(word[0]);

    // Remove characters
    for (size_t i = 1; i != word.size(); ++i)
    {
        if (std::find(charactersToRemove.begin(), charactersToRemove.end(), word[i]) != charactersToRemove.end())
            continue;
        else
            result.push_back(word[i]);
    }

    for (size_t i = 1; i != result.size(); ++i)
    {
        for (size_t j = 0; j != letters.size(); ++j)
        {
            /* code */
            if (std::find(letters[j].begin(), letters[j].end(), result[i]) != letters[j].end())
            {
                result[i] = (static_cast<char>(static_cast<int>('0') + j + 1));
                break;
            }
        }// end for j
    }// end for i

    auto new_word = std::unique(result.begin(), result.end());
    result.erase(new_word, result.end());

    while (result.size() < 4)
        result.push_back('0');
    
    if (result.size() > 4)
        result.resize(4);
    return result;
}

std::vector<unsigned int> VectorsAndStrings::c(const std::vector<unsigned int>& input_places)
{
    std::vector<unsigned int>  result(input_places.size());

    for (size_t i = 0; i != result.size(); ++i)
        result[input_places[i] - 1] = i + 1;

    return result;
}

std::vector<std::string> VectorsAndStrings::d(std::vector<std::string>& lines)
{
    std::sort(lines.rbegin(), lines.rend());
    return lines;
}

const std::string VectorsAndStrings::e(const std::string& line)
{
	const std::string yes = "YES", no = "NO";
    
    if (line.empty())
        return no;

    int left = 0, right = line.size() - 1;

    while (right - left > 0)
    {
        while (line[left] == ' ')
            left++;

        while (line[right] == ' ')
            right--;

        if (line[left++] != line[right--])
			return no;
    }
    
    return yes;
}

const std::string VectorsAndStrings::f(size_t n, size_t m, size_t k, const std::vector<std::vector<int>>& input)
{
    //int row_coord, col_coord;

    std::vector<std::vector<char>> field(m, std::vector<char>(n));
    // load mines
    for (size_t i = 0; i != k; ++i)
        field[input[k][0] - 1][input[k][1] - 1] = '*';

    // Count mines
    for (size_t i = 0; i != field.size(); ++i)
    {
        size_t start_row = i > 0 ? i - 1 : i;
        size_t end_row = i < field.size() - 1 ? i + 1 : i;

        for (size_t j = 0; j != field[i].size(); ++j)
        {
            if (field[i][j] == '*')
                continue;

            unsigned int count_of_mines = 0;
            size_t start_col = j > 0 ? j - 1 : j;
            size_t end_col = j < field[i].size() - 1 ? j + 1 : j;
            for (size_t row = start_row; row <= end_row; ++row) // start counting
            {
                for (size_t col = start_col; col <= end_col; ++col)
                {
                    if ((row == i && col == j) ||
                        field[row][col] != '*')
                        continue;

                    if (field[row][col] == '*')
                        count_of_mines++;
                }
            }//end counting
            field[i][j] = static_cast<char>(static_cast<int>('0') + count_of_mines);
        }
    }
	std::vector<char> result;
    // output field
    for (size_t i = 0; i != field.size(); ++i)
    {
        for (size_t j = 0; j != field[i].size(); ++j)
        {
            result.push_back(field[i][j]);
			result.push_back(' ');
        }
		result.push_back('\n');
    }
    return std::string(result.begin(), result.end());
}
