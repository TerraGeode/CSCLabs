/*
   Name: Mia G
   Date: 2/20/2023
   Team members: Joellen A, Felecia G, and Alex H.
   Description: This project is a team based work. We are to implement six sorting algorithms: selection sort, bubble sort, insertion sort, merge sort, quicksort, and heapsort. Using large datasets we should use a random number function to create a dataset and test with four types of datasets: almost sorted, randomly distributed, reverse sorted, and sets with many duplicates. To see how well each algorithms perform we can measure the time and number of basic operations (compares) each algorithm takes to sort each dataset.
   References: https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9, this website gave example of how to measure time and and calculate the elasped time
*/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//Declaring prototye functions that will appear later in the program
void fillArray(int S[], int n);
void reverseArray(int S[], int n);
void selectionSort(int S[], int n, int& counter);
void printArray(int S[], int n);

int main()
{
   //Declared variables
   int array[100], compares = 0, c = 0;

   fillArray(array, 100); //Calling fillArray function

   cout << "Random list: ";
   printArray(array, 100); //Calling printArray function
   cout << endl;

   clock_t begin = clock(); //Start is set to clock()
   selectionSort(array, 100, c); //Calling selectionSort function
   clock_t finish = clock(); //End is set to clock()
   
   double time = double(finish - begin)/double(CLOCKS_PER_SEC*1000); //Calculating the measure time in milleseconds

   cout << "Selection sort list: ";
   printArray(array, 100); //Calling printArray function
   cout << endl;

   cout << "Time measured in milliseconds: " << time << endl;
   cout << "Number of compares: " << c << endl;
   cout << endl;

   reverseArray(array, 100); //Calling reverseArray function

   cout << "Reverse list: ";
   printArray(array, 100); //Calling printArray function
   cout << endl;

   clock_t start = clock(); //Start is set to clock()
   selectionSort(array, 100, compares); //Calling selectionSort function
   clock_t end = clock(); //End is set to clock()
   
   double elasped = double(end - start)/double(CLOCKS_PER_SEC*1000); //Calculating the measure time in milleseconds

   cout << "Selection sort list: ";
   printArray(array, 100); //Calling printArray function
   cout << endl;

   cout << "Time measured in milliseconds: " << elasped << endl;
   cout << "Number of compares: " << compares << endl;

   return 0;
}

/*
   fillArray function randomly stores 100 numbers in an array
*/
void fillArray(int S[], int n)
{
   srand(time(0)); //Initialize random number generator

   //The for loop stores the numbers up to 100 in the array
   for(int i = 0; i < n; i++)
   {
      //Declared an integer that stores a random number
      int numRand = (rand() % n);
      S[i] = numRand; //Storing the numbers in the array
   }
}

/*
   reverseArray function reverses the numbers in descending order
*/
void reverseArray(int S[], int n)
{
   //Declared variable
   int temp;

   //The nested for loop compares the two numbers
   for(int i = 0; i < n; i++)
   {
      for(int j = i + 1; j < n; j++)
      {
         if(S[j] > S[i]) //The second number is greater than the first number
         {
            //The two numbers are swaped
            temp = S[i];
            S[i] = S[j];
            S[j] = temp;
         }
      }
   }
}

/*
   selectionSort function sorts the numbers in ascending order and counts the number of compares
*/
void selectionSort(int S[], int n, int& counter)
{
   //Declared variables
   int small, temp;

   //The nested for loop compares the two numbers
   for(int i = 0; i < n - 1; i++)
   {
      small = i; //small is set to i
      //counter++;
      for(int j = i + 1; j < n; j++)
      {
         counter++; //incrementing counter by 1
         if(S[j] < S[small]) //The second number is smaller than the first number
         {
            small = j; //small is set to j
         }
      }
      //The two numbers are swaped
      temp = S[small];
      S[small] = S[i];
      S[i] = temp;
   }
}

/*
   printArray function outputs the list of numbers
*/
void printArray(int S[], int n)
{
   for(int i = 0; i < n; i++)
   {
      cout << S[i] << " ";
   }
   cout << endl;
}