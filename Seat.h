#ifndef SEAT_H
#define SEAT_H

#include <iostream>
using namespace std;

class Seat {
	bool available;
	int seatNumber;
	int sex; //여자2, 남자 1, 초기화 상태 0
	int id; //초기화 상태 -1
	int roomNumber; //초기화 상태 0
public:
	Seat();
	int getUserSex();
	void setSeat(int seatNumber);
	bool Status();
	void able();
	void setStatus(int sex);
};

#endif