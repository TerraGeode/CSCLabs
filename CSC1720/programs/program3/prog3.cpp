/*  TerraGeode
    TerraGeode~/csc1720/programs/program3/GonzalezProgram3.cpp
    About: Load in a list of names from a file for a raffle.
          Each person can only win once, and each person
          can only have one entry for the grand prize. The
          user will then provide the cost of each ticket and
          the total amount of money spent on prizes. The 
          program will finish by returning the total profit
          of the raffle
    Compilation: g++ -Wall GonzalezProgram3.cpp -o prog3
    Execution: ./prog3
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "uniqueArrayListType.h"

using namespace std;

ifstream fin;//set in file stream variable

void load(unorderedArrayListType<string> &unoL, uniqueArrayListType<string> &uniL);
/*  load function to load data from a data file
    precon: unorderedArrayList and uniqueArrayListype are empty
    postcon: both unoL and uniL are loaded until end of file
*/

void winners(const unorderedArrayListType<string> &unoL, const uniqueArrayListType<string> &uniL, uniqueArrayListType<string> &win);
/*  winners determines who won the raffle from the loaded list
    precon: winner list is empty and unoL and uniL are passed in
    postcon: winners are chosen
*/

int main() {
    int max = 2000;//determines how many tickets can be sold(max array size)
    double price, costs, profit;
    string name;
    uniqueArrayListType<string> PS5Raffle(max), winter(5);
    unorderedArrayListType<string> raffle(max);//declare variables
    
    srand(time(NULL));//chooses a seed based on time

    cout << fixed << showpoint << setprecision(2);//sets output to display 2 decimal points

    load(raffle, PS5Raffle);//loads array lists

    winners(raffle, PS5Raffle, winter);//determines winners from list

    //cout << name << endl;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    //retrieve and output each winner
    winter.getAt(0, name);
    cout << name << " won the PlayStation 5!" << endl;

    winter.getAt(1, name);
    cout << name << " won a dinner for 2 at Blue Water Grille" << endl;

    winter.getAt(2, name);
    cout << name << " won 4 passes to Wet N Wild!" << endl;

    winter.getAt(3, name);
    cout << name << " won a $100 Amazon Gift Card!" << endl;

    winter.getAt(4, name);
    cout << name << " won 4 movie passes at the Palladium Regal Theater!" << endl;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    cout << "Ticket price: $";
    cin >> price;//get the price of each ticket

    cout << "Total costs: $";
    cin >> costs;//get how much money was spent

    profit = price * raffle.listSize() - costs;//calculates profits

    cout << "Profit: $" << profit << endl;//outputs profits

    return 0;
}

void load(unorderedArrayListType<string> &unoL, uniqueArrayListType<string> &uniL) {
    string file, fname, lname, name;//declare variables to hold file name and ticket names
    cout << "Please input file name: ";
    cin >> file;//get file from user

    fin.open(file);//attempts to open file provided by user

    if (fin.is_open()) {//checks if file opened successfully
        fin >> fname >> lname;

        while (fin && !unoL.isFull() && !uniL.isFull()) {//loops until a list is full or end of file
            name = fname + " " + lname;//generates list item

            unoL.insertEnd(name);//inserts item into unordered list
            
            if (uniL.seqSearch(name) == -1) {
                uniL.insertEnd(name);//inserts item into unique list if name is not in list
            }
            fin >> fname >> lname;//gets the next item in file
        }
        fin.close();//closes input file
    } else {//catches file failing to open
        cerr << "failed to open file" << endl;
    }
}

void winners(const unorderedArrayListType<string> &unoL, const uniqueArrayListType<string> &uniL, uniqueArrayListType<string> &win) {
    int num;//holds number of a winning ticket
    string name;//holds name of winner temporarily

    num = rand() % uniL.listSize();//generates a random number

    uniL.getAt(num, name);//retrieves name at desired spot

    win.insertEnd(name);//adds name to list

    for (int i = 1; i < 5; i++) {
        do {
            num = rand() % unoL.listSize();//generates a random number based off list length

            unoL.getAt(num, name);//pulls name in position num from list
        } while (win.seqSearch(name) != -1);//loops until does not match item on list

        win.insertEnd(name);//adds name to list
    }
}