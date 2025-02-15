#pragma once

#include <string>
#include <map>

enum TokenType {
	// Single-character tokens.
	t_LPAREN, t_RPAREN,
	t_LBRACE, t_RBRACE,
	t_COMMA, t_MINUS, t_PLUS,
	t_DIVIDE, t_STAR, t_COLON,
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
	t_EOF,
};

struct Token {
	Token();
	Token(TokenType tokenType, std::string literal, size_t line);
	void print() const;

private:
	TokenType mTokenType;
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
	{"dbl", TOKEN_DBL},
	{"while", TOKEN_WHILE},
	{"break", TOKEN_BREAK},
	{"continue", TOKEN_CONTINUE}
};