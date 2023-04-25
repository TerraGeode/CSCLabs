/*
   Felecia Gonzalez
   ~/csc1720/labs/lab4/autoMain.cpp
   About: test program for autoType and hybridType classes

   to compile: g++ -Wall autoMain.cpp autoTypeImp.o hybridTypeImp.o -o Auto
   to execute: ./Auto
*/

#include<iostream>
#include<string>
#include"autoType.h"
#include"hybridType.h"

using namespace std;

int main() {
   autoType a, b;//declare 2 test variables
   autoType c;//default constructor test
   autoType d(2022, 20, 17.5);//consturctor test
   hybridType e, f;//hybridType is a derived class based on autoType
   a.setValues(235432, 16, 16);//a values are reasonable
   b.setValues(-300, 500, 0);//b values contains unreasonables

   e.setCharge(15);
   e.setChargeEfficiency(2);//sets e charge and efficiency values to something reasonable

   f.setCharge(-1);
   f.setChargeEfficiency(20);//both variables are unreasonable for charge and efficiency

   cout << "autoType tests:" << endl;
   cout << "a dashboard: \n" << a.createDash() << endl;//should be odometer:235432, fuel level:16, efficiency:16
   cout << "b dashboard: \n" << b.createDash() << endl;//should be odometer:0, fuel level:10, efficiency:20
   cout << "c dashboard: \n" << c.createDash() << endl;//should be odometer:0, fuel level:10, efficiency:20
   cout << "d dashboard: \n" << d.createDash() << endl;//should be odometer:2022, fuel level:20, efficiency:17.5

   cout << endl;
 
   cout << "hybridType tests:" << endl;
   cout << "e dashboard:\n" << e.createDash() << endl;//odometer:0, fuel level:10, efficiency:20, charge = 15, ce = 2
   cout << "f dashboard:\n" << f.createDash() << endl;//odometer:0, fuel level:10, efficiency:20, charge = 25, ce = 3

   cout << endl;//spacing :/

   a.drive(250);//drive less than possible
   b.drive(250);//drive more than possible

   cout << "autoType a and autoType b attempt to drive 250 miles." << endl;
   cout << "a can drive upto 256 miles. b can drive up to 200 miles." <<endl;
   cout << endl;

   cout << "a dashboard post-drive:\n" <<  a.createDash() << endl;//should be odometer:235682, fuel level:0.375, efficiency:16
   cout << "b dashboard post-drive:\n" <<  b.createDash() << endl;//should be odometer:200, fuel level:0, efficiency:20

   cout << "\nautoType a will drive the remaining 6 miles it can.\n" << endl;

   a.drive(6);//should be exactly what is possible

   cout << "a dashboard post second drive:\n" << a.createDash() << endl;//should be odometer:235688, fuel level:0, efficiency:16

   return 0;//end main program
}
