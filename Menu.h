#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include "FlightAccount.h"
#include "RestaurantAccount.h"
#include "StudyCafeAccount.h"



class Menu {
	FlightAccount* user;
	int flightSize;

	RestaurantAccount* ruser;
	int restaurantSize;

	StudyCafeAccount* suser;
	int studyCafeSize;
public:
	Menu();
	~Menu();
	void print(string a,int n);
	void getMenu();
};
#endif