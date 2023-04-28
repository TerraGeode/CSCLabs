/*
   TerraGeode
   ~/csc1720/programs/program2/autoMain.cpp
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
   cout << "creating autoTypes" << endl;
   autoType a, b;//declare 2 test variables
   autoType c;//default constructor test
   autoType d(2022, 20, 17.5, 25);//consturctor test
   a.setValues(235432, 16, 16);//a values are reasonable
   b.setValues(-300, 500, 0);//b values contains unreasonables

   cout << "creating hybridTypes" << endl;
   hybridType e, f, g;//hybridType is a derived class based on autoType, g is default test
   hybridType h(10, 15, 15, 25, 50, 5);//constructor test
   e.setCharge(5);
   e.setChargeEfficiency(2);//sets e charge and efficiency values to something reasonable

   f.setCharge(-1);
   f.setChargeEfficiency(20);//both variables are unreasonable for charge and efficiency

   cout << "autoType tests:" << endl;
   cout << "a dashboard: \n" << a.createDash() << endl;//should be odometer:235432, fuel level:16, efficiency:16, tank:20
   cout << "---\nb dashboard: \n" << b.createDash() << endl;//should be odometer:0, fuel level:20, efficiency:20, tank:20
   cout << "---\nc dashboard: \n" << c.createDash() << endl;//should be odometer:0, fuel level:20, efficiency:20, tank:20
   cout << "---\nd dashboard: \n" << d.createDash() << endl;//should be odometer:2022, fuel level:20, efficiency:17.5, tank:25

   cout << endl;

   cout << "setting autoType c tank capacity to 15, fuel level should become 15." << endl;
   c.setTankCap(15);//more fuel than new tank can hold
   cout << "c dashboard:\n" << c.createDash() << endl;//should be odometer:0, fuel level:15, efficiency:20, tank:15

   cout << endl;

   cout << "setting autoType d tank to 30" << endl;
   d.setTankCap(30);//current fuel level less than new tank size
   cout << "d dashboard: \n" << d.createDash() << endl;//should be odometer:2022, fuel level:20, efficiency:17.5, tank:30

   cout << endl;

   cout << "Attempting to remove 5 gallons from autoType c" << endl;
   c.addFuel(-5);//not possible

   cout << "\nAdding 10 gallons to autoType c. c's tank is already full." << endl;
   c.addFuel(10);//should say tank full

   cout << "\nAdding 2 gallons to autoType d, d has space for more." << endl;
   d.addFuel(2);//should say fuel:22

   cout << "autoType a and autoType b attempt to drive 300 miles." << endl;
   cout << "a can drive upto 256 miles. b can drive up to 400 miles." <<endl;
   cout << "a:" << endl;
   a.drive(300);//drive less than possible
   cout << "---\nb:" << endl;
   b.drive(300);//drive more than possible

   cout << "\nautoType a will drive the remaining 100 miles it can in reverse.\n" << endl;
   cout << "b:" << endl;
   b.drive(-100);//should be exactly what is possible

   cout << "\nhybridType test:" << endl;

   cout << "e dashboard: \n" << e.createDash() << endl;//charge:5, CE:2, emode:false (set methods tested)
   cout << "---\nf dashboard: \n" << f.createDash() << endl;//charge:100, CE:3, emode:true (set methods tested)
   cout << "---\ng dashboard: \n" << g.createDash() << endl;//odometer:0, fuel level:20, efficiency:20, tank:20, charge:100, CE:3, emode:true (constructor)
   cout << "---\nh dashboard: \n" << h.createDash() << endl;//odometer:10, fuel level:15, efficiency:15, tank:25, charge:50, CE:5, emode:true (constructor)

   cout << "\nhybridType drive test:" << endl;
   cout << "h will drive 5 miles on electric power." << endl;
   h.drive(5);//emode on begining and end, charge 25, 5 miles electric
   cout << "---\nh will drive 16 miles, 1 on electric power, 15 on gas." << endl;
   h.drive(16);//1 electric mile, 15 gas miles, charge 20.75, fuel 14, emode start on turns off then back on
   cout << "---\ne will drive 100 miles. e is below electric drive minimum. e will drive all 100 miles on gas." << endl;
   e.drive(100);//emode off, 100 miles on gas, 15 gallons, emode off, charge 10

   return 0;//end main program
}
