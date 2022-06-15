#include <iostream>
using namespace std;
#include "Menu.h"
#include <map>
#include <vector>

map<string, string> flight;
map<string, string> rest;
vector<string> dataFlightID;
vector<string> dataFlightCode;

vector<string> dataRestaurantID;
vector<int> dataRestaurantTime;
vector<int> dataRestaurantTable;

vector<int> dataStudyCafeTime;
vector<int> dataStudyCafeID;
vector<int> dataStudyCafeSeat;


int main() {
	Menu run;
	run.getMenu();
	return 0;
}