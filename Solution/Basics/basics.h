#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>  // Для std::istringstream

class Basics
{
	

};

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
	std::string a(int, int, int, int );
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
	void F(std::vector<std::pair<int, int>> &coords);
};

namespace HandbookSTL
{

	class SequenceContainers
	{
	public:
		template <typename T>
		void Print(const T& data, const std::string delimiter);
		// Проверка работ
		std::vector<std::string> B(const std::vector <std::pair<std::string, std::string>> &students, const std::vector<int>& numbers);
		// Вагоны
		void MakeTrain();
	};

	template<typename T>
	inline void SequenceContainers::Print(const T& data, const std::string delimiter)
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
	}

};
