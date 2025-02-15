/*
Вам необходимо построить поле для игры «Сапёр» по его конфигурации — высоте, ширине и координатам расставленных на нем мин.

Вкратце напомним правила построения поля для игры «Сапёр»:

поле состоит из клеток с минами и пустых клеток;
клетки с миной обозначаются символом *;
пустые клетки содержат число от 0 до 8 — количество мин на соседних клетках.
Формат ввода
В первой строке содержатся три числа:

число m от 1 до 100 — количество строк на поле;
число n от 1 до 100 — количество столбцов на поле;
число k от 0 до mn, mn — количество мин на поле.
В следующих k строках содержатся пары чисел с координатами мин (номерами строки и столбца). Нумерация ведётся с единицы.
*/

#include <iostream>
#include <vector>

int main()
{
    size_t n, m, k;
    int row_coord, col_coord, count_of_mines;
    std::cin >> m >> n >> k;

    std::vector<std:: vector<char>> field(m, std::vector<char>(n));
    // load mines
    for (size_t i = 0; i != k; ++i)
    {
        /* code */
        std::cin >> row_coord >> col_coord;
        field[row_coord - 1][col_coord - 1] = '*';
    }

    // Count mines
    size_t start_row, start_col, end_row, end_col;
    for (size_t i = 0; i != field.size(); ++i)
    {
        start_row = i > 0 ? i - 1: i;
        end_row = i < field.size() - 1 ? i + 1 : i;
        /* code */
        for (size_t j = 0; j != field[i].size(); ++j)
        {
            /* code */
            if (field[i][j] == '*')
            {
                /* code */
                continue;
            }
            
            count_of_mines = 0;
            start_col = j > 0 ? j - 1: j;
            end_col = j < field[i].size() - 1 ? j + 1 : j;
            for (size_t row = start_row; row <= end_row; ++row) // start counting
            {
                /* code */
                for (size_t col = start_col; col <= end_col; ++col)
                {
                    /* code */
                    if ((row == i && col == j) || field[row][col] != '*')
                    {
                        /* code */
                        continue;
                    }
                    if (field[row][col] == '*')
                    {
                        /* code */
                        count_of_mines++;
                    }
                    
                    
                }
                
            }//end counting
            
            field[i][j] = static_cast<char>(static_cast<int>('0') + count_of_mines);
        }
        
    }

    // output field
    for (size_t i = 0; i != field.size(); ++i)
    {
        /* code */
        for (size_t j = 0; j != field[i].size(); ++j)
        {
            /* code */
            std::cout << field[i][j];
            if(j == field[i].size() - 1)
            {
                std::cout << '\n';
            }
            else
            {
                std::cout << ' ';
            }
        }
        
    }
    
    

    return 0;
}