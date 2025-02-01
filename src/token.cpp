#include "../include/token.h"

#include <iostream>

Token::Token() {}

Token::Token(TokenType type, std::string literal, size_t line) {
	mType = type;
	mLiteral = literal;
	mLine = line;
}

void Token::print() const {
	std::cout << mType << " " << mLiteral << " " << mLine << std::endl;
}