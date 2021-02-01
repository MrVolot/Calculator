#pragma once
#include <string>
#include <vector>
#include <iostream>

class Parser {
	std::vector<double> numbers_;
	std::vector<char> symbols_;
	std::string text_;
	bool isSymbol(char key);
	bool isDigit(char num);
public:
	Parser() = delete;
	Parser(std::string text_);
	bool checkIfCorrect();
	void parseString();
	void print() {
		for (const auto& x : numbers_) {
			std::cout << x << " ";
		}
		std::cout<<std::endl;
		for (const auto& x : symbols_) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	std::vector<double> numbers();
	std::vector<char> symbols();
};