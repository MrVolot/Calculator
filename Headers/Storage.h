#pragma once
#include <stack>

class Storage {
	std::stack<double> numbers;
	std::stack<char> symbols;
public:
	void pushNumber(double num);
	void pushSymbol(char sym);
	double popNumber();
	char popSymbol();
	bool isEmptyNumbers();
	bool isEmptySymbols();
};