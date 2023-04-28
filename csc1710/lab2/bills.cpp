/*
	CSC-1710-03
	Name: TerraGeode
	Lab 2
	File: bills.cpp
*/

#include <iostream>
using namespace std;
int main() {
	int bills20, bills10, bills5, bills1, total; //intializes all variables

	cout << "How many $20s?" << endl;
	cin >> bills20; //asks for total amount of $20 bills

	cout << "How many $10s?" << endl;
	cin >> bills10; // asks for total amount of $10 bills

	cout << "How many $5s?" << endl;
	cin >> bills5; //asks for total amount of $5 bills

	cout << "How many $1s?" << endl;
	cin >> bills1; // asks for total amount of $1 bills

	total = bills20*20 + bills10*10 + bills5*5 + bills1*1; //generates the total amount of money
	cout << "The total amount is " << total << " dollars." << endl; 

	return 0;
}
