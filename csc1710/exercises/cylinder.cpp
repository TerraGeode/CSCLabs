#include <iostream>
using namespace std;
int main() {
	double pi = 3.1415926, radius, height;

	cout << "Please enter the radius." << endl;
	cin >> radius;

	cout << "Please enter height." << endl;
	cin >> height;

	cout << "The surface area is " << pi*2*radius*radius + radius*height << "." << endl;
	cout << "The volume is " << pi*radius*radius*height << "." << endl;

	return 0;
}
