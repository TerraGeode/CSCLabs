/*
   Felecia Gonzalez
   ~/csc1720/labs/lab4/autoType.h
   About: AutoType header file
*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class autoType {
   private:
      double odometer;
      double fuel;
      double efficiency;
   public:
      void setValues(double miles  = 0, double level = 10, double mpg = 20);
         /*
            Set the values of an autoType class
            pre-con: an autoType is declared and 3 doubles are passed in
            Post-con: autoType variables are assigned default values
        */

      string createDash();
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

      autoType(double miles, double level, double mpg);
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
