#pragma once
// 文件名: parser.h 用于分析词法，绑定语义
#include <string>
#include <iostream>
#include <assert.h>
#include "table.h"
#include "lex.h"
#include "def.h"


//extern void skipto(int* stop);
//extern enum token getToken(void);       //get the token from lexical analysis
//extern enum token getNext(void);        //get the next token from lexical analysis
void S(void);
int E(void);
void L(void);
int B(int num);
void error();

