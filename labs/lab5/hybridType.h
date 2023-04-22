/*
   Felecia Gonzalez
   ~/csc1720/labs/lab5/hybrid.h
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
   public:
      void setCharge(double battery = 25);
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

      void setChargeEfficiency(double mpc = 3);
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
};
#endif
