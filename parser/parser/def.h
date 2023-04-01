#pragma once
// 文件名: def.h 预定义类型
#include <string>
enum token { INT, ID, ASSIGN, PRINT, LPAREN, RPAREN, COMMA, SEMICOLON, PLUS, MINUS, TIMES, DIV, END };
struct tokenval { std::string id; int num; };
struct toks
{
	enum token name;
	struct tokenval value;
};
typedef struct toks * tokptr;

typedef struct toks Toks;