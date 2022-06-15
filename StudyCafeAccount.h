#ifndef STUDYCAFEACCOUNT_H
#define STUDYCAFEACCOUNT_H
#include <iostream>
#include <fstream>
using namespace std;
#include <map>

class StudyCafeAccount {
	static int userID;
	int age;
	int sex;//남자 0, 여자 1
	static map<int, string> user;
	int roomNumber;
	int id;
	int currentUserID;
	int currentUserSex;
	int numberOfBooking = 0;
	int time[7] = { 0, };
public:
	int Menu();
	void set();
	int login();
	void addUserID();
	int getID();
	int getCurrentUser();
	int getSex();
	bool find(string id, int n);
	int getNumberOfBook();
	void addNumberOfBook();
	void subNumberOfBook();
	void setCurrentUserSex(int sex);
	int getCurrentUserSex();
	void addTime(int date, int hour);
};

#endif