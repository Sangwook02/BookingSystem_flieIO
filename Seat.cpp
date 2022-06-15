#include "Seat.h"
#include <string>



int Seat::getUserSex() {
	return sex;
}
Seat::Seat() {
	this->available = true;
	this->sex = 0;
	this->seatNumber = -1;
	this->id = -1;
	this->roomNumber = 0;
}
bool Seat::Status() {
	return available;
}
void Seat::setStatus(int sex) {
	this->available = false;
	this->sex = sex;
}
void Seat::able() {
	if (available == true) {
		cout.width(3);
		cout << seatNumber;
	}
	else {
		
		cout << "   ";
	}
}


void Seat::setSeat(int seatNumber) {
	this->seatNumber = seatNumber;
}