#pragma once

#include <string>
#include <vector>

#include "token.h"

class Scanner {
	size_t line_no = 1;
	size_t start = 0;
	size_t current = 0;
	std::string mSrc;
	
	Token makeToken(TokenType single, std::string singleLiteral, TokenType multi, std::string mutliLiteral);

public:
	Scanner(std::string inputSrc);
	void scan(std::vector<Token>& tokensOutput);
};