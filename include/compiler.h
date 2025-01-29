#pragma once
#include <string>

class Compiler {
	std::string mSrc;

public:
	Compiler();
	void compile(const char* path);
};