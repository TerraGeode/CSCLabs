/*  Felecia Gonzalez
    Date: 04/13/2022
    About: This program allows a user to convert a binary number to a decimal 
          number and vice versa.
    Path: ~fgonzalez/csc1720/programs/program4/prog4.cpp
    Compilation: g++ -Wall prog4.cpp -o prog4
    Execution: ./prog4
*/
#include <iostream>
#include <cmath>
#include "arrayStack.h"
#include "linkedStack.h"

using namespace std;

long long toDeci(long long biNum);
/*  Function to convert a binary number to a decimal
     number using an arrayStack.
    Precon: A binary number is passed into function.
    Postcon: The binary number is converted to a decimal
            number and returned.
*/

long long toBi(long long deciNum);
/*  Function to convert a decimal number to a binary
     number using a linkedStack.
    Precon: a decimal number is passed into function.
    Postcon: The decimal number is convereted to a binary
            number and returned.
*/

int main() {
    long long myNum, result;//variable to hold number
    cout << "Due to limitations of int and long long variable types," << endl;
    cout << "Numbers longer than 18 digits may not be displayed," << endl;
    cout << "registered, or converted properly." << endl;

    cout << "\nBinary number: ";
    cin >> myNum;//get binary number from user

    result = toDeci(myNum);//converts myNum to decimal form

    cout << myNum << " converted " << result << endl;//displays conversion

    cout << "Decimal number: ";
    cin >> myNum;//gets decimal number from user

    result = toBi(myNum);//converts myNum to binary

    cout << myNum << " converted " << result << endl;//displays conversion

    return 0;
}

long long toDeci(long long biNum) {
    stackType<int> biStack;//variable to temporarily hold numbers
    int item;//temporary variable to hold a digit
    int n = 0;//item to track nomber of loops

    while (biNum != 0 && !biStack.isFullStack()) {
        //loops until biNum reaches 0 or biStack is full
        item = biNum % 10;//asigns item to digit in position n from right
        biNum /= 10;//removes digit in position n from right of biNum
        biStack.push(item);//adds item to stack
        n++;//increments n
    }

    long long total = 0;//variable to hold final total
    while (!biStack.isEmptyStack()) {//loops until biStack is empty
        n--;//deincrements n
        total += biStack.top() * pow(2, n);//adds top of stack multiplied by 2^n to total
        //cout << biStack.top() << " " << total << endl;
        biStack.pop();//moves to next item in stack
    }
    return total;
}

long long toBi(long long deciNum) {
    //
    linkedStackType<int> myStack;
    int item;//var to temporarily hold a number
    long long total = 0;//var to hold final number

    while (deciNum != 0) {//loops until deciNum reaches 0
        item = deciNum % 2;//sets item to 1 or 0
        deciNum /= 2;//divides deciNum by 2 rounded down
        myStack.push(item);//stores item in linked stack
    }

    while (!myStack.isEmptyStack()) {//loops until stack is empty
        total += myStack.top();//inputs digit from stack
        //cout << myStack.top() << " " << total << endl;
        total *= 10;//makes space for next digit
        myStack.pop();//moves to next item in stack
    }
    total /= 10;//removes extra digit from last run

    return total;
}