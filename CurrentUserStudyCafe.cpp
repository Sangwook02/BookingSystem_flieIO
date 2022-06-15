#include "CurrentUserStudyCafe.h"


CurrentUserStudyCafe::CurrentUserStudyCafe(StudyCafeAccount suser) {
	this->id = suser.getID();
	this->sex = suser.getSex();
}
int CurrentUserStudyCafe::getID() {
	return id;
}
int CurrentUserStudyCafe::getSex() {
	return sex;
}