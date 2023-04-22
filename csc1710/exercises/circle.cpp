//circle thingy
//Felecia Gonzalez

#include <iostream>

using namespace std;

int main() {
	float pi = 3.1415;
	float radius;

	cout << "What is the radius?" << endl;
	cin >> radius;

	cout << "The radius of the circle = " << radius << "." << endl;
	cout << "The area of the circle = " << static_cast<float>(pi*radius*radius) <<"." << endl;
	cout << "The circumference of the circle = " << static_cast<float>(pi*radius*2) << "." << endl;

	return 0;
}
