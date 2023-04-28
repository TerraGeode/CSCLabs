/*
   TerraGeode
   ~/csc1720/programs/program2/hybrid.h
   About: header file for hybrid class
*/

#ifndef hybridType_H
#define hybridType_H
#include <iostream>
#include <string>
#include "autoType.h"

using namespace std;

class hybridType: public autoType {
   private:
      double charge;
      double chargeEfficiency;
      bool electricMode;
   public:
      void setCharge(double battery = 100);
         /*
            Sets the battery’s charge level
            Pre-con: a double is passed in
           Post-con: battery charge is set to the double or a more reasonable value
         */

      double getCharge() const;
         /*
            Returns the battery’s charge level
            Pre-con: the charge is stored in a private variable
            Post con: the charge level is returned
         */

      void setChargeEfficiency(double cpm = 3);
         /*
            Set the charge efficiency
            Pre con: a double is passed in
            Post con: the charge efficiency is set to the double or a more reasonable value
         */

      double getChargeEfficiency() const;
         /*
            Returns the charge efficiency
            Pre con: the efficiency is stored in a private variable
            Post con: the charge efficiency is returned
         */

      string createDash() const;
         /*
            Return a string containing all variables in a hybridType
            Pre con: all variables are private and stored in hybridType
            Post con: all variables have been converted into a string and returned
         */

      void drive(double distance);
         /*
            Drive method designed for hybrids
            Precon: a distance is passed in
            Postcon: a distance is driven on battery while electric is true 
                    remaining distance is covered by gas or until gas runs out
                    1% battery is recovered for every 20 miles
         */

      hybridType(double miles, double level, double mpg, double tank, double battery, double cpm);
         /*
            constructor for an hybridType
            Pre-con: 6 doubles are passed when hybridType is initialized
            Post-con: hybridType variables are assigned default values
         */

      hybridType();
         /*
            Default constructor for autoType
            Pre-con: an hybridType is declared with no values
            Post-con: hybridType variables are assigned default values
         */
};
#endif
