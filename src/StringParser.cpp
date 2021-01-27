#include "StringParser.h"
#include <iostream>

bool Parser::isSymbol(char key) {
	switch (key) {
	case '+':
		return true;
	case '-':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	}
	return false;
}
bool Parser::isDigit(char num) {
	if (num >= '0' && num <= '9') {
		return true;
	}
	return false;
}
bool Parser::checkIfCorrect() {
	if (text[0] != '-' &&( text[0] < '0' || text[0] > '9'))
		return false;
	//4+*20+45+76-190
	for (int i{ 0 }; i < text.size()-1; i++) {
		if (isSymbol(text[i])&& (!isDigit(text[i + 1] || text[i + 1] != '-'))) {
			return false;
		}
		if (!isSymbol(text[i])) {
			if (!isDigit(text[i])) {
				return false;
			}
		}
	}
	return true;
}
Parser::Parser(std::string text_) :text{ text_ } {}

void Parser::parseString() {
	std::string tmpNum;
	for (int i{ 0 }; i < text.size(); i++) {
		if (isDigit(text[i])) {
			tmpNum += text[i];
			continue;
		}
		else {
			numbers.push_back(std::stod(tmpNum));
			tmpNum.erase();
		}
		if(isSymbol(text[i])){
			symbols.push_back(text[i]);
		}
	}
}


