#include "parser.h"
// �ļ���: main.c ��������������/����
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