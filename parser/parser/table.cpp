#include "table.h"
// 文件名: table.cpp 存储变量的表格定义
Table::Table(std::string id, int value, Table *tail) :id(id), value(value), tail(tail)
{
}

Table::~Table()
{
}

int lookup(Table *table, std::string id) {
	assert(table != nullptr);
	if (id == table->id) return table->value;
	else return lookup(table->tail, id);
}
void update(Table **tabptr, std::string id, int value) {
	*tabptr = new Table(id, value, *tabptr);
}