/*
   TerraGeode
   ~/csc1720/labs/lab4/autoTypeImp.cpp
   About: autoType class implementation
*/

#include<iostream>
#include<string>
#include<iomanip>
#include"autoType.h"

using namespace std;

void autoType::setValues(double miles, double level, double mpg) {
   if (miles >=  0 && miles < 500000) {//verifies that miles is reasonable
      odometer = miles;
   } else {
      odometer = 0;
   }
   if (level >= 0 && level <= 30) {//checks that fuel level is reasonable
      fuel = level;
   } else {
      fuel = 10;
   }
   if (mpg > 0 && mpg < 50) {//checks that miles per gallon is reasonable
      efficiency = mpg;
   } else {
      efficiency = 20;
   }
}

string autoType::createDash() {
   static string result;//declare string var

   result = "odometer: " + to_string(odometer) + "  miles | fuel level: " + to_string(fuel) + " gallon(s) | efficiency: " + to_string(efficiency) + " mpg";//creates a string with all private variables

   return result;//returns the string created
}

void autoType::drive(double distance) {
   if (distance <= fuel * efficiency) {//checks if distance is less than or equal to the max posible distance to drive
      odometer += distance;//adds distance driven to odometer
      fuel -= distance / efficiency;//subtracts fuel used from fuel
   } else if (distance > fuel * efficiency) {//checks if distance is more than max posible drive distance
      odometer += fuel * efficiency;//adds max possible drive distance to odometer
      fuel = 0;//sets fuel to 0 indicating it to be empty
   }
}

autoType::autoType(double miles, double level, double mpg) {
   if (miles >=  0 && miles < 500000) {//verifies that miles is reasonable
      odometer = miles;
   } else {
      odometer = 0;
   }
   if (level >= 0 && level <= 30) {//checks that fuel level is reasonable
      fuel = level;
   } else {
      fuel = 10;
   }
   if (mpg > 0 && mpg < 50) {//checks that miles per gallon is reasonable
      efficiency = mpg;
   } else {
      efficiency = 20;
   }
}

autoType::autoType() {
   odometer = 0;//assign default variables to autoType
   fuel = 10;
   efficiency = 20;
}
