#ifndef TABLE_H
#define TABLE_H
#include <iostream>
using namespace std;

class Table {
	bool available;
	string code;
	int capacity;
public:
	Table();
	Table(string code, int capacity);
	void setTable(string code, int capacity);
	string able();
	void setStatus();
	bool Status();
};

#endif