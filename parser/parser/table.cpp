#include "table.h"
// �ļ���: table.cpp �洢�����ı����
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