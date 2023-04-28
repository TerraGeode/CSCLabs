/* TerraGeode
   CSC1710-03
   Lab 10: further practice on function writing, function overloading, and default parameters
*/

#include <iostream>
#include <cmath>

using namespace std;

double pi = 3.14;//global var

double distance(double x1, double y1, double x2, double y2) {//generate distance between 2 points
   static double result;//static ensures result is a local variable

   result = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));//calculate distance

   return result; //returns the distance
}

double radius(double centerX, double centerY, double pointX, double pointY) {
   double rad;

   rad = distance(centerX, centerY, pointX, pointY); //canablizing code that already exists

   return rad;
}

double circumference(double radius = 1) {//default value 1
   static double result;

   result = 2.0 * pi * radius;//calculations :)

   return result;
}

double area(double radius = 1) {//default value is 1
   static double result;

   result = pi * pow(radius, 2);//the integral of circumference

   return result;
}

double distance(double x, double y) {//overloaded edition
   static double result;

   result = sqrt(pow(x, 2) + pow(y, 2));//measures distance from orgin

   return result;
}

int main() {
   double myX1, myY1, myX2, myY2, myDistance, myRadius;

   cout << "First coordinate pair?" << endl;
   cin >>  myX1 >> myY1;
   cout << "Second coordinate pair?" << endl;
   cin >> myX2 >> myY2;
   //get coordinates from user

   myDistance = distance(myX1, myY1, myX2, myY2); //calculate

   cout << "The distance is: " << myDistance << endl; //output
   cout << "The overloaded distance (using second coordinate pair and orgin) is: " << distance(myX2, myY2) << endl;

   cout << "Center coordinate?" << endl;
   cin >>  myX1 >> myY1;
   cout << "Point coordinate?" << endl;
   cin >> myX2 >> myY2;
   //get coordinates from user

   myRadius = radius(myX1, myY1, myX2, myY2); //calculate

   cout << "The radius is: " << myRadius << endl; //output

   cout << "The circumference is " << circumference(myRadius) << endl;

   cout << "The area of the circle is " << area(myRadius) << endl;

   cout << "Circumference default: " << circumference() << endl;
   cout << "Area default: " << area() << endl;

   return 0;
}
