/* Felecia Gonzalez
   Dr. Wei Yong
   CSC 1710-03
   Lab 5           */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
	//associates in/out file with iostream
	ifstream inFile;
	ofstream outFile;

	//opens in/out files
	inFile.open("inData.txt");
	outFile.open("outData.txt");

	cout << fixed << showpoint;
	cout << setprecision(2);//forces the output to show trailing 0s and show only 2 decimals
	
	string firstName, lastName, department;
	double MGS, bonus, tax, pay, miles, time, speed, cost, sales;
	int coffeeSold;//declare all variables

	inFile >> firstName >> lastName >> department;
	inFile >> MGS >> bonus >> tax;
	inFile >> miles >> time;
	inFile >> coffeeSold >> cost;//assign variables from file data

	pay = (MGS + MGS*bonus/100.0) * (1 - tax/100.0);//calculate paycheck

	speed = miles/time;//calculate average speed

	sales = coffeeSold*cost;//calculate coffee sales

	//output statements into out file
	outFile << "Name: " << firstName << " " << lastName << ", Department: " << department << endl;
	outFile << "Monthly Gross Salary: $" << MGS << ", Monthly Bonus: " << bonus << "%, Taxes: " << tax << "%" << endl;
	outFile << "Paycheck: $" << pay << endl;
	outFile << " " << endl;
	outFile << "Distance Traveled: " << miles << " miles, Traveling Time: " << time << " hours" << endl;
	outFile << "Average Speed: " << speed << " miles per hour" << endl;
	outFile << " " << endl;
	outFile << "Number of Coffee Cups Sold: " << coffeeSold << ", Cost: $" << cost << " per cup" << endl;
	outFile << "Sales Amount = $" << sales << endl;

	inFile.close();
	outFile.close();
	

	return 0;
}
