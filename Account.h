#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <map>
#include <fstream>
using namespace std;


extern map<string,string> flight;
extern map<string, string> rest;

class Account {
	string name;
	string id;
	int numberOfBooking;
	string currentUserID;
public:
	Account();
	void setUser(int n);
	int login(int n);
	void show();
	string getID();
	string getName();
	string getCurrentUser();
	void setCurrentUser(string id);
	int getNumberOfBook();
	void addNumberOfBook();
	void subNumberOfBook();
	bool find(string a, int n);
};

#endif
