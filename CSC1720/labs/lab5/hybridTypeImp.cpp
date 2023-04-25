/*
   Felecia Gonzalez
   ~/csc1720/labs/lab5/hybridTypeImp.cpp
   hybridType implementation file
*/

#include<iostream>
#include<string>
#include"autoType.h"
#include"hybridType.h"

using namespace std;

void hybridType::setCharge(double battery) {
   if (battery <=50 && battery >= 0) {//checks that battery is between 0 and 100 percent power
      charge = battery;
   } else {//otherwise assigns a value of 100 as default
      charge = 25;
   }
}

double hybridType::getCharge() const {
   return charge;//returns the current value of charge
}

void hybridType::setChargeEfficiency(double mpc) {
   if (mpc > 0 && mpc <=5) {//checks that mpc is a reasonable number
      chargeEfficiency = mpc;
   } else {//otherwise assigns chargeEfficiency to 3
      chargeEfficiency = 3;
   }
}

double hybridType::getChargeEfficiency() const {
   return chargeEfficiency;//returns value of chargeEfficiency
}

string hybridType::createDash() const {
   static string result;
   result = autoType::createDash() + "\ncharge: " + to_string(charge) + " kWh\ncharge efficiency: " + to_string(chargeEfficiency) + " miles per kWh";//creates the string with reference to autoType createDash method
   return result;//returns the string
}

