#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

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
	void F(std::vector<std::pair<int, int>> &coords);
};

namespace HandbookSTL
{

	class SequenceContainers
	{
	public:
		template <typename T>
		void Print(const T& data, const std::string delimiter);
		// �������� �����
		std::vector<std::string> B(const std::vector <std::pair<std::string, std::string>> &students, const std::vector<int>& numbers);

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
