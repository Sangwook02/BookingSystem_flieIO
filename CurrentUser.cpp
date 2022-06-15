#include "CurrentUser.h"

CurrentUser::CurrentUser(Account user) {
	this->id = user.getID();
}

string CurrentUser::getID() {
	return this->id;
}