/* Felecia Gonzalez
   fgonzalez~/csc1720/programs/program3/uniqueArrayListType.h
   header file for uniqueArrayListType
*/
#ifndef uniqueArrayList_TYPE
#define uniqueArrayList_TYPE

#include <iostream>
#include <string>
#include "arrayListType.h"
#include "unorderedArrayListType.h"

using namespace std;

template <class t>
class uniqueArrayListType: public unorderedArrayListType<t> {
   public:
      //Constructor
      uniqueArrayListType(int size = 100);

      /* insertAt Function inserts an item at a particular location
         Precondition: a string and location are passed in
         Postcondition: the string is inserted at location and
                       all other items are shifted appropriately.
                       an error will be displayed if list is full,
                       location is out of range,
                       or a matching string already exists
      */
      void insertAt(int location, t insertItem);
  
      /* insertEnd Function add a sting at the end of list
         Precondition: a string is passed in
         Postcondition: string is added to the end of list unless list is full
                       or a matching string already exists
      */
      void insertEnd(t insertItem);

      /* replaceAt Function swaps a string with another string
         Precondition: a string and location are passed in
         Postcondition: the string over rides the string in the desired location
                       if location is out of rangeor a matching string already exist,
                        an error is displayed
      */
      void replaceAt(int location, t repItem);
};

//~~~~~~~~~~~~~~~~~uniqueArrayListType Implementation~~~~~~~~~~~~~~~~~

template <class t>
uniqueArrayListType<t>::uniqueArrayListType(int size)
                   : unorderedArrayListType<t>(size)
{
}

template <class t>
void uniqueArrayListType<t>::insertAt(int location, t insertItem) {
   if (unorderedArrayListType<t>::seqSearch(insertItem) == -1) {//ensures no matching item exists in list
      unorderedArrayListType<t>::insertAt(location, insertItem);
   } else {
      cerr << insertItem << " already exists" << endl;
   }
}

template <class t>
void uniqueArrayListType<t>::insertEnd(t insertItem) {
   if (unorderedArrayListType<t>::seqSearch(insertItem) == -1) {//ensures no matching item exists in list
      unorderedArrayListType<t>::insertEnd(insertItem);
   } else{
      cerr << insertItem << " already exists" << endl;
   }
}

template <class t>
void uniqueArrayListType<t>::replaceAt(int location, t repItem) {
   if (unorderedArrayListType<t>::seqSearch(repItem) == -1) {//ensures no matching item exists in list
      unorderedArrayListType<t>::replaceAt(location, repItem);
   } else{
      cerr << repItem << " already exists" << endl;
   }
}
#endif