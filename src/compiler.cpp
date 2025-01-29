#include "../include/compiler.h"

#include <fstream>
#include <iostream>

Compiler::Compiler() {}

void Compiler::compile(const char* path) {
	std::ifstream file(path);
	std::string line;
	while (std::getline(file, line)) {
		mSrc.append(line);
		mSrc.append("\n");
	}

	std::cout << mSrc << std::endl;
}