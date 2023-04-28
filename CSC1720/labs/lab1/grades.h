/* TerraGeode
   CSC1710-03
   Lab 1: This lab (originally lab12 of CSC1710)  will provide practice in using functions to load, process and print 1D and 2D arrays. 
      Modified to have prototypes and definitions separated.
      Make 4 copies
   File: header
   Compilation instructions: Run "g++ gradesMain.cpp gradesImp.cpp"
   be sure that the test file is in the same directory and is formatted as student name followed by 5 integer grades.
   run ./a.out
   type in the name of the data file
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/* 
   getData: load data into parallel arrays one for names, and one for scores from a file
   pre-conditions: name[] is the array used to store names, scores2d is the parallel array used to store scores, filename references a txt file with grade data formatted as a name followed by 5 grades
   post-condition: name[] and score2d[][5] will be loaded with names and scores, and the amount of array slots filled will be returned
   assumptions: a valid filename is provided, and the file is formatted correctly
*/
int getData(string name[], int score2d[][5], string fileName);

/*
   calcAvg: calculates and individual student's average
   pre-conditions: score2d references an array of grades, and index references the row of grades in score2d being averaged
   post-condition: the average of the row is returned
*/
double calcAvg(const int score2d[][5], int index); 

/*
   letterGrade: determine a student's letter grade from the average of 5 grades
   pre-conditions: score2d contains the scores being refferenced, grade is being loaded to store the letter grade, and length indicates how many array rows were used when score2d was initially loaded
   post-condition: grade will be loaded with the letter grades for each student
*/
void letterGrade(const int score2d[][5], char grade[], int length); 

/*
   printResults: print a table of grades for each student, including average and letter grade, and the overall class average
   pre-condition: name has the names of each student, score2d has the scores in rows parallel to names, grade has the letter grade of eac student parallel to name, and length references how many slots were initially loaded in names
   post-condition: a table has been output in the format of name|5 int grades|average grade|letter grade, the last line shows the average grade of the class
*/
void printResults(string name[], int score2d[][5], char grade[], int length); 
