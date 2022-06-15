#include "Table.h"

Table::Table() {
	this->available = true;
	this->capacity = 0;
	this->code = " ";
}

Table::Table(string code, int capacity) {
	this->available = true;
	this->capacity = 0;
	this->code = "0";
}
void Table::setTable(string code, int capacity) {
	this->available = true;
	this->capacity = capacity;
	this->code = code;
}

string Table::able() {
	if (available == true) {
		return code;
	}
	else {
		return " ";
	}
}
bool Table::Status() {
	return available;
}
void Table::setStatus() {
	this->available = false;
}