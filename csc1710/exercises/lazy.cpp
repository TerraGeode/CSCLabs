/* 
   Lake Lazy day Ch. 4 exercise */

#include <iostream>

using namespace std;

int main() {
	int temp;

	cout << "Please enter the temperature." << endl;

	cin >> temp; //gets temperature from user

	if (temp > 95 || temp < 20) {
		cout << "Visit our shops!" << endl;
	}else if (temp >= 80) {
		cout << "swimming" << endl;
	} else if (temp >= 60) {
		cout << "tennis" << endl;
	} else if (temp >= 40) {
		cout << "golf" << endl;
	} else {
		cout << "skiing" << endl;
	}

	return 0;
}

//best practice is to ensure if condition is satifies by itself in entirety to minimize risk of breaking
