#include "Storage.h"

void Storage::pushNumber(double num) {
	numbers.push(num);
}

void Storage::pushSymbol(char sym) {
	symbols.push(sym);
}

double Storage::popNumber() {
	auto tmp{numbers.top()};
	 numbers.pop();
	 return tmp;
}

char Storage::popSymbol() {
	if (symbols.empty())
		return '@';
	auto tmp{ symbols.top() };
	symbols.pop();
	return tmp;
}

bool Storage::isEmptyNumbers() {
	return numbers.empty();
}

bool Storage::isEmptySymbols() {
	return symbols.empty();
}