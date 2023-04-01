// 文件名: lex.cpp 用于lex analysis
#include <lex.h>
std::vector<Toks> t;
extern struct tokenval tokval;
bool isDigital(std::string str) {
	for (int i = 0; i < (int)str.size(); i++) {
		if (str.at(i) == '-' && (int)str.size() > 1)  // 有可能出现负数
			continue;
		if (str.at(i) > '9' || str.at(i) < '0')
			return false;
	}
	return true;
}

bool ischar(char c)
{
	if (c == '_' || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return true;
	else
		return false;
}

void scanner(void)
{
	std::string c;
	while (1)
	{
		std::cin >> c;

		if (!c.compare("$"))
		{
			break;
		}
		else if (!c.compare("("))
		{
			tokptr temp = new Toks;
			temp->name = LPAREN;
			t.push_back(*temp);
		}
		else if (!c.compare(")"))
		{
			tokptr temp = new Toks;
			temp->name = RPAREN;
			t.push_back(*temp);
		}
		else if (!c.compare(","))
		{
			tokptr temp = new Toks;
			temp->name = COMMA;
			t.push_back(*temp);
		}
		else if (!c.compare(";"))
		{
			tokptr temp = new Toks;
			temp->name = SEMICOLON;
			t.push_back(*temp);
		}
		else if (!c.compare("+"))
		{
			tokptr temp = new Toks;
			temp->name = PLUS;
			t.push_back(*temp);
		}
		else if (!c.compare("-"))
		{
			tokptr temp = new Toks;
			temp->name = MINUS;
			t.push_back(*temp);
		}
		else if (!c.compare("*"))
		{
			tokptr temp = new Toks;
			temp->name = TIMES;
			t.push_back(*temp);
		}
		else if (!c.compare("/"))
		{
			tokptr temp = new Toks;
			temp->name = DIV;
			t.push_back(*temp);
		}
		else if (!c.compare("="))
		{
			tokptr temp = new Toks;
			temp->name = ASSIGN;
			t.push_back(*temp);
		}
		else if (!c.compare("print"))
		{
			tokptr temp = new Toks;
			temp->name = PRINT;
			t.push_back(*temp);
		}
		else if (isDigital(c))
		{
			tokptr temp = new Toks;
			temp->name = INT;
			temp->value.num = stoi(c);
			t.push_back(*temp);
		}
		else if (!isDigital(c) && ischar(c.at(0)))
		{
			tokptr temp = new Toks;
			temp->name = ID;
			temp->value.id = c;
			t.push_back(*temp);
		}
		else
		{
			std::cout << "error token!";
		}
	}
}

enum token getToken(void)
{
	if ((int)t.size() == 0)
	{
		std::cout << "finished";
		exit(0);
	}
	enum token temp = t[0].name;
	tokval = t[0].value;
	t.erase(t.begin());
	return temp;
}

enum token getNext(void)
{
	return t[0].name;
}

void skipto(int *stop)
{
	int size = sizeof(stop) / sizeof(stop[0]);
	int flag = 0;
	while (1)
	{
		for (int i = 0; i < size; i++)
		{
			if (stop[i] == t[0].name)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			return;
		}
		else
			t.erase(t.begin());
	}
}