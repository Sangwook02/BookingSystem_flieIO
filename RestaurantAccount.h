#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Account.h"
class RestaurantAccount:public Account {
	int age;
public:
	RestaurantAccount();
	int Menu();

};

#endif