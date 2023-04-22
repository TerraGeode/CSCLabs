/*
   Felecia Gonalez
   ~/csc1720/programs/program2/autoTypeImp.cpp
   About: autoType class implementation
*/

#include<iostream>
#include<string>
#include"autoType.h"

using namespace std;

const double autoType::DEFAULT_ODOMETER = 0;

const double autoType::DEFAULT_EFFICIENCY = 20;

const double autoType::DEFAULT_TANK = 20;

double autoType::getOdometer() const {
   return odometer;
}

double autoType::getFuel() const {
   return fuel;
}

double autoType::getEfficiency() const {
   return efficiency;
}

void autoType::setOdometer(double miles) {
   if (miles >=  0 && miles < 1000000) {//verifies that miles is reasonable
      odometer = miles;
   } else {
      cerr << "Milage not valid, odometer set to " << DEFAULT_ODOMETER << endl;
      odometer = DEFAULT_ODOMETER;
   }
}

void autoType::setFuel(double level) {
   if (level >= 0 && level <= tankCap) {//checks that fuel level is reasonable
      fuel = level;
   } else {
      cerr << "Fuel level not valid, fuel level set to " << tankCap << endl;
      fuel = tankCap;
   }
}

void autoType::setEfficiency(double mpg) {
   if (mpg > 0 && mpg < 50) {//checks that miles per gallon is reasonable
      efficiency = mpg;
   } else {
      cerr << "Efficiency not valid, fuel efficiency set to " << DEFAULT_EFFICIENCY << endl;
      efficiency = DEFAULT_EFFICIENCY;
   }
}

void autoType::setTankCap(double tank) {
   if (tank >= 10 && tank <=50) {//check if tank size is reasonable
      tankCap = tank;
   } else {
      cerr << "Tank capacity not valid, tank capacity set to " << DEFAULT_TANK << endl;
      tankCap = DEFAULT_TANK;
   }

   if (fuel > tankCap) {//prevent fuel overflow
      fuel = tankCap;
      cout << "Fuel exceeded tank capacity, fuel level set to " << tankCap << endl;
   }
}

void autoType::setValues(double miles, double level, double mpg) {
   autoType::setOdometer(miles);
   autoType::setFuel(level);
   autoType::setEfficiency(mpg);
}

string autoType::createDash() const {
   static string result;//declare string var

   result = "odometer: " + to_string(odometer) + "miles";
   result += "\nfuel level: " + to_string(fuel) + "gallon(s)";
   result += "\nefficiency: " + to_string(efficiency) + " mpg";
   result += "\ntank capacity: " + to_string(tankCap) + "gallons";//creates a string with all private variables

   return result;//returns the string created
}

void autoType::drive(double distance) {
   if (distance < 0) {//checks if driving is done in reverse
      distance *= -1;
   }

   if (distance <= fuel * efficiency) {//checks if distance is less than or equal to the max posible distance to drive
      odometer += distance;//adds distance driven to odometer
      fuel -= distance / efficiency;//subtracts fuel used from fuel
      cout << distance << " mile(s) travelled on gas\nFuel: " << fuel << " gallon(s)" << endl;
   } else if (distance > fuel * efficiency) {//checks if distance is more than max posible drive distance
      odometer += fuel * efficiency;//adds max possible drive distance to odometer
      cout << fuel * efficiency << " mile(s) travelled" << endl;
      cout << "No fuel remaining" << endl;
      cout << distance - fuel * efficiency << " mile(s) untraveled" << endl;
      fuel = 0;//sets fuel to 0 indicating it to be empty
   }
}

void autoType::addFuel(double pumped) {
   if (pumped < 0) {//catches negative values
      cerr << "fuel cannot be removed." << endl;
      return;
   }

   if (pumped >= tankCap - fuel) {//catches tank overflow/full
      cout << "Tank full, fuel level is " << tankCap << " gallons." << endl;
      fuel = tankCap;
   } else {
      fuel += pumped;//adds pumped to fuel
      cout << "fuel level is now " << fuel << " gallon(s)" << endl;
   }
}

autoType::autoType(double miles, double level, double mpg, double tank) {
   autoType::setOdometer(miles);
   autoType::setTankCap(tank);
   autoType::setEfficiency(mpg);
   autoType::setFuel(level);
}

autoType::autoType() {
   odometer = DEFAULT_ODOMETER;//assign default variables to autoType
   fuel = DEFAULT_TANK;
   efficiency = DEFAULT_EFFICIENCY;
   tankCap = DEFAULT_TANK;
}
