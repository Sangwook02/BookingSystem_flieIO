#ifndef CURRENTUSER_H
#define CURRENTUSER_H
#include <iostream>
#include "Account.h"
using namespace std;

class CurrentUser {
	string  id;
public:
	CurrentUser(Account user);
	string getID();
};

#endif