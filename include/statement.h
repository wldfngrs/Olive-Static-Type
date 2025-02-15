#pragma once

#include "expr.h"

#include <vector>
#include <iostream>

class Statement {
public:
	virtual void print_ast() = 0;
};

class Print : Statement {
	std::unique_ptr<Expr> mExpr;

public:
	Print(std::unique_ptr<Expr> expr) {
		mExpr = std::move(mExpr);
	}
	
	void print_ast() override {
		std::cout << "print(";
		mExpr->print_ast();
		std::cout << ")\n";
	}
};

class Root {
	std::vector<Statement> statements;

public:
	void print_ast() {
		std::cout << "(root(";
		for (auto& statement : statements) {
			statement.print_ast();
		}
		std::cout << ")\n";
	}
};