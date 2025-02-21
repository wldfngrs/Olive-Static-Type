#pragma once

#include <string>
#include <map>

enum TokenType {
	// Single-character tokens.
	t_LPAREN, t_RPAREN,
	t_LBRACE, t_RBRACE,
	t_COMMA, t_MINUS, t_UNARY, t_PLUS,
	t_DIVIDE, t_MULTIPLY, t_COLON,
	// One or two character tokens.
	t_BANG, t_BANGEQUAL,
	t_EQUAL, t_EQUALEQUAL,
	t_GREATER, t_GREATEREQUAL,
	t_LESS, t_LESSEQUAL,
	// Literals.
	t_IDENTIFIER, t_STRING, t_NUMBER,
	// Keywords.
	t_AND, t_ELSE, t_FALSE,
	t_FOR, t_FN, t_IF, t_OR,
	t_PRINT, t_RETURN,
	t_TRUE, t_INT, t_STR, t_DBL, t_WHILE, t_BREAK, t_CONTINUE,
	t_NEWLINE,
};

struct Token {
	Token();
	Token(TokenType tokenType, std::string literal, size_t line);
	void print() const;

	TokenType mTokenType;
	size_t mLine;
private:
	std::string mLiteral;
};

static std::map<std::string, TokenType> keywords = {
	{"and", t_AND},
	{"else", t_ELSE},
	{"false", t_FALSE},
	{"for", t_FOR},
	{"fn", t_FN},
	{"if", t_IF},
	{"or", t_OR},
	{"print", t_PRINT},
	{"true", t_TRUE},
	{"int", t_INT},
	{"str", t_STR},
	{"dbl", t_DBL},
	{"while", t_WHILE},
	{"break", t_BREAK},
	{"continue", t_CONTINUE}
};