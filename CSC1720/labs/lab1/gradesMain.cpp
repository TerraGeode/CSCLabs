/* Felecia Gonzalez
   Dr. Titus
   CSC1720-01
   Lab 1 :This lab(originally csc1710 lab 12) will provide practice in using functions to load, process and print 1D and 2D arrays. Modified to have prototypes and definitions separated.
   Lab 1 works on building a multi-file system
   File: main: Execute the main task of the program
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "grades.h"

using namespace std;

int main() {
   string names[28], file;
   int scores[28][5], size;
   char grades[28];

   cout << "Please input a file name." << endl;
   cin >> file;

   cout << fixed << showpoint << setprecision(1);

   size = getData(names, scores, file);//assign input data to arrays, get the size of the lists

   letterGrade(scores, grades, size);//assigns letter grades to grades array

   printResults(names, scores, grades, size);//output results

   return 0;
}
