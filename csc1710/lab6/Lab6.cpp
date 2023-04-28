/* TerraGeode
   CSC1710-03
   Lab 6           */

#include<iostream>

using namespace std;

int main () {
	//make variables
	int year;

	//get year from user
	cout << "Please give a year." << endl;
	cin >> year;

	//check if past, present, or future year
	if (year < 1582) {//catches dates before 1582
                cout << "Error, " << year << " was before the Gregorian calendar was adopted." << endl;
                return 0;//exits code early
        }else if (year == 2021) {
		cout << year << " is a ";
	}else if (year < 2021 && year > 1582) {
		cout << year << " was a ";
	}else if (year > 2021) {
		cout << year << " will be a ";
	}

	//check if a leap year
	if (year % 4 == 0 && year > 1582 && (year % 100 != 0 || year % 400 == 0)) {
		cout << "leap year." << endl;
	}else if (year > 1582 && year % 400 != 0 && (year % 4 != 0 || year % 100 == 0)) {
		cout << "regular year." << endl;
	}

	return 0;
}
