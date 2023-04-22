/* Felecia Gonzalez
   Dr. Wei Yong
   CSC 1710-03
   Program 1       */

#include <iostream>
using namespace std;
int main() {

	//declare variables (all intergers)
	int mysec, sec, min, hour, day, mod;

	//Get seconds from user
	cout << "Please input an interger amount of seconds." << endl;
	cin >> mysec;

	//calculate seconds
	sec = mysec%60;
	mod = mysec/60;

	//calculate minutes
	min = mod%60;
	mod/=60;

	//calculate hours
	hour = mod%24;
	mod/=24;

	//calculate days
	day = mod;

	//display output
	cout << mysec << " seconds coresponds to: " << day << " days, " << hour << " hours, " << min << " minutes, and " << sec << " seconds." << endl;

	return 0;
}
