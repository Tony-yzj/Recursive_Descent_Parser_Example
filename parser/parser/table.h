#pragma once
// 文件名: table.h 存储变量的表格定义
#include <string>
#include <assert.h>
class Table
{
public:
	Table(std::string id, int value, Table *tail);
	~Table();
	std::string id;	//变量名
	int value;	 //变量值
	Table *tail; //表格下一行
};

int lookup(Table *table, std::string id);	//查找变量
void update(Table **tabptr, std::string id, int value);	//更新变量