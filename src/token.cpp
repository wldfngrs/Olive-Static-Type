#include "../include/token.h"

#include <iostream>

Token::Token() {}

Token::Token(TokenType tokenType, std::string literal, size_t line) {
	mTokenType = tokenType;
	mLiteral = literal;
	mLine = line;
}

void Token::print() const {
	std::cout << mLiteral << std::endl;
}