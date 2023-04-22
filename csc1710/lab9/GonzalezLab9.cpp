/* Felecia Gonzalez
   Dr. Yong Wei
   CSC1710-03
   Lab 9: using 3 user defined functions update the sales of members, print their information, and output total profit.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int updateSales (int week, string memberName) {
   //create a variable to output
   int sold;
   //get update value
   cout << "Enter amount of boxes sold by " << memberName << " during week " << week << "." << endl;
   cin >> sold;

   return sold;
}

string getFullName() {
   //declare variables
   string first, last, full;

   //get and combine names
   cout << "First name?" << endl;
   cin >> first;
   cout << "Last name?" << endl;
   cin >> last;

   full = first + " " + last;

   return full;
}

void printInfo(string member, int totalSold) {
   //output info
   cout << "Member name: " << member << ", Total boxes sold: " << totalSold << endl;
}

double profit(int totalSold) {
   //declare a var
   double price, total;

   //get price
   cout << "How much does one box cost?" << endl;
   cin >> price;
   //calc
   total = totalSold*price;

   return total;
}

int main() {
   //declare variables
   string member1, member2;
   int member1sold = 0, member2sold = 0, i, totalSales = 0;
   double profits;

   //set to show 2 decimal places
   cout << fixed << showpoint << setprecision(2) <<endl;

   //get first member's name
   member1 = getFullName();

   //find total sold over 5 weeks
   for (i = 1; i <= 5; i++) {
      member1sold += updateSales(i, member1);
   }

   //print first member info
   printInfo(member1, member1sold);

   //add to total sales
   totalSales += member1sold;

   //get second member name
   member2 = getFullName();

   //find total number sold over 5 weeks
   for (i = 1; i <= 5; i++) {
      member2sold += updateSales(i, member2);
   }

   //print second member info
   printInfo(member2, member2sold);

   //add to total sales
   totalSales += member2sold;

   //output profit sales
   profits = profit(totalSales);
   cout << "Total profit from band booster candy sales: $" << profits << endl;
  return 0;
}
