/* Felecia Gonzalez
   main test file for unorderedArrayListType and arrayListType
   to compile: g++ arrayMain.cpp arrayListType.cpp unorderedArrayListType.cpp -o Lab6
   or:         g++ arrayMain.cpp arrayListType.o unorderedArrayListType.o -0 Lab6
   to execute: ./Lab6
*/
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include <iostream>
using namespace std;

int main() {
    cout << "creating new arrayListTypes.\n"
         << "a uses the default constructor." << endl;
    unorderedArrayListType a;//default version
    cout << "b uses an invalid parameter." << endl;
    unorderedArrayListType b(-15);//invalid parameter
    cout << "c uses a valid parameter" << endl;
    unorderedArrayListType c(20);//valid parameter

    cout << "unorderedArrayListType a empty: " << a.isEmpty() << endl;

    cout << "unorderedArrayListType b is full: " << b.isFull() << endl;

    cout << "unorderedArrayListType c max size: " << c.maxListSize() << endl;
    
    cout << "loading unorderedArrayListType c\n"
         << "runs an extra time to test if list is full" << endl;

    for (int i = 0; i <= c.maxListSize(); i++) {//loops until list is full
        c.insertEnd(i);
    }

    cout << "printing unorderedArrayListType c" << endl;
    c.print();

    cout << "attempting to remove item at position -1 in unorderedArrayListType c" << endl;
    c.removeAt(-1);//should fail due to out of range
    cout << "removing item at position 5 in unorderedArrayListType c" << endl;
    c.removeAt(5);//removes 5 which is in position 5 and replaces it with item at end of list
    c.print();//outputs the updated list

    cout << "attempting to insert 20 at position 20 which is out of range" << endl;
    c.insertAt(20, 20);//should fail

    cout << "attempting to insert 20 at position 5" << endl;
    c.insertAt(5,20);
    c.print();//prints updated list

    cout << "looking for position with value 5 in unorderedArrayListType c:" << c.seqSearch(5) << endl; //-1
    cout << "looking for position with value 15 in unorderedArrayListType c:" << c.seqSearch(15) << endl;//16

    cout << "attempting to add -4 to the begining of unorderedArrayListType c while still full" << endl;
    c.insertFirst(-4);//should fail

    cout << "removing item at position 8 in unorderedArrayListType c" << endl;
    c.removeAt(8);

    cout << "attempting to add -4 to begining of unorderedArrayListType c with space" << endl;
    c.insertFirst(-4);//works
    c.print();//prints updated list

    cout << "finding largest value in unorderedArrayListType c: " << c.findMax() << endl;//20

    cout << "copying unorderedArrayListType c to unorderedArrayListType d using copy cunstructor" << endl;
    unorderedArrayListType d(c);
    cout << "c: ";//both should match
    c.print();
    cout << "d: ";
    d.print();

    cout << "emptying unorderedArrayListType c\n"
         << "unorderedArrayListType d should be unaffected." << endl;
    c.clearList();
    cout << "c: ";
    c.print();//shows nothing
    cout << "d: ";
    d.print();//remains unchaged

    cout << "finding the max value in empty list of unorderedArrayListType c" << endl;
    c.findMax();//displays a message and returns 0

    return 0;
}