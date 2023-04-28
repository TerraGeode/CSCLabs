/* TerraGeode
   TerraGeode~/csc1720/programs/program3/unorderedArrayListType.h
   header file for unorderedArrayListType
*/
#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE

#include <string>
#include "arrayListType.h" 

template <class t>
class unorderedArrayListType: public arrayListType<t>
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
      void insertAt(int location, t insertItem);
  
      /* insertEnd Function add a sting at the end of list
         Precondition: a string is passed in
         Postcondition: string is added to the end of list unless list is full
      */
      void insertEnd(t insertItem);

      /* replaceAt Function swaps a string with another string
         Precondition: a string and location are passed in
         Postcondition: the string over rides the string in the desired location
                       if location is out of range, an error is displayed
      */
      void replaceAt(int location, t repItem);
  
      /* seqSearh Function look for the location of a string
         Precondition: a string is passed in
         Postcondition: the loctation of a matching string is returned
                       unless none is found in which case -1 is returned
      */
      int seqSearch(t searchItem) const;

}; 

//~~~~~~~~~~~~~~~~~unorderedArrayListType Implementation~~~~~~~~~~~~~~~~~

template <class t>
unorderedArrayListType<t>::unorderedArrayListType(int size)
                      : arrayListType<t>(size)
{
}  //end constructor

template <class t>
void unorderedArrayListType<t>::insertAt(int location, t insertItem) 
{
   if (location < 0 || location >= this->maxSize || location > this->length)
      cout << "The position of the item to be inserted "
           << "is out of range." << endl;
   else if (this->length >= this->maxSize)  //list is full
      cout << "Cannot insert in a full list" << endl;
   else
   {
      for (int i = this->length; i > location; i--)
         this->list[i] = this->list[i - 1];	//move the elements down

      this->list[location] = insertItem; //insert the item at 
                                   //the specified position

      this->length++;	//increment the length
   }
} //end insertAt

template <class t>
void unorderedArrayListType<t>::insertEnd(t insertItem)
{
   if (this->length >= this->maxSize)  //the list is full
      cout << "Cannot insert in a full list." << endl;
   else
   {
      this->list[this->length] = insertItem; //insert the item at the end
      this->length++; //increment the length
   }
} //end insertEnd

template <class t>
void unorderedArrayListType<t>::replaceAt(int location, t repItem)
{
   if (location < 0 || location >= this->length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      this->list[location] = repItem;
} //end replaceAt

template <class t>
int unorderedArrayListType<t>::seqSearch(t searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < this->length && !found)
      if (this->list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)
      return loc;
   else
      return -1;
} //end seqSearch
#endif
