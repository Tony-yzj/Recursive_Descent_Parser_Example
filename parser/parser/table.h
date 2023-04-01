#pragma once
// �ļ���: table.h �洢�����ı����
#include <string>
#include <assert.h>
class Table
{
public:
	Table(std::string id, int value, Table *tail);
	~Table();
	std::string id;	//������
	int value;	 //����ֵ
	Table *tail; //�����һ��
};

int lookup(Table *table, std::string id);	//���ұ���
void update(Table **tabptr, std::string id, int value);	//���±���