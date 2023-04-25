/*
   Felecia Gonzalez
   ~/csc1720/programs/program2/hybridTypeImp.cpp
   hybridType implementation file
*/

#include<iostream>
#include<string>
#include"autoType.h"
#include"hybridType.h"

using namespace std;

void hybridType::setCharge(double battery) {
   if (battery <= 100 && battery >= 0) {//checks that battery is between 0 and 100 percent power
      charge = battery;
   } else {//otherwise assigns a value of 100 as default
      charge = 100;
      cerr << "Charge value not valid, charge set to 100%" << endl;
   }

   if (charge > 20) {
      electricMode = true;
   } else {
      electricMode = false;
   }
}

double hybridType::getCharge() const {
   return charge;//returns the current value of charge
}

void hybridType::setChargeEfficiency(double cpm) {
   if (cpm > 0 && cpm <=5) {//checks that mpc is a reasonable number
      chargeEfficiency = cpm;
   } else {//otherwise assigns chargeEfficiency to 3
      chargeEfficiency = 3;
      cerr << "Charge efficiency not valid, set to 3% per mile" << endl;
   }
}

double hybridType::getChargeEfficiency() const {
   return chargeEfficiency;//returns value of chargeEfficiency
}

string hybridType::createDash() const {
   static string result;
   result = autoType::createDash();
   result += "\ncharge: " + to_string(charge) + "%";
   result += "\ncharge efficiency: " + to_string(chargeEfficiency) + "% per mile";
   result += "\nelectric mode: " + to_string(electricMode);//creates the string with reference to autoType createDash method
   return result;//returns the string
}

hybridType::hybridType(double miles, double level, double mpg, double tank, double battery, double cpm)
   :autoType(miles, level, mpg, tank)
{
   hybridType::setCharge(battery);
   hybridType::setChargeEfficiency(cpm);
}

void hybridType::drive(double distance) {
   if (distance < 0) {//catch negatives
      distance *= -1;
   }

   if (electricMode) {//checks if electric mode is true
      cout << "electric mode is on" <<  endl;
      double edis;//declare variable to hold max distance to travel in electric power
      edis = (charge - 20) / chargeEfficiency;//calculate distance abel to be traveled until battery dips to 20%
      if (edis >= distance) {//checks if max electric distance is more than driven distance
         autoType::setOdometer(getOdometer() + distance);//increases odometer distance
         charge -= distance * chargeEfficiency;//decrease charge by percentage used
         cout << distance << " mile(s) traveled on electric power" << endl;
      } else if (edis < distance) {
         double ndis;//declare variable to hold remaining distance
         ndis = distance - edis;//subtract electric distance from total distance
         autoType::setOdometer(getOdometer() + edis);//adds electric distance to odometer
         cout << edis << " mile(s) traveled on electric power, switching to gas." << endl;
         charge = 20;//battery power is used until power reaches 20%
         autoType::drive(ndis);//drives the remaining distance on gas
         charge += ndis / 20;//adds 1% battery for every 20 miles
      }
   } else {
      cout << "electric mode is off" << endl;
      autoType::drive(distance);//drives distance on gas if electric mode is false
      charge += distance / 20;//adds 1% battery for every 20 miles
   }
   if (charge > 100) {//catches overcharging
      charge = 100;//sets charge to be back in bounds
      electricMode = true;//indicates that battery has enough power to travel on battery
      cout << "electric mode is turned on" << endl;
   } else if (charge <= 100 && charge > 20) {//checks if charge is
      electricMode = true;
      cout << "electric mode is turned on" << endl;
   } else {
      electricMode = false;//if charge is <= 20%, electricMode turns off
      cout << "electric mode is turned off" << endl;
   }

   cout << charge << "% remaining" << endl;
}

hybridType::hybridType()
   :autoType()
{
   charge = 100;
   chargeEfficiency = 3;
   electricMode = true;
}
