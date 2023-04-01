#pragma once
// 文件名: lex.h 用于lex analysis
#include <string>
#include <iostream>
#include <vector>
#include "def.h"

//tokptr t;
bool isDigital(std::string str);
bool ischar(char c);
void scanner(void);
enum token getToken(void);
enum token getNext(void);
void skipto(int *stop);