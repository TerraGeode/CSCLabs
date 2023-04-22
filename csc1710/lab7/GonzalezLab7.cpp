/* Felecia Gonzalez
   Dr. Wei Yong
   CSC 1710-03
   Lab 7           */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

   /*double F, C, K; //generate variables to be used

   //set out put to always show 3 decimal places
   cout << fixed << showpoint;
   cout << setprecision(3);

   //get temperature from user
   cout << "Input a temperature." << endl;
   cin >> F;

   //calculate celcius and kelvin values
   C = (F-32) * 5.0 / 9.0;
   K = C + 273.15;

   //output conversions
   cout << F << "F = " << C << "C = " << K << "K" << endl;*/


   //declare variables to be used
   double T, C, K, delta, max;

   //get initial temperature, maximum, and increments from user
   cout << "Please enter an initial Farenheit temperature, a maximum temperature, and an incremental value larger than 0." << endl;
   cin >> T >> max >> delta;

   //set table to show 3 decimal places always
   cout << showpoint << fixed;
   cout << setprecision(3);

   //create table head
   cout << "|" << setw(7) << "F" << setw(7) << "|" << setw(7) << "C" << setw(7) << "|" << setw(7) << "K" << setw(7) << "|"  << endl;
   cout << "|" << setw(42) << setfill('~') << "|" << endl;
   //create loop that generates rows of T convesion values until T > max
   while (T <= max) {
      //calculate celcius and kelvin values
      C = (T - 32) * 5.0 / 9.0;
      K = C + 273.15;

      //output current farenheit, celcius, and kelvin values
      cout << "|" << setw(10) << setfill(' ')  << T << setw(4);
      cout << "|" << setw(10) << C << setw(4);
      cout << "|" << setw(10) << K << setw(4);
      cout << "|" << endl;

      //increat curent temp by delta
      T += delta;
   }
   return 0;
}
