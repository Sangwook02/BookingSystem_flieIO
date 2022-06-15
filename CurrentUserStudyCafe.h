#ifndef CURRENTUSERSTUDYCAFE_H
#define CURRENTUSERSTUDYCAFE_H
#include <iostream>
#include "StudyCafeAccount.h"
using namespace std;

class CurrentUserStudyCafe {
	int id;
	int sex;

public:
	CurrentUserStudyCafe(StudyCafeAccount suser);
	int getID();
	int getSex();
};

#endif