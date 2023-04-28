/*
   TerraGeode
   CSC1720
   Program1.cpp
   About: Store, alphabetize and print the data of a 12 player soccer team. Printing is done before and after sorting
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 12

ifstream fin;

struct playerType {
   string first;
   string position;
   int games;
   int goals;
   int shots;
   int mins;
   double percentage;
};

void loadData(playerType T[], int &cnt);
/*
   Load an array of player structs
   Requires a playerType array, length counter, and the name of a file provided by user
   Length will be set and playerType array will be loaded
   Assumes file is formatted as name position games goals shots minutes
*/

void printData(playerType T[], int cnt);
/*
   Print out all the data stored in a playerType array
   Requires a playerType array and the length of the array
   A table of all players is printed
*/

void bestShot(playerType T[], int cnt);
/*
   Determines who has the highest shot percentage
   Requires a playerType array and its length
   The player with the highest percentage is output with their percentage
   Assumes there is not a tie for best
*/

void alphabetize(playerType T[], int cnt);
/*
   Reorganize a playerType array in alphabetical order
   Requires a playerType array, and an array length
   The playerType array is alphabetized
*/

int main() {
   playerType team[MAX];
   int size = 0;//declare and initialize variables

   cout << fixed << showpoint << setprecision(1);//format to show 1 decimal point

   loadData(team, size);//load data into team array

   printData(team, size);//print data as was inputed

   cout << endl;
   bestShot(team, size);//display player with highest shot percentage

   alphabetize(team, size);//reorganize team array

   cout << "\n" << "Alphabetized roster: " << endl;
   printData(team, size);//display reorganized team array
   return 0;
}

void loadData(playerType T[], int &cnt) {
   static string fileName, temp;//declare variables

   cout << "Please input file name" << endl;//Get fileName from user
   cin >> fileName;

   fin.open(fileName);//Open file

   fin >> temp;//temporarily holds name variable to check while loop

   while (fin && cnt < MAX) {//loops until file end or cnt is less than max size
      T[cnt].first = temp;//assign things from file to struct array
      fin >> T[cnt].position >> T[cnt].games >> T[cnt].goals >> T[cnt].shots >> T[cnt].mins;

      if (T[cnt].shots != 0) {//prevents /0 error
         T[cnt].percentage = static_cast<double>(T[cnt].goals) / T[cnt].shots * 100.0;//calculates and assigns shot percentage
      } else if (T[cnt].shots == 0) {
         T[cnt].percentage = 0;//assigns the value of 0 if no shots have been made
      }

      fin >> temp;//temporarily holds name variable to check while loop
      cnt++;//increments cnt

   }
   fin.close();
}

void printData(playerType T[], int cnt) {
   static int i;//initialize variable

   cout << "                        Player Stats                        " << endl;
   cout << "------------------------------------------------------------" << endl;
   cout << "Player Name | Position  | GP | Goals | Shots | Mins |  Shot%" << endl;
   cout << "____________|___________|____|_______|_______|______|_______" << endl;
   for (i = 0; i < cnt; i++) {
      cout << setw(12) << left << T[i].first << right << "|";
      cout << setw(11) << left << T[i].position << right << "|";
      cout << setw(4) << T[i].games << "|";
      cout << setw(7) << T[i].goals << "|";
      cout << setw(7) << T[i].shots << "|";
      cout << setw(6) << T[i].mins << "|";
      cout << setw(6) << T[i].percentage  << "%" << endl;//Print player data
   }
}

void bestShot(playerType T[], int cnt) {
   static playerType best;
   static int i;//declare variables

   best = T[0];//Assume T[0] is current best

   for (i = 0; i < cnt; i++) {//checks each slot for a higher percentage
      if (T[i].percentage > best.percentage) {//reassigns best if a higher percentage is found
         best = T[i];
      }
   }

   cout << best.first << " has the highest shot percentage with " << best.percentage << "%" << endl;//outputs the best shot
}

void alphabetize(playerType T[], int cnt) {
   static int i, j, name;
   static playerType temp;//declare variables

   for (i = 0; i < cnt; i++) {
      name = i;//assume T[i] belongs in position i
      for (j = i; j < cnt; j++) {
         if (T[j].first < T[name].first) {//checks to see if there is anoter player with a name that occurs earlier in the alphabet
            name = j;//sets postion j as earlier in the alphabet
         }
      }

      temp = T[i];
      T[i] = T[name];
      T[name] = temp;//swap the content of position i and name
   }
}
