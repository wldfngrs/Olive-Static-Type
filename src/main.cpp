#include <iostream>

#include "../include/compiler.h"

int main(int argc, const char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./olvc [file]\n";
		exit(1);
	}

	Compiler compiler;
	compiler.compile(argv[1]);
}