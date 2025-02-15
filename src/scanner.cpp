#include "../include/scanner.h"

#include <iostream>

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

static bool isAlpha(char c) {
	return (c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c == '_');
}

Scanner::Scanner(std::string inputSrc) {
	mSrc = inputSrc;
};

Token Scanner::makeToken(TokenType single, std::string singleLiteral, TokenType multi, std::string multiLiteral) {
	Token token;
	if (std::string(mSrc, start, 2) == multiLiteral) {
		token = { multi, multiLiteral, line_no };
		current += 2;;
	}
	else {
		token = { single, singleLiteral, line_no };
		++current;
	}

	return token;
}

void Scanner::scan(std::vector<Token>& tokensOutput) {
	for (; current < mSrc.size();) {
		switch (mSrc[start]) {
		// Single-character tokens.
		case ' ':
		case '\r':
		case '\t':
			current++;
			break;
		case '\n':
			tokensOutput.emplace_back(TOKEN_NEWLINE, "\\n", line_no);
			current++;
			line_no++;
			break;
		case '(':
			tokensOutput.emplace_back(TOKEN_LEFT_PAREN, "(", line_no);
			current++;
			break;
		case ')':
			tokensOutput.emplace_back(TOKEN_RIGHT_PAREN, ")", line_no);
			++current;
			break;
		case '{':
			tokensOutput.emplace_back(TOKEN_LEFT_BRACE, "{", line_no);
			++current;
			break;
		case '}':
			tokensOutput.emplace_back(TOKEN_RIGHT_BRACE, "}", line_no);
			++current;
			break;
		case ',':
			tokensOutput.emplace_back(TOKEN_COMMA, ",", line_no);
			++current;
			break;
		case '-':
			tokensOutput.emplace_back(TOKEN_MINUS, "-", line_no);
			++current;
			break;
		case '+':
			tokensOutput.emplace_back(TOKEN_PLUS, "+", line_no);
			++current;
			break;
		case '/':
			tokensOutput.emplace_back(TOKEN_SLASH, "/", line_no);
			++current;
			break;
		case '*':
			tokensOutput.emplace_back(TOKEN_STAR, "*", line_no);
			++current;
			break;
		case '"':
			start++;
			do {
				++current;
			} while (mSrc[current] != '"' && current <= mSrc.size());

			if (current >= mSrc.size()) {
				std::cout << "Unterminated string.\n";
				return;
			}

			tokensOutput.emplace_back(TOKEN_STRING, std::string(mSrc, start, current - start), line_no);
			current++;
			break;
		// One or two character tokens.
		case '!':
			tokensOutput.push_back(makeToken(TOKEN_BANG, "!", TOKEN_BANG_EQUAL, "!="));
			break;
		case '=':
			tokensOutput.push_back(makeToken(TOKEN_EQUAL, "=", TOKEN_EQUAL_EQUAL, "=="));
			break;
		case '<':
			tokensOutput.push_back(makeToken(TOKEN_LESS, "<", TOKEN_LESS_EQUAL, "<="));
			break;
		case '>':
			tokensOutput.push_back(makeToken(TOKEN_GREATER, ">", TOKEN_GREATER_EQUAL, ">="));
			break;
		default:
			if (isDigit(mSrc[start])) {
				do {
					++current;
				} while (isDigit(mSrc[current]));

				tokensOutput.emplace_back(TOKEN_NUMBER, std::string(mSrc, start, current - start), line_no);
			}
			else if (isAlpha(mSrc[start])) {
				do {
					++current;
				} while (isDigit(mSrc[current]) || isAlpha(mSrc[current]));

				std::string str = std::string(mSrc, start, current - start);
				if (keywords.find(str) == keywords.end()) {
					tokensOutput.emplace_back(TOKEN_IDENTIFIER, std::string(mSrc, start, current - start), line_no);
				}
				else {
					tokensOutput.emplace_back(keywords[str], str, line_no);
				}
			}
			else {
				std::cout << "Unexpected character.\n";
			}
		}

		start = current;
	}
	tokensOutput.emplace_back(TOKEN_EOF, "$", line_no);
}