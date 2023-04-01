// 文件名: parser.cpp 用于分析词法，绑定语义
#include "parser.h"
void error()
{
	std::cout << "error";
	assert(true);
}                           //the error handler, emit the details here

enum token tok;
struct tokenval tokval;
void advance() { tok = getToken(); }
void eat(enum token t) { if (tok == t) advance(); else error(); }
Table *table;
int S_FOLLOW[] = { SEMICOLON, COMMA };
void S(void) {
	switch (tok) {
	case ID:    //S := ID ASSIGN E
	{
		std::string id = tokval.id;
		eat(ID);
		if (tok == ASSIGN)
		{
			eat(ASSIGN);
			update(&table, id, E());
		}
		if (tok == SEMICOLON) //ENBF定义 S := ID ASSIGN E { SEMICOLON S } 
		{
			eat(SEMICOLON);
			S();
		}
		break;
	}
	case PRINT: //S := PRINT LPR L RPR
	{
		eat(PRINT);
		if (tok == LPAREN)
		{
			eat(LPAREN);
			L();
			printf("\n");
			eat(RPAREN);
		}
		if (tok == SEMICOLON)	//ENBF定义 S := PRINT LPAREN L RPAREN { SEMICOLON S }
		{
			eat(SEMICOLON);
			S();
		}
		break;
	}
	default:
	{
		error(); //采用错误直接终端策略
	}
	}
}

int L_FOLLOW[] = { RPAREN, COMMA };
void L(void) {
	switch (tok) {
	case ID: case INT: case PRINT: case LPAREN:	// L := E  (scan the token in first(E))
	{
		printf("%d ", E());
		while (tok == COMMA)	//ENBF定义 L := E { COMMA L }
		{
			eat(COMMA);
			printf("%d ", E());
		}
		break;
	}
	default:
	{
		error();
	}
	}
}

int E_FOLLOW[] = { PLUS, MINUS, TIMES, DIV, COMMA, SEMICOLON };
int E(void) {
	switch (tok) {
	case INT:	// E := INT
	{
		int num = tokval.num;
		eat(INT);
		int op = tok;
		// E := INT { B }
		while (op == PLUS || op == MINUS || op == TIMES || op == DIV)
		{
			num = B(num);
			op = tok;
		}
		return num;
		break;
	}
	case ID:		//E := ID
	{
		int num;
		if (getNext() == ASSIGN) // E := S COMMA E
		{
			S();
			if (tok != COMMA) error();
			eat(COMMA);
			num = E();
			// E := S COMMA E { B }
			while (tok == PLUS || tok == MINUS || tok == TIMES || tok == DIV)
			{
				num = B(num);
			}
			return num;
		}
		num = lookup(table, tokval.id);
		eat(ID);
		int op = tok;
		// E := ID { B }
		while (op == PLUS || op == MINUS || op == TIMES || op == DIV)
		{
			num = B(num);
			op = tok;
		}
		return num;
	}
	case PRINT:		// E := S COMMA E
	{
		S();
		if (tok != COMMA) error();
		eat(COMMA);
		int num = E();
		// E := S COMMA E { B }
		while (tok == PLUS || tok == MINUS || tok == TIMES || tok == DIV)
		{
			num = B(num);
		}
		return num;
	}
	case LPAREN:	// E := LPAREN E RPAREN
	{
		eat(LPAREN);
		int num = E();
		eat(RPAREN);
		// E := LPAREN E RPAREN { B }
		while (tok == PLUS || tok == MINUS || tok == TIMES || tok == DIV)
		{
			num = B(num);
		}
		return num;
	}
	default:
	{
		error();
	}
	}
	return -1;
}

int B_FOLLOW[] = { INT, ID, LPAREN, ID, PRINT };	//Calculate
int B(int num) {
	switch (tok) {
	case PLUS:
	{
		eat(PLUS);
		return num + E();
		break;
	}
	case MINUS:
	{
		eat(MINUS);
		return num - E();
		break;
	}
	case TIMES:
	{
		eat(TIMES);
		return num * E();
		break;
	}
	case DIV:
	{
		eat(DIV);
		return num / E();
		break;
	}
	default:
	{
		error();
		return -1;
	}
	}
}

/*void eatOrSkipTo(token expected, int *stop) {
	if (tok==expected)
		eat(expected);
	else {error(); skipto(stop);}
}*/