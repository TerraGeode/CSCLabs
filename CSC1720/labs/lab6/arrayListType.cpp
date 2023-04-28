/* Written by Teacher name
   Modified by TerraGeode
   arrayListType implemetation file
   to compile : g++ -c arrayListType.cpp
*/
#include <iostream> 
#include "arrayListType.h" 
 
using namespace std;

arrayListType::arrayListType(int size)
{
   if (size <= 0)
   {
      cout << "The array size must be positive. Creating "
           << "an array of the size 100." << endl;

      maxSize = 100;
   }
   else
      maxSize = size;

   length = 0;

   list = new int[maxSize];
} //end constructor

arrayListType::~arrayListType()
{
   delete [] list;
} //end destructor

arrayListType::arrayListType(const arrayListType& otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;

   list = new int[maxSize]; 	//create the array

   for (int j = 0; j < length; j++)  //copy otherList
      list [j] = otherList.list[j];
}//end copy constructor

bool arrayListType::isEmpty() const
{
   return (length == 0);
} //end isEmpty

bool arrayListType::isFull() const  
{
   return (length == maxSize);
} //end isFull

int arrayListType::listSize() const
{
   return length;
} //end listSize

int arrayListType::maxListSize() const
{
   return maxSize;
} //end maxListSize

void arrayListType::print() const
{
   for (int i = 0; i < length; i++)
      cout << list[i] << " ";
   cout << endl;
} //end print

void arrayListType::removeAt(int location)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be removed "
           << "is out of range." << endl;
   else
   {
      for (int i = location; i < length - 1; i++)
         list[i] = list[i+1];

      length--;
   }
} //end removeAt

void arrayListType::clearList()
{
   length = 0;
} //end clearList

int arrayListType::findMax() const{
   int result;//varaible to hold highest value

   if (length == 0) {//catches empty arrays
      cout << "Cannot search an empty array, defaulting to 0." << endl;
      result = 0;//sets result to an int
   } else {
      result = list [0];// assigns first item as highest by default

      for (int i = 0; i < length; i++) {//loops for all items in list
         if (list[i] > result) {//sets result to list[i] if less than list[i]
            result = list[i];
         }
      }
   }
   return result;//returns highest value
}