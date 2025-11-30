#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>  // Для std::istringstream
#include <list>
#include <utility>
#include <unordered_map>
#include <iterator>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>
#include <stdexcept>
#include <cassert>
#include <stack>


namespace Basics
{
	class FirstSteps
	{
	public:
		void a(void);
		void b(int a, int b);

	};

	class DataTypes
	{
	public:
		double a(double);
		unsigned long long int b(unsigned long long int);
	};

	class BranchesAndCycles
	{

	private:
		bool is_a_leap_year(int year);

	public:
		std::string a(int, int, int, int);
		std::string b(int, int, int);
		std::string c(int);
		int d(int, int);
		void e(int, int);
		int f(int);
		double g(int);

	};

	class VectorsAndStrings
	{
	public:
		std::string a(const std::string&);
		std::string b(const std::string&);
		std::vector<unsigned int> c(const std::vector<unsigned int>&);
		std::vector<std::string> d(std::vector<std::string>&);
		const std::string e(const std::string&);
		std::string f(size_t, size_t, size_t, const std::vector<std::vector<unsigned int>>&);
	};

	class Functions
	{
	public:
		//Функция возвращает пару из индексов максимального элемента в матрице.
		// Если максимальных элементов несколько, то возвращает наименьшую такую пару.
		std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

		//Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:
		std::string CommonPrefix(const std::vector<std::string>& words);

		//Функция должна вернуть вектор строк, полученный разбиением строки str на части по указанному символу-разделителю delimiter.
		// Если разделитель встретился в начале или в конце строки str, то в начале (соответственно, в конце) вектора с результатом должна быть пустая строка.
		// Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ.
		// Для пустой строки надо вернуть вектор, содержащий одну пустую строку.
		//Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your и name ? .
		std::vector<std::string> Split(const std::string& str, char delimiter);

		//Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель. 
		// Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".
		std::string Join(const std::vector<std::string>& tokens, char delimiter);

		// Напишите функцию, которая возвращает транспонированную матрицу:
		std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

		//Вам даны координаты точек на плоскости.
		// Выведите эти точки в порядке возрастания расстояний до начала координат.
		//Формат ввода
		// Сначала задано количество точек n.Затем идет последовательность из n строк, 
		// каждая из которых содержит два целых числа — координаты точки.
		// Величина	n не превосходит 100. Координаты точек по модулю не превосходят 1000.
		void F(std::vector<std::pair<int, int>>& coords);
	};
};

namespace HandbookSTL
{

	class SequenceContainers
	{
	public:
		// Шаблонный Print
		// функция Print, которая умеет печатать в поток std::cout элементы 
		// переданного контейнера через указанную строку - разделитель
		template<typename T>
		inline void Print(const T& data,
			const std::string delimiter)
		{
			auto iter = data.cbegin();

			std::cout << *iter;
			iter++;
			while (iter != data.cend())
			{
				std::cout << delimiter;
				std::cout << *iter;
				iter++;
			}
			std::cout << std::endl;
		};

		// Проверка работ
		std::vector<std::string> B(const std::vector <std::pair<std::string,
			std::string>> &students, const std::vector<int>& numbers);
		// Вагоны
		void MakeTrain();
		// Ctrl+X, Ctrl+V
		std::list<std::string> CtrlXV(const std::vector<std::string> &text, 
			const std::vector<std::string> &commands);
		// Ctrl+X, Ctrl+V - 2
		static std::list<std::string> CtrlXV2(const std::vector<std::string>& text,
			const std::vector<std::string>& commands);
	};

	class AssociationContainers
	{
	public:
		// На вход подаётся последовательность целых чисел. 
		// Для каждого числа выведите в отдельной строке слово YES,
		// если это число ранее встречалось в последовательности,
		// и NO, если не встречалось.
		std::vector<std::string> A(const std::vector<int>& arr);

		// Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.
		std::string B(const std::vector<std::string>& words);

		//Дан список всех файлов в некоторой файловой системе.
		// Необходимо вывести все непустые директории этой файловой системы в лексикографическом порядке.
		std::set<std::string> C(const std::vector<std::string> &pathes);

		// Профессор написал научную книгу и составил для неё предметный указатель.
		// Это список ключевых слов, для каждого из которых указана страница, на которой это слово встречается.
		// Теперь профессор хочет для каждой страницы выписать в алфавитном порядке все ключевые слова, 
		// которые на эту страницу попали (если такие вообще есть). 
		// Помогите профессору решить эту задачу.
		std::map<int, std::set<std::string>> D(const std::vector< std::pair<int, std::string>>& input);

		// Будем называть символьной n - граммой последовательность из n последовательно идущих символов в одном слове в тексте.
		// Для данного числа n подсчитайте суммарное количество каждой n - граммы в тексте.
		std::vector<std::pair<std::string, int>> E(const std::vector<std::string> &words, const int gramm_length);

	};

	class Algorithms
	{
	public:
		template <typename T>
		void Duplicate(std::vector<T>& v) {
			const size_t size = v.size();
			v.reserve(2 * size);
			auto start = v.cbegin();
			auto end = start + size;
			for (auto it = start; it != end; ++it) {
				v.push_back(*it);
			}
		};

		template <typename Iter>
		Iter Unique(Iter first, Iter last)
		{
			auto it1 = first, it2 = first;
			while (it2 != last)
			{
				if (it1 != it2)
					*it1 = std::move(*it2);
				
				++it1;

				const auto& value = *it2;
				while (it2 != last && *it2 == value)
					++it2;
 			}
			return it1;
		};

		// Реализуйте функцию SetDifference, которая принимает на вход два отсортированных по возрастанию диапазона
		template <typename InIter1, typename InIter2, typename OutIter>
		OutIter SetDifference(InIter1 first1, InIter1 last1,
			InIter2 first2, InIter2 last2,
			OutIter out)
		{
			while (first1 != last1)
			{
				if (first2 == last2)
				{
					*out = *first1;
					out++;
					first1++;
					continue;
				}
				
				if (*first1 < *first2)
				{
					// Данное значение точно есть в первом множестве
					*out = *first1;
					out++;
					first1++;	
					continue;
				}

				if (*first2 < *first1)
				{
					// Значения из второго множества точно нет в первом
					first2++;
					continue;
				}

				if (*first1 == *first2)				
				{
					// Данную пару не рассматриваем для записи
					first1++;
					first2++;
				}
			}
			return out;
		}

		// D: Приближённый двоичный поиск
		// В первой строке входных данных содержатся натуральные числа n и k,
		// не превосходящие 100000. Во второй строке задаются n целых чисел первого массива,
		// отсортированного по неубыванию, а в третьей строке – k целых чисел второго массива.
		// Каждое число в обоих массивах по модулю не превосходит 2⋅10^9. Второй массив,
		// в отличие от первого, не отсортирован.

		template <typename InIter>
		int D(InIter start, InIter end, int number)
		{
			// Защита от неправильный данных
			if (start == end)
				throw std::logic_error("Start equal end iterator!");

			auto it = std::lower_bound(start, end, number);

			if (it == end)
			{
				--it;
				return *it;
			}

			const int value_right = *it;

			while (it != end && it != start && *it == value_right)
				it--;

			const int value_left = *it;

			// Проверяем дистанцию до результатов
			if (value_right - number < number - value_left)
				return value_right;
			else
				return value_left;
		}
	};

	class Adapters
	{
	public:
		// На вход подаётся скобочная последовательность — строка, которая состоит из скобок ()[]{}.
		// Вам нужно определить, является ли она правильной. 
		// В правильной скобочной последовательности каждой открывающей скобке соответствует закрывающая и 
		// пары скобок корректно вложены друг в друга.
		std::string A(const std::string line);
		
	};

};
