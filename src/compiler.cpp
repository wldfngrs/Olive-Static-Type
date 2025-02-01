#include <fstream>
#include <iostream>
#include <sstream>

#include "../include/compiler.h"
#include "../include/scanner.h"

Compiler::Compiler() {}

void Compiler::compile(const char* path) {
	std::ostringstream ss;
	std::ifstream file(path, std::ios_base::in);
	// check for failure if file is not found!

	ss << file.rdbuf();
	std::string input = ss.str();

	Scanner scanner(input);
	scanner.scan(mTokens);
	
	for (auto& token : mTokens) {
		token.print();
	}
}