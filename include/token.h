#pragma once

#include <string>
#include <map>

enum TokenType {
	// Single-character tokens.
	TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
	TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,
	TOKEN_COMMA, TOKEN_MINUS, TOKEN_PLUS,
	TOKEN_SLASH, TOKEN_MOD, TOKEN_STAR, TOKEN_QUESTION_MARK, TOKEN_COLON,
	TOKEN_PERCENT,
	// One or two character tokens.
	TOKEN_BANG, TOKEN_BANG_EQUAL,
	TOKEN_EQUAL, TOKEN_EQUAL_EQUAL,
	TOKEN_GREATER, TOKEN_GREATER_EQUAL,
	TOKEN_LESS, TOKEN_LESS_EQUAL,
	// Literals.
	TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_NUMBER,
	// Keywords.
	TOKEN_AND, TOKEN_ELSE, TOKEN_FALSE,
	TOKEN_FOR, TOKEN_FN, TOKEN_IF, TOKEN_OR,
	TOKEN_PRINT, TOKEN_RETURN,
	TOKEN_TRUE, TOKEN_INT, TOKEN_STR, TOKEN_WHILE, TOKEN_BREAK, TOKEN_CONTINUE,
	TOKEN_NEWLINE,
	TOKEN_EOF,
};

struct Token {
	Token();
	Token(TokenType type, std::string literal, size_t line);
	void print() const;

private:
	TokenType mType;
	std::string mLiteral;
	size_t mLine;
};

static std::map<std::string, TokenType> keywords = {
	{"and", TOKEN_AND},
	{"else", TOKEN_ELSE},
	{"false", TOKEN_FALSE},
	{"for", TOKEN_FOR},
	{"fn", TOKEN_FN},
	{"if", TOKEN_IF},
	{"or", TOKEN_OR},
	{"print", TOKEN_PRINT},
	{"true", TOKEN_TRUE},
	{"int", TOKEN_INT},
	{"str", TOKEN_STR},
	{"while", TOKEN_WHILE},
	{"break", TOKEN_BREAK},
	{"continue", TOKEN_CONTINUE}
};