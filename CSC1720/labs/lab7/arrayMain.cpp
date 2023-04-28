/* TerraGeode
   TerraGeode~/csc1720/labs/lab7/arrayMain.cpp
   main file for uniqueArrayListType
   to compile: g++ arrayMain.cpp uniqueArrayListType.cpp unorderedArrayListType.cpp arrayListType.cpp
   to execute: a.out
   other: io redirection was used in testing
         use "./a.out<names.txt" with apropriately named file.
*/

#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "uniqueArrayListType.h"
#include <iostream>
#include <string>

using namespace std;

void load(unorderedArrayListType &myList);
/*
   load the list of an unorderedArrayListType from cin statements
   precon: an unordered array and int size are passed in
   postcon: the list array is filled until array is full or input ends
*/

int main() {
   cout << "creating uniqueArrayListType a with maxSize 16" << endl;
   uniqueArrayListType a(16);

   cout << "loading items into list array" << endl;
   load(a);//loads uniqueArrayListType a
   
   cout << "printing uniqueArrayListType a" << endl;
   a.print();//prints a
}

void load(unorderedArrayListType &myList) {
   if (myList.isFull()) {//cathes full lists
       return;  
    }

    string name;//variable to hold an input value
    cin >> name;//reads name in from input

    while (cin && !myList.isFull()) {//loops until input stream ends or array is full
       myList.insertEnd(name);//adds item at end of list

       cin >> name;//pushes in the next item
    }
}