/* Felecia Gonzalez
   Original Author: Dr. Titus
   Path: ~feleciagonzalez/csc1720/labs/lab10/ullTest.cpp
   About: This program tests various operations of an unordered linked list
   Compilation: g++ -Wall ullTest.cpp -o  testUnordered
   Execution: ./testUnordered
*/

#include<iostream>
#include"unorderedLinkedList.h"

using namespace std; 

template<class Type>
double findAvg(unorderedLinkedList<Type> &aList);
/*find the average value of a list and return it
  precon: List info is stored in aList
  postcon: Average value of the list is calculated and
          returned if list is not empty.
*/

int main()
{
   unorderedLinkedList<int> listA, listB;          
   int num;                                        

   cout << "Creating list with input 22 7 48 93 14 2 " << endl ;

   listA.insertLast(22);                      
   listA.insertLast(7);
   listA.insertLast(48);
   listA.insertLast(93);        
   listA.insertLast(14);
   listA.insertLast(2);
   
   cout << endl;                                   

   cout << "listA: ";                      
   listA.print();                                  
   cout << endl;                                   

   cout << "Length of listA: " << listA.length() << endl;
   cout << "Average of listA: " << findAvg(listA) << endl;

   listB = listA;	   //test the assignment operator 

   cout << endl;
   cout << "listB: ";                     
   listB.print();                                  
   cout << endl;                                   

   cout << "Length of listB: " << listB.length() << endl;                 

   cout << endl;
   cout << "Enter the number to be " << "deleted: ";                           
   cin >> num;                                     

   listB.deleteNode(num);                          
	
   cout << "After deleting " << num << endl;
   cout << "listB: " ;                     
   listB.print();                                  
   cout << endl;                                

   cout << "Length of listB: " << listB.length() << endl;              
   cout << endl;

   cout << "Output listA " << "using an iterator:" << endl;            

   linkedListIterator<int> it;                  

   for (it = listA.begin(); it != listA.end(); ++it)                  
       cout << *it << " ";                        
   cout << endl;

   cout << "\nRemoving largest item in listA." << endl;
   listA.deleteLargest();
   listA.print();
   cout << "\n" << endl;

   unorderedLinkedList<char> listC;          
   char x;                                 

   cout << endl << "Creating list with input A K M G ! C " << endl ;

   listC.insertLast('A');                      
   listC.insertLast('K');
   listC.insertLast('M');
   listC.insertLast('G');        
   listC.insertLast('!');
   listC.insertLast('C');
       
   cout << endl;                                   

   cout << "listC: ";                      
   listC.print();                                  
   cout << endl;                                   
   cout << "Length of listC: " << listC.length() << endl;  

   cout<< endl << "Enter the character to be " << "deleted: ";                           
   cin >> x;                                     

   listC.deleteNode(x);                          
	
   cout << "After deleting " << x << endl;
   cout << "listC: " ;                     
   listC.print();                                  
   cout << endl;                         

   return 0;					
}

template<class Type>
double findAvg(unorderedLinkedList<Type> &aList){
    double total = 0, avg;//declare and initialize values
    linkedListIterator<Type> lLI;//creates an iterator

    for (lLI = aList.begin(); lLI != aList.end(); ++lLI) {//iterates through list
        total += *lLI;//increases total by info
    }

    avg = total / aList.length();//divides total by length of list

    return avg;
}