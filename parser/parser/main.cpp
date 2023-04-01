#include "parser.h"
// 文件名: main.c 主程序，用于输入/测试
extern enum token tok;
extern void advance();
int main()
{
	scanner();
	advance();
	S();
	if (tok != END)
	{
		error();
	}
}