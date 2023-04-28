/*
   TerraGeode
   CSC 1720
   Lab2.cpp
   About: Store data of up to 50 people. 
    Find and print the data of all people with a matching searched age.
   Copilation: g++ Lab2.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin;//associates fin with the ifstream

struct dateType {
   int month;
   int day;
   int year;
};

struct personType {
   string first;
   string last;
   int id;
   dateType birthday;
};

int loadInfo(personType persons[]);
/* 
   Load data into an array of up to 50 structs from a file
   Requires a file name, and an array of people
   Returns the amount of slots used, array is loaded
   Assumes file is a valid file and formatted correctly (FN LN ID MM DD YYYY)
*/

void readDate(dateType &myDate);
/*
   Get date from user
   Requires a dateType and user input
   Returns a loaded dateType
   Assumes Date formatted as MM DD YYYY
*/

int calcAge(dateType myPerson, dateType myDay);
/*
   Calculates a person’s age
   Requires a person’s birthday and today’s date
   Returns an int for an age
*/

void printInfo(personType person, dateType myDay);
/*
   Prints the information of a single person
   Needs a personType and today's date
   Outputs as FN LN ID MM DD YYYY age
*/

void searchAge(personType persons[], dateType myDay, int length);
/*
   Search for and print the information of all people of a certain age
   Requires an array of people, today’s date, and an age, and an array length
   Prints the information of all people with a matching age, otherwise says no matching people
*/

int main() {
   personType people[50];
   int size;
   dateType today;//initialize variables

   size = loadInfo(people);//assings the length of people to size

   readDate(today);

   searchAge(people, today, size);
   return 0;
}

int loadInfo(personType persons[]) {
   static int cnt;
   static string name, fileName;
   cnt = 0;//declare and initialize variables

   cout << "Please input file name." << endl;
   cin >> fileName;//get file name from user

   fin.open(fileName);//opens the given file

   fin >> name;//temporarily holds the name variable to check the fstream

   while (fin && cnt < 50) {//runs unti eof or 50 persons are stored
      persons[cnt].first = name;
      fin >> persons[cnt].last >> persons[cnt].id >> persons[cnt].birthday.month >> persons[cnt].birthday.day >> persons[cnt].birthday.year;//assigns values from data file

   cnt++;//increases cnt

   fin >> name;
   }

   fin.close();//closes the input file

   return cnt;//retunrs the length of the personType array
}

void readDate(dateType &myDate) {
   cout << "What is today’s date? Format as MM DD YYYY." << endl;
   cin >> myDate.month >> myDate.day >> myDate.year;
}

int calcAge(dateType myPerson, dateType myDay) {
   static int result;//declare variable
   result = myDay.year - myPerson.year;//determines age bassed only off year

   if ((myDay.month < myPerson.month) || (myDay.month == myPerson.month && myDay.day < myPerson.day)) {//determines whether or not birthday has passed
      result--;//decreases age by one year if birthday has not passed
   }
   return result;
}

void printInfo(personType person, dateType myDay) {
   cout << person.first << " " << person.last << " " << person.id << " " << person.birthday.month << "/" << person.birthday.day << "/" << person.birthday.year << " " << calcAge(person.birthday, myDay) << endl;
}

void searchAge(personType persons[], dateType myDay, int length) {
   static int age, i, cnt;
   cnt = 0;//declare and initialize variables

   cout << "Please input an age" << endl;//Get age from user
   cin >> age;

   for (i = 0; i < length; i++) {//loops until all slots checked
      if (calcAge(persons[i].birthday, myDay) == age) {//checks if ages match
         printInfo(persons[i], myDay);
         cnt++;//counts matches found
      }
   }
   if (cnt == 0) {//checks if no matches were found
      cout << "No matches found" << endl;
   }
}
