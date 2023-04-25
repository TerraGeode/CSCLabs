/* Written by Dr. Titus
   Modified by Felecia Gonzalez
   unorderedArrayListType header file
*/
#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 

class unorderedArrayListType: public arrayListType
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt Function insert something at the specified location
         Precondition: the array has everything stored normally
         Postcondition: the item at the desired is moved to the back of the list
                        the new item is placed at the desired postion, length is increased by one
      */
      void insertAt(int location, int insertItem);
  
      /* insertEnd Function add a new item to the end of a list
         Precondition: the array exists normally
         Postcondition: new item is added at list[length], and length is incremented by 1
      */
      void insertEnd(int insertItem);

      /* replaceAt Function old item is replaced with a new item
         Precondition: array exists as is
         Postcondition: new item overrides old item at location. length does not change
      */
      void replaceAt(int location, int repItem);
  
      /* seqSearh Function find the location of a desired item
         Precondition: location of item searchItem is unknown
         Postcondition: location of item matching searchItem is returned
                        if searchItem DNE, returns -1
      */
      int seqSearch(int searchItem) const;

      /* removeAt Function remove an item from the list
         precon: array exists as is
         postcon: old item is overrode by item at the end of the list
                  length is decreased by 1
      */
      void removeAt(int location);
      
      /*insertFirst function inserts an item at begining of list
        precon: array exists as is
        postcon: old first item is moved to end
                 new item is place at begining
                 length increases by 1
      */
      void insertFirst(int insertItem);

}; 

#endif
