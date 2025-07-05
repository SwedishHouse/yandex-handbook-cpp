#include "basics.h"

#include <iostream>
#include <string>


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