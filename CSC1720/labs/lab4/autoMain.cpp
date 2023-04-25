/*
   Felecia Gonzalez
   ~/csc1720/labs/lab4/autoMain.cpp
   About: test program for autoType object

   to compile: g++ -Wall autoMain.cpp autoTypeImp.cpp -o Auto
   to execute: ./Auto
*/

#include<iostream>
#include<string>
#include<iomanip>
#include"autoType.h"

using namespace std;

int main() {
   autoType a, b;//declare 2 test variables
   autoType c;//default constructor test
   autoType d(2022, 20, 17.5);//consturctor test

   a.setValues(235432, 16, 16);//a values are reasonable
   b.setValues(300, 500, 0);//b values contains unreasonables

   cout << "a dashboard: " << a.createDash() << endl;//should be odometer:235432, fuel level:16, efficiency:16
   cout << "b dashboard: " << b.createDash() << endl;//should be odometer:300, fuel level:10, efficiency:20
   cout << "c dashboard: " << c.createDash() << endl;//should be odometer:0, fuel level:10, efficiency:20
   cout << "d dashboard: " << d.createDash() << endl;//should be odometer:2022, fuel level:20, efficiency:17.5

   cout << endl;//spacing :/
   cout << endl;

   a.drive(250);//drive less than possible
   b.drive(250);//drive more than possible

   cout << "autoType a and autoType b attempt to drive 250 miles.\na can drive 250 miles, b cannot.\n" << endl;

   cout << "a dashboard post-drive: " <<  a.createDash() << endl;//should be odometer:235682, fuel level:0.375, efficiency:16
   cout << "b dashboard post-drive: " <<  b.createDash() << endl;//should be odometer:500, fuel level:0, efficiency:20

   cout << "\nautoType a attempts to drive 6 miles\n" << endl;

   a.drive(6);//should be exactly what is possible

   cout << "a dashboard post second drive: " << a.createDash() << endl;//should be odometer:235688, fuel level:0, efficiency:16

   return 0;//end main program
}
