/* Felecia Gonzalez
   Dr. Titus
   CSC1710-03
   Lab 12:This lab will provide practice in using functions to load, process and print 1D and 2D arrays. Modified to have prototypes and definitions separated.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

ifstream iFile;

int getData(string name[], int score2d[][5], string fileName);
double calcAvg(const int score2d[][5], int index); 
void letterGrade(const int score2d[][5], char grade[], int length); 
void printResults(string name[], int score2d[][5], char grade[], int length); 

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

int getData(string name[], int score2d[][5], string fileName) {//Read name and scores into an array (also return a list length)
   static int i = 0, j;//declare needed variables

   iFile.open(fileName);//opens an input file

   while (iFile && i < 28) {//runs until array full or file ends
      iFile >> name[i];

      for (j = 0; j < 5; j++) {//inputs values into the scores array for the index parallel to the name index
         iFile >> score2d[i][j];
      }

      i++;//increments i
   }

   return i;//returns the length
}

double calcAvg(const int score2d[][5], int index) {
   static double result, sum = 0;//declare needed variables
   static int i;

   for (i = 0; i < 5; i++) {//add all of the scores in a "row" together
      sum += score2d[index][i];
   }

   result = sum / 5.0;//calculate the average value
   sum = 0;//fixes issue where sum is not reset between runs

   return result;//returns the average
}

void letterGrade(const int score2d[][5], char grade[], int length) {
   static int i;
   static double avg;
   static char result;//declare needed variables

   for (i = 0; i < length; i++) {//for each index value, find the average, and assign a grade letter to the parallel
      avg = calcAvg(score2d, i);//finds the average for the index i

      if (avg <= 100 && avg >= 90) {//determines the letter grade for each index
         result = 'A';
      } else if (avg < 90 && avg >= 80) {
         result = 'B';
      } else if (avg < 80 && avg >= 70) {
         result = 'C';
      } else if (avg < 70 && avg >= 60) {
         result = 'D';
      } else if (avg < 60) {
         result = 'F';
      }

      grade[i] = result;//assigns the result to the parallel index
   }
}

void printResults(string name[], int score2d[][5], char grade[], int length) {//Output names, 5 scores, avg score, and letter grade for all students
   static int i, j;//declare required variables
   static double sum = 0, result;

   cout << "Student Names|Student Test Scores |Average|Letter Grade" << endl;
   for (i = 0; i < length; i++) {//loops index to array length
      cout << setw(13) << name[i] << "|";//outputs name
      for (j = 0; j < 5; j++) {//outputs all scores for a student
         cout << setw(4)  << score2d[i][j];
         sum += score2d[i][j];
      }
      cout << "|" << setw(7) << calcAvg(score2d, i) << "|";//output average score
      cout << setw(12) << grade[i] << endl;//outputs letter grade
   }
   cout << "Class average: " << sum / (length * 5) << endl;
}
