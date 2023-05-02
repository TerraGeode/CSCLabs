/*
   Team members: J.A, M.G, TerraGeode, A.H.
   Date: 03/01/2023
   Description: This project is a team based work. We are to implement six sorting 
      algorithms: selection sort, bubble sort, insertion sort, merge sort, quicksort,
      and heapsort. Using large datasets we should use a random number function to 
      create a dataset and test with four types of datasets: almost sorted, randomly 
      distributed, reverse sorted, and sets with many duplicates. To see how well 
      each algorithms perform we can measure the time and number of basic operations 
      (compares) each algorithm takes to sort each dataset.
*/

#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include <ctime>
#include <cmath>

using namespace std;

//struct used by TerraGeode
struct heap {
   int *S;
   int heapsize;
};

//sorts by J.A.
void insertionSort(int s[], int n, unsigned int& counter);
void bubbleSort(int s[], int n, unsigned int& counter);
//sorts by M.G
void selectionSort(int S[], int n, unsigned int& counter);
//sorts by A.H.
void exchange(int& a, int& b, unsigned int &c);
void partition (int arr[], int low, int high, int& pivotpoint, unsigned int &c);
void quicksort (int arr[], int low, int high, unsigned int &c);
void mergeSort (int n, int S[], unsigned int &c2);
void merge2 (int h, int m, const int U[], const int V[], int S[], unsigned int &c2);
//sorts by TerraGeode
void siftDown(heap &H, int i, unsigned int &counter);
int root(heap &H, unsigned int &counter);
void removeKeys(int n, heap &H, int arr[], unsigned int &counter);
void makeHeap(int n, heap &H, unsigned int &counter);
void heapSort(int n, heap &H, int S[], unsigned int &counter);
//combined (one or more people either wrote or contributed to these functions
void randArr(int S[], int n, int max);//generates data sets based off input
void printA(int S[], int n);//prints array
void shuffle(int S[], int n);
void copy(int arrO[], int arrN[], int n);//copies one array to another

int main() {
   srand(time(0));//sets seed based on time
   int m, size;//variables to determine values input into array at runtime and length of array
   unsigned int compare = 0;//variable to track how many comparisons are made
   int *original, *test;//pointers to arrays determined at run time
   clock_t start, finish;//variables to indicate start and end of a function
   double T;// variable to hold time taken by function

   //cout << "Set array length to 0 to read in a file." << endl;
   cout << "set array items to i > 1 to generate a random array with maximum value i." << endl;
   cout << "Set array items to 1 to generate an ordered list" << endl;
   cout << "Set array items to 0 to generate a nearly sorted list" << endl;
   cout << "Set array items to a negative value to generate reverse sorted list" << endl;
   cout << "Array length: ";
   cin >> size;//determine size of array
   cout << "Array items: ";
   cin >> m;//determine type of array to be generated

   original = new int[size];
   test = new int[size];//creates pointers pointing to arrays of length size

   randArr(original, size, m);//generates array based on input parameters

   cout << endl;

   copy(original, test, size);
   start = clock();
   bubbleSort(test, size, compare);//runs bubblesort
   finish = clock();
   T = double(finish - start)/double(CLOCKS_PER_SEC/1000);//calculates time taken
   cout << "BubbleSort comparisons: " << compare << endl;
   cout << "Time: " << T << " miliseconds" << endl;
   cout << endl;
   compare = 0;//resets compare

   copy(original, test, size);
   start = clock();
   selectionSort(test, size, compare);//runs selectionsort
   finish = clock();
   T = double(finish - start)/double(CLOCKS_PER_SEC/1000);//calculates time taken
   cout << "SelectionSort comparisons: " << compare << endl;
   cout << "Time: " << T << " miliseconds" << endl;
   cout << endl;
   compare = 0;//resets compare

   copy(original, test, size);
   start = clock();
   insertionSort(test, size, compare);//runs insertionsort
   finish = clock();
   T = double(finish - start)/double(CLOCKS_PER_SEC/1000);//calculates time taken
   cout << "InsertionSort comparisons: " << compare << endl;
   cout << "Time: " << T << " miliseconds" << endl;
   cout << endl;
   compare = 0;//resets compare

   copy(original, test, size);
   start = clock();
   mergeSort(size, test, compare);//runs mergesort
   finish = clock();
   T = double(finish - start)/double(CLOCKS_PER_SEC/1000);//calculates time taken
   cout << "MergeSort comparisons: " << compare << endl;
   cout << "Time: " << T << " miliseconds" << endl;
   cout << endl;
   compare = 0;//resets compare

   copy(original, test, size);
   start = clock();
   quicksort(test, 0, size - 1, compare);//runs quicksort
   finish = clock();
   T = double(finish - start)/double(CLOCKS_PER_SEC/1000);//calculates time taken
   cout << "QuickSort comparisons: " << compare << endl;
   cout << "Time: " << T << " miliseconds" << endl;
   cout << endl;
   compare = 0;//resets compare

   copy(original, test, size);
   heap myHeap;//declares a heap to use in heapsort
   start = clock();
   heapSort(size, myHeap, test, compare);//runs heapsort
   finish = clock();
   T = double(finish - start)/double(CLOCKS_PER_SEC/1000);//calculates time taken
   cout << "HeapSort comparisons: " << compare << endl;
   cout << "Time: " << T << " miliseconds" << endl;
   cout << endl;
   compare = 0;//resets compare

   return 0;
}

void insertionSort(int s[], int n, unsigned int& counter){
   //declares variables
   long int i,j;
   long int x;
   counter = 0; //counter is initialized to 0

   //for loop starts at second int, loops through array
   for (i = 0; i < n; i++){
        x = s[i]; //key value is set to specific position of array
        j = i-1;  //j becomes position of int before key
        counter++;
        //while loop compares x in array vs. previous int, swaps if int is less
        while (j>=0 && s[j] > x)
        {
                                         counter++;
           s[j+1] = s[j];
           j--;

        }
        s[j+1] = x; //position becomes new key
   }
}

void bubbleSort(int s[], int n, unsigned int& counter)
{
    //declares variables, initializes counter to 0
    long int i, j;
    counter = 0;
    bool notsorted = true; //bool variable initialized to true

    //while the array is not sorted
    while(notsorted){

      for(i=0; i<n ;i++ )//loops through aray
      {
         notsorted = false; //sets bool to false (array is sorted)
     //    counter++;
         //nested for loop
         for( j=0; j<n-i; j++)
          {
                      counter++;
                      if(s[j] > s[j+1]) //if first element is greater than second
                      {
                         notsorted = true; //bool declares array to be sorted

                          //swaps adjacent elements
                          int temp;
                          temp = s[j];
                          s[j] = s[j+1];
                          s[j+1] = temp;
                      }
          }

      }
   }
}

void selectionSort(int S[], int n, unsigned int& counter)
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

void exchange(int& a, int& b, unsigned int &c)
{
   int t = a;
   a = b;
   b = t;
}

void partition (int arr[], int low, int high, int& pivotpoint, unsigned int &c)
{
   int i, j;
   int pivotitem;

   pivotitem = arr[low];
   j= low;
   for (i = low + 1; i <= high; i++)
      if (arr[i] < pivotitem)
      {
         j++;
         exchange(arr[i], arr[j], c);
         c++;
      }
   pivotpoint = j;
   exchange(arr[low], arr[pivotpoint], c);
}

void quicksort (int arr[], int low, int high, unsigned int &c)
{
   int pivotpoint=0;

   if (high > low)
   {
      partition(arr, low, high, pivotpoint, c);
      quicksort(arr, low, pivotpoint - 1, c);
      quicksort(arr, pivotpoint + 1, high, c);
      c++;
   }
}

void mergeSort (int n, int S[], unsigned int &c2)
{
   if (n>1)
   {
      const int h = floor(n/2);
      const int m = n-h;
      int U[h], V[m];

      for(int i=0; i<h; i++)
      {
         U[i]=S[i];
         c2++;
      }

      int d=0;
      for(int j=h; j<n; j++)
      {
         V[d]=S[j];
         d++;
         c2++;
      }

      mergeSort(h, U, c2);
      mergeSort(m, V, c2);
      merge2(h ,m, U, V, S, c2);

   }
}

void merge2 (int h, int m, const int U[], const int V[], int S[], unsigned int &c2)
{
   int i, j, k;
   i=0;j=0; k=0;
   while (i<h && j<m)
   {
      if (U[i] < V[j])
      {
         S[k] = U[i];
         i++;
         c2++;
      }
      else
      {
         S[k] = V[j];
         j++;
         c2++;
      }
      k++;
   }

   if (i>=h)
   {
      while(k<h+m)
      {
         S[k]=V[j];
         c2++;
         j++;
         k++;
      }
   }
   else
   {
      while(k<h+m)
      {
         S[k]=U[i];
         c2++;
         i++;
         k++;
      }
   }
}

void siftDown(heap &H, int i, unsigned int &counter) {
   //an excessive amout of int-1 is used due to how the text book built the algorithm for indexes 1 to n.
   //c++ indexes from 0 to n-1, thus requiring an offset to be used to determine parent and child nodes.
   //all calls to siftDown have been modified to call i >= 1
   int parent = i, largerC;//parent is initialized with index i
   int siftkey = H.S[i - 1];//siftkey is item in H.S[i-1]
   bool spotFound = false;

   while (2*parent <= H.heapsize && !spotFound) {//ends if left child does not exist and spot is found
      //cout << "parent: " << H.S[parent] << endl;
      //cout << "left: " << H.S[leftC] << endl;
      counter+=2;
      if (2*parent < H.heapsize && H.S[2*parent-1] < H.S[2*parent]) {//checks if right child exists and is greater than left child
         largerC = 2*parent+1;
      } else {
         largerC = 2*parent;
      }
      if (siftkey < H.S[largerC-1]) {//checks if largerC key is bigger than siftkey
         H.S[parent-1] = H.S[largerC-1];//adjusted for true position
         parent = largerC;
      } else {
         spotFound = true;
      }
   }
   H.S[parent-1] = siftkey;//places sift key in final position
   //printA(H.S, H.heapsize);
}

int root(heap &H, unsigned int &counter) {
   int keyout = H.S[0];//gets key at S[0]
   //printA(H.S, H.heapsize);
   H.S[0] = H.S[H.heapsize - 1];//places last key at in head of root
   H.heapsize -= 1;//decreases heapsize
   siftDown(H, 1, counter);//restores heap property
   return keyout;//returns key value
}

void removeKeys(int n, heap &H, int arr[], unsigned int &counter) {
   int i;
   for (i = n; i > 0; i--) {
      arr[i-1] = root(H, counter);//places the root of H in the back of the array
      //i-1 to account for index offset to stop siftDown from breaking
   }
}

void makeHeap(int n, heap &H, unsigned int &counter) {
   int i;
   H.heapsize = n;//sets heapsize to array length
   //array arr should have alreeady been set to H.S.
   for (i = floor(n/2); i >= 1; i--){//subtrees have depth >1 from 0 to floor(n/2)
      siftDown(H, i, counter);//sifts down on all subtrees with a depth greater than 1
      //printA(H.S, H.heapsize);
   }
}

void heapSort(int n, heap &H, int S[], unsigned int &counter) {
   H.S = S;
   makeHeap(n, H, counter);//creates initial heap
   removeKeys(n, H, H.S, counter);//actual sort
}

void shuffle(int arr[], int n) {
   int temp, i, j, k;

   for (i = 0; i < 2; i++) {
      j = rand()%n;
      k = rand()%n;
      temp = arr[j];
      arr[j] = arr[k];
      arr[k] = temp;
   }
}

void randArr(int arr[], int n, int max) {
   if (max > 1) {
      for (int i = 0; i < n; i++) {
         arr[i] = (rand() % max) +1;
      }
   } else if (max == 1) {
      for (int i = 0; i < n; i++) {
         arr[i] = i;
      }
   } else if (max == 0) {
      for (int i = 0; i < n; i++) {
         arr[i] = i;
      }
      shuffle(arr, n);
   } else {
      for (int i = 0; i < n; i++) {
         arr[i] = n - i;
      }
   }
}

void printA(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void copy(int arrO[], int arrN[], int n) {
    for (int i = 0; i < n; i++) {
        arrN[i] = arrO[i];
    }
}
