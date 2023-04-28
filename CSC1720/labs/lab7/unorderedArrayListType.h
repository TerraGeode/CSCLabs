/* TerraGeode
   TerraGeode~/csc1720/labs/lab7/unorderedArrayListType.h
   header file for unorderedArrayListType
*/
#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE

#include <string>
#include "arrayListType.h" 

class unorderedArrayListType: public arrayListType
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt Function inserts an item at a particular location
         Precondition: a string and location are passed in
         Postcondition: the string is inserted at location and
                       all other items are shifted appropriately.
                       an error will be displayed if list is full or
                       location is out of range.
      */
      void insertAt(int location, string insertItem);
  
      /* insertEnd Function add a sting at the end of list
         Precondition: a string is passed in
         Postcondition: string is added to the end of list unless list is full
      */
      void insertEnd(string insertItem);

      /* replaceAt Function swaps a string with another string
         Precondition: a string and location are passed in
         Postcondition: the string over rides the string in the desired location
                       if location is out of range, an error is displayed
      */
      void replaceAt(int location, string repItem);
  
      /* seqSearh Function look for the location of a string
         Precondition: a string is passed in
         Postcondition: the loctation of a matching string is returned
                       unless none is found in which case -1 is returned
      */
      int seqSearch(string searchItem) const;

}; 

#endif
