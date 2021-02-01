#pragma once
#include <iostream>
#include "Storage.h"
#include <vector>

class Calculator {
	Storage stor;
	double result{};
	int checkPriority(char symbol);
	double count(double first, double second, char symbol);
public:
	void fill(std::vector<double> numString, std::vector<char> symbolString);
	void print() {
		while (!stor.isEmptyNumbers()) {
			std::cout << stor.popNumber()<<" ";
		}
		std::cout << std::endl;
		while (!stor.isEmptySymbols()) {
			std::cout << stor.popSymbol() << " ";
		}
		std::cout << std::endl;
	}
	double calculate();
};