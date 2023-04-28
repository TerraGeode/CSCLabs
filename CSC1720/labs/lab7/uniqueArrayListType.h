/* TerraGeode
   TerraGeode~/csc1720/labs/lab7/uniqueArrayListType.h
   header file for uniqueArrayListType
*/
#ifndef uniqueArrayList_TYPE
#define uniqueArrayList_TYPE

#include <iostream>
#include <string>
#include "arrayListType.h"
#include "unorderedArrayListType.h"

using namespace std;

class uniqueArrayListType: public unorderedArrayListType {
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
      void insertAt(int location, string insertItem);
  
      /* insertEnd Function add a sting at the end of list
         Precondition: a string is passed in
         Postcondition: string is added to the end of list unless list is full
                       or a matching string already exists
      */
      void insertEnd(string insertItem);

      /* replaceAt Function swaps a string with another string
         Precondition: a string and location are passed in
         Postcondition: the string over rides the string in the desired location
                       if location is out of rangeor a matching string already exist,
                        an error is displayed
      */
      void replaceAt(int location, string repItem);
};

#endif