/* TerraGeode
   Original Author: Teacher
   Path: ~TerraGeode/csc1720/labs/lab10/ollTest.cpp
   About: Program to test the various operations on an ordered linked list
   Compilation: g++ -Wall ollTest.cpp -o  testOrdered
   Execution: ./testOrdered
*/
  
#include <iostream>
#include "orderedLinkedList.h"
 
using namespace std;
 
int main()
{
   orderedLinkedList<int> list1, list2;        
   int num;                                    

   cout << "Creating list with input 77 11 44 99 33 55" << endl ;

   list1.insertLast(77);                      
   list1.insertLast(11);
   list1.insertLast(44);
   list1.insertLast(99);        
   list1.insertLast(33);
   list1.insertLast(55);

   cout << endl;                               

   cout << "list1: ";                  
   list1.print();                             
   cout << endl;                               

   list2 = list1; //test the assignment operator 

   cout << "list2: ";                 
   list2.print();                              
   cout << endl;                              

   cout << "Enter the number to be " << "deleted: ";                        
   cin >> num;                               
   cout << endl;                               

   list2.deleteNode(num);                     

   cout << "After deleting " << num << endl;
   cout << "list2: " ;         
   list2.print();                              
   cout<<endl;  

   cout << endl << "Output list1 " << "using an iterator:" << endl;            

   linkedListIterator<int> it;                  

   for (it = list1.begin(); it != list1.end(); ++it)                  
       cout << *it << " ";                        
   cout << endl;

   cout << "\nDeleting lagest item in list1." << endl;
   list1.deleteLargest();
   list1.print();
   cout << endl;     

   return 0;					
}



