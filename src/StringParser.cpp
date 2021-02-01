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
	if (text_[0] != '-' && (!isDigit(text_[0]))) 
		return false;
	if (text_[0] == '-' && (text_[1] != '-' && !isDigit(text_[1])))
		return false;
	for (int i = 0; i <= text_.size()-1; i++) {
		if (isSymbol(text_[i])) {
			if (!isDigit(text_[i + 1]) && text_[i + 1] != '-') {
				return false;
			}
		}
		if (!isSymbol(text_[i])) {
			if (!isDigit(text_[i])) {
				return false;
			}
		}
	}
	return true;
}
Parser::Parser(std::string text__) :text_{ text__ } {}

void Parser::parseString() {
	std::string tmpNum;
	int i{};
	if (text_[0] == '-') {	
		tmpNum += text_[0];
		i++;
	}
	for (i; i <= text_.size()-1; i++) {
		if (isDigit(text_[i]) || (isSymbol(text_[i - 1]) && text_[i] == '-')) {
			tmpNum += text_[i];
			continue;
		}
		else {
			if (!tmpNum.empty()) {
				numbers_.push_back(std::stod(tmpNum));
				tmpNum.erase();
			}
		}
		if(isSymbol(text_[i])){
			symbols_.push_back(text_[i]);
		}
	}
	if (!tmpNum.empty()) {
		numbers_.push_back(std::stod(tmpNum));
	}
	std::reverse(numbers_.begin(), numbers_.end());
	std::reverse(symbols_.begin(), symbols_.end());
}

std::vector<double> Parser::numbers() {
	return numbers_;
}

std::vector<char> Parser::symbols() {
	return symbols_;
}