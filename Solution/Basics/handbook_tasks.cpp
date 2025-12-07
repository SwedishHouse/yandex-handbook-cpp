#include "handbook_tasks.h"
#include <map>
#include <set>
#include <iomanip> // Для std::setw
#include <numeric> // Для std::accumulate
#include <queue>
#include <string_view>



void Basics::FirstSteps::a()
{
	std::string s = "C++ is a general-purpose programming language with a bias towards systems programming that\n  - is a better C\n  - supports data abstraction\n  - supports object-oriented programming\n  - supports generic programming.";

	std::cout << s << std::endl;
}

void Basics::FirstSteps::b(int a, int b)
{
	std::cout << a + b << std::endl;
}

double Basics::DataTypes::a(double cent)
{
	return  cent / 2.54;
}

unsigned long long int Basics::DataTypes::b(unsigned long long int n)
{
	return n * (n + 1) / 2;
}

bool Basics::BranchesAndCycles::is_a_leap_year(int year)
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

std::string Basics::BranchesAndCycles::a(int col1, int row1, int col2, int row2)
{
    if (row1 == row2 || col1 == col2 || std::abs(col2 - col1) == std::abs(row2 - row1))
       return "YES";
    else
        return "NO";
}

std::string Basics::BranchesAndCycles::b(int num1, int num2, int num3)
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

std::string Basics::BranchesAndCycles::c(int year)
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

int Basics::BranchesAndCycles::d(int month, int year)
{
    if (month < 7)
    {
        if (month % 2)
            return 31;
        else if (month != 2)
            return 30;
        else if (Basics::BranchesAndCycles::is_a_leap_year(year))
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

void Basics::BranchesAndCycles::e(int weekday, int amount_days)
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

int Basics::BranchesAndCycles::f(int value)
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

double Basics::BranchesAndCycles::g(int n)
{
    double result = 0;
    while (n)
    {
        result += static_cast<double>(std::pow(-1, n + 1)) / (n);
        n--;
    }
	return result;
}

std::string Basics::VectorsAndStrings::a(const std::string& password)
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

std::string Basics::VectorsAndStrings::b(const std::string& word)
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

std::vector<unsigned int> Basics::VectorsAndStrings::c(const std::vector<unsigned int>& input_places)
{
    std::vector<unsigned int>  result(input_places.size());

    for (size_t i = 0; i != result.size(); ++i)
        result[input_places[i] - 1] = i + 1;

    return result;
}

std::vector<std::string> Basics::VectorsAndStrings::d(std::vector<std::string>& lines)
{
    std::sort(lines.rbegin(), lines.rend());
    return lines;
}

const std::string Basics::VectorsAndStrings::e(const std::string& line)
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

std::string Basics::VectorsAndStrings::f(size_t n, size_t m, size_t k, const std::vector<std::vector<unsigned int>>& input)
{
    //int row_coord, col_coord;

    std::vector<std::vector<char>> field(n, std::vector<char>(m));
    // load mines
    for (size_t i = 0; i != k; ++i)
        field[input[i][0] - 1][input[i][1] - 1] = '*';

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
    for (size_t i = 0; i < field.size(); ++i)
    {
        for (size_t j = 0; j < field[i].size() - 1; ++j)
        {
            result.push_back(field[i][j]);
			result.push_back(' ');
        }
        result.push_back(field[i][field[i].size() - 1]);
		result.push_back('\n');
    }
    return std::string(result.begin(), result.end());
}

std::pair<size_t, size_t> Basics::Functions::MatrixArgMax(const std::vector<std::vector<int>>& matrix)
{
    std::pair<size_t, size_t> result = { 0, 0 };
    size_t counter = 0;
    int max_value = -2147483647;

    // Find Max value
    for (size_t i = 0; i != matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] > max_value)
            {
                max_value = matrix[i][j];

            }
        }
    }

    // find count of max values and save indexes
    for (size_t i = 0; i != matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == max_value)
            {
                result = { i, j };
                counter++;
            }
        }
    }

    if (counter > 1)
    {
        for (size_t i = 0; i != matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[i].size(); ++j)
                if (matrix[i][j] == max_value && 
                    std::pair<size_t, size_t>(i , j) < result)
                    result = std::pair<size_t, size_t>(i, j);
        }
    }

    return result;
}

std::string Basics::Functions::CommonPrefix(const std::vector<std::string>& words)
{
    const std::string answer = "";

    if (words.empty())
        return answer;

    size_t max_length = UINT32_MAX;

    // проверим, есть ли пустые строки 
    for (const auto& var : words)
    {
        if (var.empty()) return answer;
        if (var.size() < max_length) max_length = var.size();
    }

    // Здесь все строки не пустые
    size_t index = 0;
    char current_sym = words[0][index];
    bool is_stopped = false;

    while (index < max_length && !is_stopped)
    {
        for (const auto& var : words)
        {
            if (current_sym != var[index])
            {
                is_stopped = true;
                break;
            }
        }
        if (!is_stopped)
            current_sym = words[0][++index];
        else
            break;
    }

    return std::string(words[0].begin(), words[0].begin() + index);
}

std::vector<std::string> Basics::Functions::Split(const std::string& str, char delimiter)
{
    std::vector<std::string> res;
    std::string::const_iterator left = str.cbegin();
    
    for(std::string::const_iterator right = str.cbegin(); right != str.cend(); ++right)
    {
        if(*right == delimiter)
        {
            res.push_back(std::string(left, right));
            left = right + 1;
        }
    }
    res.push_back(std::string(left, str.cend()));
    return res;
}

std::string Basics::Functions::Join(const std::vector<std::string>& tokens, char delimiter)
{
    std::string res = "";

    if (tokens.empty())
        return res;
    
    std::vector<std::string>::const_iterator it = tokens.cbegin();

    res += *it;
    it++;
    while (it != tokens.cend())
    {
        res.push_back(delimiter);
        res += *it;
        it++;
    }

    return res;
}

std::vector<std::vector<int>> Basics::Functions::Transpose(const std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>> res(matrix[0].size(), std::vector<int>(matrix.size()));
    for (size_t i = 0; i < res.size(); ++i)
    {
        for(size_t j = 0; j < res[0].size(); ++j)
        {
            res[i][j] = matrix[j][i];
        }
    }

    return res;
}

void Basics::Functions::F(std::vector<std::pair<int, int>> &coords)
{
    std::sort(coords.begin(), coords.end(), [](const std::pair<int, int> lhs, const std::pair<int, int> rhs){
        return (lhs.first * lhs.first) + (lhs.second * lhs.second) < (rhs.first * rhs.first) + (rhs.second * rhs.second);
        });
}

std::vector<std::string> HandbookSTL::SequenceContainers::
B(const std::vector <std::pair<std::string, std::string>>& students,
    const std::vector<int>& numbers)
{
    std::deque<std::string> students_deque;
    for (const auto &student_record : students)
    {
        if (student_record.second == "top")
            students_deque.push_front(student_record.first);
        else
            students_deque.push_back(student_record.first);
    }

    std::vector<std::string> result(numbers.size());

    for (size_t i = 0; i != result.size(); ++i)
        result[i] = students_deque[numbers[i] - 1];

    return result;
}

void HandbookSTL::SequenceContainers::MakeTrain()
{
    std::string input_val;
    std::deque<int> train;
    
    while (std::cin >> input_val) {

        std::string action = input_val;
        int number;

        std::cin >> number;

        switch (action[0])
        {
        case '+':
            if (action.substr(1) == "left")
                train.push_front(number);
            else
                train.push_back(number);
            break;

        case '-':
            if (action.substr(1) == "left")
            {
                while (!train.empty() && number > 0)
                {
                    train.pop_front();
                    number--;
                }
                    
            }
            else
            {
                while (!train.empty() && number > 0)
                {
                    train.pop_back();
                    number--;
                }
            }
            break;

        default:
            break;
        }
    }

    for (const auto & val : train)
        std::cout << val << " ";

    std::cout << std::endl;
}

std::list<std::string> HandbookSTL::SequenceContainers::CtrlXV(const std::vector<std::string>& text,
    const std::vector<std::string> &commands)
{
    // Результат после обработки команд 
    std::list<std::string> text_to_edit;

    // Заполним 
    for(const auto &val : text)
        text_to_edit.push_back(val);

    std::string buffer;

    auto it = text_to_edit.begin();

    for (const auto &command : commands)
    {
        if (command == "Down")
        {
            if (it == text_to_edit.end())
                continue;

            it++;
        }
        else if (command == "Up")
        {
            if (it == text_to_edit.begin())
                continue;
            it--;
        }
        else if (command == "Ctrl+X")
        {
            if (it == text_to_edit.end())
                continue;

            buffer = std::move(*it);
            it = text_to_edit.erase(it);
        }
        else if (command == "Ctrl+V")
        {
            if (buffer.empty())
                continue;

            text_to_edit.insert(it, buffer);
        }
        else
        {
            assert(command == "Ctrl+V", "No supported cmd");
        }
        
    }// end while

    return text_to_edit;
}

std::list<std::string> HandbookSTL::SequenceContainers::CtrlXV2(const std::vector<std::string>& text,
    const std::vector<std::string>& commands)
{
    // Инициализируем список с обработанным текстом
    std::list<std::string> edit_text;

    // Копируем исходный текст до пустой строки
    for(const auto &val: text)
    {
        if (val.empty())
            break;

        edit_text.push_back(val);
    }

    // Определяем список действий
    enum Actions_e
    {
        down,   // Курсор вниз
        up,     // Вверх
        cut,    // Вырезать и записать в буфер
        insert, // Вставить из буфера
        shift   // Выбрать несколько строк
    };

    // Ставим в соответствие командам действия
    const std::unordered_map<std::string, int> actions = { {"Down", down},
                                                        {"Up", up},
                                                        {"Ctrl+X", cut},
                                                        {"Ctrl+V", insert},
                                                        {"Shift", shift}
    };

    // Буфер
    std::list<std::string> buffer;

    // Начинаем прохождение по списку с начала
    auto cursor = edit_text.begin();

    // Переменная для сохранения позици, с которой выделение нескольких строк
    auto shift_position = edit_text.begin();

    // Флаг для определения, нажат ли Shift
    bool is_pressed = false;

    // Цикл по всем командам
    for(const auto &command : commands)
    {
        // Определяем текущую команду
        switch (actions.at(command))
        {
        case down:
            // Не можем выйти за предел текста
            if (cursor == edit_text.end())
                continue;

            // Инкрементируем позицию
            cursor = std::next(cursor);
            break;
        
        case up:
            // Не можем выйти за предел текста
            if (cursor == edit_text.begin())
                continue;

            // Декрементируем позицию
            cursor = std::prev(cursor);
            break;

        case cut:
        {
            // Операция приводит к перезаписи буфера
            buffer.clear();

            // 
            if (is_pressed)
            {
                // Помним про условме задачи:
                // Если курсор находится на строке n, то после операций Shift, Down, Down выделенными окажутся строки n и n + 1
                // Определяем начало и конец отрезка для вырезания и сохранения в буфер
                int distance = static_cast<int>(std::distance(shift_position, cursor)); 

                if (distance < 0)
                {
                    std::swap(shift_position, cursor);
                    distance = std::abs(distance);
                }

                while (shift_position != edit_text.end() && shift_position != cursor)
                {

                    buffer.push_back(std::move(*shift_position));
                    shift_position = edit_text.erase(shift_position);
                }

                cursor = shift_position;

                // Сброс флага
                is_pressed = false;

            }
            else
            {
                buffer.push_back(std::move(*cursor));
                cursor = edit_text.erase(cursor);
            }
            break;
        }

        case insert:
        {
            
            if (is_pressed)
            {
                // Помним про условме задачи:
                // Если курсор находится на строке n, то после операций Shift, Down, Down выделенными окажутся строки n и n + 1
                // Определяем начало и конец отрезка для вырезания и сохранения в буфер
                int distance = static_cast<int>(std::distance(shift_position, cursor));

                if (distance < 0)
                {
                    std::swap(shift_position, cursor);
                    distance = std::abs(distance);
                }
                while (shift_position != cursor)
                {
                    shift_position = edit_text.erase(shift_position);
                }

            }

            // Не может происходить вставки из пустого буфера
            //if (buffer.empty())
            //    continue;
            
            for (const auto& value : buffer)
                edit_text.insert(cursor, value);

            // Сброс флага
            is_pressed = false;

            break;
        }

        case shift:
            // Сохраняем текущее положение курсора
            shift_position = cursor;

            // Обновляем состояние флага
            is_pressed = true;

            break;
        default:
            break;
        }

    }// end while

    return edit_text;
}

std::vector<std::string> HandbookSTL::AssociationContainers::A(const std::vector<int>& arr)
{
    std::map<int, bool> keeper;
    std::vector<std::string> result;

    for (auto val : arr)
    {
        if (auto it = keeper.find(val); it != keeper.end())
        {
            result.push_back("YES");
        }
        else
        {
            keeper[val] = true;
            result.push_back("NO");
        }
            

    }
    return result;
}

std::string HandbookSTL::AssociationContainers::B(const std::vector<std::string>& words)
{
    const size_t COUNT = words.size();

    if(COUNT == 0)
        return "";

    std::map<char, int> letters;
    for (const auto& word : words)
    {
        const std::set<char> word_letter(word.cbegin(), word.cend());

        for (const auto letter : word_letter)
        {
            ++letters[letter];
        }

    }

    std::string result;

    for (const auto &[letter, freq] : letters)
    {
        if (freq == COUNT)
        {
            result.push_back(letter);
        }
    }
    std::sort(result.begin(), result.end());
    
    return result;
}

std::set<std::string> HandbookSTL::AssociationContainers::C(const std::vector<std::string>& pathes)
{
    std::set<std::string> directories;

    for (const auto & path : pathes)
    {
        for (size_t i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
                directories.insert(path.substr(0, i + 1));
        }
    }

    return directories;
}

std::map<int, std::set<std::string>> HandbookSTL::AssociationContainers::D(const std::vector<std::pair<int, std::string>>& input)
{
    std::map<int, std::set<std::string>> result;

    for (const auto& line : input)
    {
        int page = line.first;
        std::string word = line.second;
        result[page].insert(word);
    }

    return result;
}

std::vector<std::pair<std::string, int>> HandbookSTL::AssociationContainers::E(const std::vector<std::string>& words, const int gramm_length)
{
    std::unordered_map<std::string, int> freq;

    for (const std::string &word : words)
    {
        for (size_t i = gramm_length; i <= word.size(); i++)
        {
            ++freq[word.substr(i - gramm_length, gramm_length)];
        }
    }

    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());

    std::sort(sorted.begin(), sorted.end(), [](const auto& p1, const auto& p2) {
        return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
        });

    return sorted;
}

std::string HandbookSTL::Adapters::A(const std::string line)
{
    const std::string   line_wrong = "NO",
                        line_ok = "YES";
    if (line.empty())
        return line_wrong;


    std::stack<char> st;
    const static std::map<char, char> curves = { {'}', '{'}, {']', '['}, {')', '('} };

    for (auto sym : line)
    {
        if (curves.find(sym) != curves.end())
        {
            if (st.empty() || st.top() != curves.at(sym))
                return line_wrong;

            st.pop();
            continue;
        }

        bool is_find = false;
        for (const auto& [key, value] : curves)
        {
            is_find = value == sym;
            if (is_find)
            {
                st.push(sym);
                break;
            }
        }
        if (!is_find) return line_wrong;
    }

    return st.empty() ? line_ok : line_wrong;
}


std::vector<int> HandbookSTL::Adapters::B(const std::vector<int> &values, size_t k)
{

    std::vector<int> res;

    if (k == 0)
        return res;

    std::multiset<int> window;
    
    // Заполним окно
    for (size_t i = 1; i <= values.size(); ++i)
    {
        window.insert(values[i - 1]);
        if (i >= k)
        {
            res.push_back(*window.cbegin());
            auto it = window.find(values[i - k]);
            if(it != window.end())
                window.erase(it);
        }
    }

    return res;
}

std::string HandbookSTL::Adapters::C(const std::string line)
{
    static enum commands_e
    {
        CLEAR,
        ADD,
        EXTRACT
    };

    static const std::unordered_map<std::string, int> COMMADS = { {"CLEAR", CLEAR}, {"ADD", ADD}, {"EXTRACT", EXTRACT} };
    static std::priority_queue<int> pq;

    for (const auto& cmd : COMMADS)
    {
        // Ищем команду
        if (line.find(cmd.first) == std::string::npos)
            continue;

        // В цикле ее обработаем и выйдем
        switch (cmd.second)
        {
        case CLEAR:
            while (!pq.empty())
                pq.pop();
            break;

        case ADD:
        {
            int value = std::stoi(line.substr(cmd.first.size() + 1));

            pq.push(value);
        }
            
            break;

        case EXTRACT:
            if (pq.empty())
                return "CANNOT";

            {
                int value = pq.top();
                pq.pop();
                return std::to_string(value);
            }

            break;

        default:
            assert(false);
            break;
        }

        break; // for break
    }

    return std::string();
}

bool HandbookSTL::Adapters::NextToken(std::string_view& sv, const char del, std::string_view &out)
{
    if (sv.size() == 0) return false;

    size_t right = 0;

    while (right < sv.size() && sv[right] != del)
        right++;

    out = std::string_view(sv.begin(), sv.begin() + right);

    if (right != sv.size())
        right++;

    sv.remove_prefix(right);

    return true;
}
