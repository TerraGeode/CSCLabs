/*
   TerraGeode
   ~/csc1720/programs/program2/autoType.h
   About: AutoType header file
*/

#ifndef autoType_H
#define autoType_H
#include <iostream>
#include <string>

using namespace std;

class autoType {
   private:
      double odometer;
      double fuel;
      double efficiency;
      double tankCap;
   public:
      static const double DEFAULT_ODOMETER;
      static const double DEFAULT_EFFICIENCY;
      static const double DEFAULT_TANK;

      double getOdometer() const;
         /*
            Returns odometer value
            Precon: value is stored in private odometer variable
            Postcon: odometer value is returned
         */

      double getFuel() const;
         /*
            Returns fuel level
            Precon: value is stored in private fuel variable
            Postcon: fuel value is returned
         */

      double getEfficiency() const;
         /*
            Returns fuel efficiency
            Precon: value is stored in private efficiency variable
            Postcon: efficiency value is returned
         */

      void setOdometer(double miles);
         /*
            Sets the value of odometer
            Precon: odometer has an initial value
            Postcon: odometer is assigned a new value
         */

      void setFuel(double level);
         /*
            Sets the value of fuel level
            Precon: fuel has an initial value
            Postcon: fuel is assigned a new value
         */

      void setEfficiency(double mpg);
         /*
            Sets the value of fuel efficiency
            Precon: efficiency has an initial value
            Postcon: efficiency is assigned a new value
         */

      void setTankCap(double tank);
         /*
            Sets the value of tankCap
            Precon: tankCap has an initial value
            Postcon: tankCap is assigned a new value
                     if fuel becomes greater than tankCap, fuel is set to tank cap
         */

      void setValues(double miles  = 0, double level = 10, double mpg = 20);
         /*
            Set the values of an autoType class
            pre-con: an autoType is declared and 3 doubles are passed in
            Post-con: autoType variables are assigned default values
        */

      string createDash() const;
         /*
            Create and return a string with the values of an autoType
            pre-con: an autoType containing initialized variables is called
            post-con: a string with all variables listed is returned but not printed
        */

      void drive(double distance);
         /*
            Drive and update private variables from an amount of given miles as appropriate. It is possible to run out of gas before miles is reached
            pre-con: a declared and innitialized autoType is called and a double is passed in
            post-con: all autoType variables are updated appropriately, whether the distance passed in was reached or not
         */
      void addFuel(double pumped);
         /*
            Add fuel up to tank capacity
            Precon: the tank has an amount of fuel
            Postcon: fuel is added til the tank is full or input value is met
         */

      autoType(double miles, double level, double mpg, double tank);
         /*
            constructor for an autoType
            Pre-con: 3 doubles are passed when autoType is initialized
            Post-con: autoType variables are assigned default values
         */

      autoType();
         /*
            constructor for autoType
            Pre-con: an autoType is declared with no values
            Post-con: autoType variables are assigned default values
         */
};
#endif
