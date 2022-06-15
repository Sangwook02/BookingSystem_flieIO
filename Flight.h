#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
using namespace std;

class Flight {
	string seat[9] = { "NO","---","---","---","---","---","---","---","---" }; 
	int status[9];
public:
	Flight();
	void showLeftSeat();
	void showSeat();
	void setStatus(int idx);
	int getStatus(int idx);
}; 

#endif