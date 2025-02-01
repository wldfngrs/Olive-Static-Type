#pragma once
#include <string>
#include <vector>

#include "../include/scanner.h"

class Compiler {
	std::vector<Token> mTokens;

public:
	Compiler();
	void compile(const char* path);
};