#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>  // ��� std::istringstream
#include <list>
#include <utility>
#include <unordered_map>
#include <iterator>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>

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
		//������� ���������� ���� �� �������� ������������� �������� � �������.
		// ���� ������������ ��������� ���������, �� ���������� ���������� ����� ����.
		std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

		//�������� ������� ��� ���������� ����������� ������ �������� �����, ���������� � ������� words:
		std::string CommonPrefix(const std::vector<std::string>& words);

		//������� ������ ������� ������ �����, ���������� ���������� ������ str �� ����� �� ���������� �������-����������� delimiter.
		// ���� ����������� ���������� � ������ ��� � ����� ������ str, �� � ������ (��������������, � �����) ������� � ����������� ������ ���� ������ ������.
		// ���� ��� ����������� ����������� �����, �� ������ ������ ����� ���� ���� ������ ������� � �����.
		// ��� ������ ������ ���� ������� ������, ���������� ���� ������ ������.
		//��������, Split("What_is_your_name?", '_') ������ ������� ������ �� ����� What, is, your � name ? .
		std::vector<std::string> Split(const std::string& str, char delimiter);

		//������� ������ ������� ������, ���������� �������� ��������� ������� ����� ��������� �����������. 
		// ��������, Join({"What", "is", "your", "name?"}, '_') ������ ������� ������ "What_is_your_name?".
		std::string Join(const std::vector<std::string>& tokens, char delimiter);

		// �������� �������, ������� ���������� ����������������� �������:
		std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

		//��� ���� ���������� ����� �� ���������.
		// �������� ��� ����� � ������� ����������� ���������� �� ������ ���������.
		//������ �����
		// ������� ������ ���������� ����� n.����� ���� ������������������ �� n �����, 
		// ������ �� ������� �������� ��� ����� ����� � ���������� �����.
		// ��������	n �� ����������� 100. ���������� ����� �� ������ �� ����������� 1000.
		void F(std::vector<std::pair<int, int>>& coords);
	};
};

namespace HandbookSTL
{

	class SequenceContainers
	{
	public:
		// ��������� Print
		// ������� Print, ������� ����� �������� � ����� std::cout �������� 
		// ����������� ���������� ����� ��������� ������ - �����������
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

		// �������� �����
		std::vector<std::string> B(const std::vector <std::pair<std::string,
			std::string>> &students, const std::vector<int>& numbers);
		// ������
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
		// �� ���� ������� ������������������ ����� �����. 
		// ��� ������� ����� �������� � ��������� ������ ����� YES,
		// ���� ��� ����� ����� ����������� � ������������������,
		// � NO, ���� �� �����������.
		std::vector<std::string> A(const std::vector<int>& arr);

		// ��� ���� �����. �������� � ���������� ������� ������ ����� ���� ���� ����.
		std::string B(const std::vector<std::string>& words);

		//��� ������ ���� ������ � ��������� �������� �������.
		// ���������� ������� ��� �������� ���������� ���� �������� ������� � ������������������ �������.
		std::set<std::string> C(const std::vector<std::string> &pathes);

		// ��������� ������� ������� ����� � �������� ��� �� ���������� ���������.
		// ��� ������ �������� ����, ��� ������� �� ������� ������� ��������, �� ������� ��� ����� �����������.
		// ������ ��������� ����� ��� ������ �������� �������� � ���������� ������� ��� �������� �����, 
		// ������� �� ��� �������� ������ (���� ����� ������ ����). 
		// �������� ���������� ������ ��� ������.
		std::map<int, std::set<std::string>> D(const std::vector< std::pair<int, std::string>>& input);

		// ����� �������� ���������� n - ������� ������������������ �� n ��������������� ������ �������� � ����� ����� � ������.
		// ��� ������� ����� n ����������� ��������� ���������� ������ n - ������ � ������.
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
		}
	};

};
