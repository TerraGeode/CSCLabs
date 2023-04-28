/*
   TerraGeode
   CSC1720
   Lab 3 : counterType.cpp
   About/goals:
      modular programming
      defining the class in a header file (.h file extension)
      implementing the methods in an implementation file (.cpp file extension)
      tracing and utilizing a program to test the class created – labTest.cpp
      compiling a program that involves two .cpp files and one header file.
*/

#include <iostream>

using namespace std;

class counterType {
   private:
      int counter;
   public:
      void initializeCounter();
         /*
            assigns a default value to a counterType post creation
            requires an already declared counter
            results in a counter value of 0
         */

      void setCounter(int cnt = 0);
         /*
            set counter to a particular positiv value
            rquires a declared counter and an integer
            reassigned counter
         */

      int getCounter() const;
         /*
            return the value of the counter
            requires a defined counter
            counter value is returned
         */

      void incrementCounter();
         /*
            inclrease the value of counter by 1
            rquires a defined counter
            counter is increased by 1
         */

      void decrementCounter();
         /*
            decrease the value of counter by 1
            requires a defined counter
            counter is decreased by 1 unless it becomes negative
         */

      void displayCounter() const;
         /*
            outputs counter value
            requires a defined counter
            the current value of counter is output to the command line
         */

      counterType(int cnt);
         /*
            counterType class constructor
            requires an int value
            int value is assigned to counter unless it is negative
         */

      counterType();//constructor, assigns counter to 0
};
