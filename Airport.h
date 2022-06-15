#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include <fstream>
using namespace std;
#include "Flight.h"

class Airport {
	Flight f[4][7][3];
	string code; // 공항의 식별코드를 대문자로 표현하여 이후 항공편의 식별코드를 만들 때 사용.
public:
	Airport();
	Airport(string code);
	string getCode();
	int take(int a,int b, int c);
	int cancel(int a, int b, int c);
};

#endif 