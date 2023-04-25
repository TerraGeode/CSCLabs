/* Felecia Gonzalez
   fgonzalez~/csc1720/programs/program3/arrayListType.h
   header file for arrayListType
*/
#ifndef ArrayList_TYPE
#define ArrayList_TYPE 
#include <string>

using namespace std;

template <class t>
class arrayListType 
{
   protected:
      t *list;    //array to hold the list elements
      int length;   //variable to store the length of the list
      int maxSize;  //variable to store the maximum 
                  //size of the list
   public:
      /*Constructor
        Creates an array of the size specified by the 
        parameter size. The default array size is 100.
        Postcondition: The list points to the array, 
                       length = 0, and maxSize = size;
      */
      arrayListType(int size = 100);

      //Copy constructor
      arrayListType (const arrayListType<t>& otherList);

      //Destructor
      //Deallocate the memory occupied by the array.
      virtual ~arrayListType();

      /*isEmpty Function to determine whether the list is empty
        Postcondition: Returns true if the list is empty;
                       otherwise, returns false.
      */
      bool isEmpty() const;

      /*isFull Function to determine whether the list is full
        Postcondition: Returns true if the list is full; 
                       otherwise, returns false.
      */
      bool isFull() const;

      /*listSize Function to determine the number of elements in 
        the list.
        Postcondition: Returns the value of length.
      */
      int listSize() const;

      /*maxListSize Function to determine the maximum size of the list
        Postcondition: Returns the value of maxSize.
      */
      int maxListSize() const;

      /*print Function to output the elements of the list
        Postcondition: Elements of the list are output on the 
                       standard output device.
      */
      void print() const;

      /*insertAt Function to insert insertItem in the list at the 
        position specified by location. 
        Note that this is an abstract function.
        Postcondition: Starting at location, the elements of 
                       the list are shifted down, 
                       list[location] = insertItem; length++;    
                       If the list is full or location is
                       out of range, an appropriate message 
                       is displayed.
      */
      virtual void insertAt(int location, t insertItem) = 0;

      /*insertEnd Function to insert insertItem an item at the end of 
        the list. Note that this is an abstract function.
        Postcondition: list[length] = insertItem; and length++;
                       If the list is full, an appropriate 
                       message is displayed.
      */
      virtual void insertEnd(t insertItem) = 0;

      /*removeAt Function to remove the item from the list at the 
        position specified by location 
        Postcondition: The list element at list[location] is 
                       removed and length is decremented by 1.
                       If location is out of range, an 
                       appropriate message is displayed.
      */
      void removeAt(int location);

      /*clearList Function to remove all the elements from the list 
        After this operation, the size of the list is zero.
        Postcondition: length = 0;
      */
      void clearList();

      /*seqSearch Function to search the list for searchItem.
        Note that this is an abstract function.
        Postcondition: If the item is found, returns the 
                       location in the array where the item   
                       is found; otherwise, returns -1.
      */
      virtual int seqSearch(t searchItem) const = 0;

      void getAt(const int loc, t &item) const;
      /* getAt function to return item at location loc
         precon: a location is passed in, list is not accessible to public
         postcon: item at loc is returned if item is in range
      */
};

//~~~~~~~~~~~~~~~~~arrayListType Implementation~~~~~~~~~~~~~~~~~

template <class t>
arrayListType<t>::arrayListType(int size)
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

   list = new t[maxSize];
} //end constructor

template <class t>
arrayListType<t>::~arrayListType()
{
   delete [] list;
} //end destructor

template <class t>
arrayListType<t>::arrayListType(const arrayListType<t>& otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;

   list = new t[maxSize]; 	//create the array

   for (int j = 0; j < length; j++)  //copy otherList
      list [j] = otherList.list[j];
}//end copy constructor

template <class t>
bool arrayListType<t>::isEmpty() const
{
   return (length == 0);
} //end isEmpty

template <class t>
bool arrayListType<t>::isFull() const  
{
   return (length == maxSize);
} //end isFull

template <class t>
int arrayListType<t>::listSize() const
{
   return length;
} //end listSize

template <class t>
int arrayListType<t>::maxListSize() const
{
   return maxSize;
} //end maxListSize

template <class t>
void arrayListType<t>::print() const
{
   for (int i = 0; i < length; i++)
      cout << list[i] << " ";
   cout << endl;
} //end print

template <class t>
void arrayListType<t>::removeAt(int location)
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

template <class t>
void arrayListType<t>::clearList()
{
   length = 0;
} //end clearList

template <class t>
void arrayListType<t>::getAt(const int loc, t &item) const {
   if (loc < 0 || loc >= this->length) {
      cout << "Location out of range" << endl;
   } else {
     item = this->list[loc];
   }
}
#endif
