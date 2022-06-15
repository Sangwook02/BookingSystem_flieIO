#ifndef BOOKRESTAURANT_H
#define BOOKRESTAURANT_H
#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include "Account.h"
#include "Table.h"



extern vector<string> dataRestaurantID;
extern vector<int> dataRestaurantTime;
extern vector<int> dataRestaurantTable;

class BookRestaurant {
	queue<string>four_q;
	queue<string>six_q;
	int date;
	int time;

	Table t[30][9];

public:
	BookRestaurant();
	int Book(string id);
	void cancel(string id);
	int WalkIn(string id);
	void setTime();
	void setDate();
	int getFour_q_size();
	int getSix_q_size();
	int take(int n, string id);
};

#endif
