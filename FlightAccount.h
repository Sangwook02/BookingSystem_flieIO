#ifndef FLIGHTACCOUNT_H
#define FLIGHTACCOUNT_H
#include "Account.h"
#include <iostream>
#include <map>
using namespace std;


class FlightAccount:public Account {
	int mileage;
public:
	FlightAccount();
	void addMileage();
	void subMileage();
	int Menu();
	int showMileage();
};
#endif