#ifndef BOOKFLIGHT_H
#define BOOKFLIGHT_H
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Airport.h"
#include <fstream>
using namespace std;

extern vector<string> dataFlightID;
extern vector<string> dataFlightCode;

class BookFlight {
	int onewayOrRound; //왕복이면 0, 편도면 1
	int date;
	int time;
	int month;
	string departureCode;
	int departure;
	int arrival;
	string arrivalCode;
	string flightCode;
	Airport a[5];
public:
	void setOnewayOrRound();
	void setTime();
	void setDate();
	void setWhereToWhere();
	int Book(string id);
	void cancel(string id);
	string getFlightCode();
};

#endif