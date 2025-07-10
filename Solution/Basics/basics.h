#pragma once
#include <string>
#include <vector>
#include <algorithm>

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