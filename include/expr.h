#pragma once

#include "token.h"

#include <iostream>

enum Type {
	INT,
	STR,
	DBL,
	NAT,
};

class Expr {
	Type mType;
public:
	virtual void print_ast() {
		;
	}

	void set_type(Type type) {
		mType = type;
	}

	Type check_type() const {
		return mType;
	}
};


// CHECK TYPE INFORMATION AND CONSISTENCY
class Unary : Expr {
	std::unique_ptr<Expr> mExpr;
public:
	Unary(std::unique_ptr<Expr> expr) {
		mExpr = std::move(expr);
		set_type(NAT);
	}
	void print_ast() override {
		std::cout << "unary(int:";
		mExpr->print_ast();
		std::cout << ")";
	}
};

class Binary : Expr {
	char mOp;
	std::unique_ptr<Expr> mLeft, mRight;
public:
	Binary(std::unique_ptr<Expr> left, char op, std::unique_ptr<Expr> right) {
		mLeft = std::move(left);
		mOp = op;
		mRight = std::move(right);
		set_type(NAT);
	}
	void print_ast() override {
		std::cout << "binary(";
		mLeft->print_ast();
		std::cout << " " << mOp << " ";
		mRight->print_ast();
		std::cout << ")";
	}
};

class Group : Expr {
	std::unique_ptr<Expr> mExpr;
public:
	Group(std::unique_ptr<Expr> expr) {
		mExpr = std::move(expr);
		set_type(NAT);
	}
	
	void print_ast() override {
		std::cout << "group(";
		mExpr->print_ast();
		std::cout << ")";
	}
};

class Str : Expr {
	std::string mString;
public:
	Str(std::string string) {
		mString = string;
		set_type(STR);
	}
	void print_ast() override {
		std::cout << "str: " << mString;
	}
};

class Int : Expr {
	int64_t mInteger;
public:
	Int(int64_t integer) {
		mInteger = integer;
		set_type(STR);
	}

	void print_ast() override {
		std::cout << "int: " << mInteger;
	}
};

class Dbl : Expr {
	double mDbl;
public:
	Dbl(double dbl) {
		mDbl = dbl;
		set_type(STR);
	}

	void print_ast() override {
		std::cout << "dbl: " << mDbl;
	}
};