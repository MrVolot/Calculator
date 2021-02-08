#include "Calculator.h"

void Calculator::fill(std::vector<double> numString, std::vector<char> symbolString) {
	for (const auto& num : numString) {
		stor.pushNumber(num);
	}
	for (const auto& symbol : symbolString) {
		stor.pushSymbol(symbol);
	}
}
//50/300*(3+4*5)*10
double Calculator::calculate() {
	std::stack<double> tmpNum;
	std::stack<char> tmpSym;
	while (!stor.isEmptySymbols()) {
		auto tmpSymbolOne{ stor.popSymbol() };
		auto tmpSymbolTwo{ stor.popSymbol() };
		if (checkPriority(tmpSymbolOne) <= checkPriority(tmpSymbolTwo)) {
			if(tmpSymbolTwo!='@')
				stor.pushSymbol(tmpSymbolTwo);
			auto tmpNumberOne{ stor.popNumber() };
			auto tmpNumberTwo{ stor.popNumber() };
			stor.pushNumber(count(tmpNumberOne, tmpNumberTwo, tmpSymbolOne));
		}
		else {
			auto tmpNumberOne{ stor.popNumber() };
			auto tmpNumberTwo{ stor.popNumber() };
			auto tmpNumberThree{ stor.popNumber() };
			stor.pushNumber(count(tmpNumberTwo, tmpNumberThree, tmpSymbolTwo));
			stor.pushNumber(tmpNumberOne);
			stor.pushSymbol(tmpSymbolOne);
		}
	}
	result = stor.popNumber();
	return result;
}

int Calculator::checkPriority(char symbol) {
	switch (symbol) {
	case '/' :
		return 1;
	case '*':
		return 2;
	case '+':
		return 3;
	case '-':
		return 3;
	case '@':
		return 100;
	}
}

double Calculator::count(double first, double second, char symbol) {
	switch (symbol) {
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		return first / second;
	}
}
