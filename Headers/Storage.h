#pragma once
#include <stack>
#include "Stack.h"

class Storage {
	Stack<double> numbers;
	Stack<char> symbols;
public:
	void pushNumber(double num);
	void pushSymbol(char sym);
	double popNumber();
	char popSymbol();
	bool isEmptyNumbers();
	bool isEmptySymbols();
};