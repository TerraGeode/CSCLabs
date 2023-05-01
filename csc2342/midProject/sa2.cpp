/*
- nearly sorted generated array in main
- pre and post condition
- 

*/

#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include <time.h>
#include <ctime>
#include <cmath>

using namespace std;
long int c_cnt = 0;
long int m_cnt = 0;
#define MAX 100000


void insertionSort(long int s[], long int n, int& counter);
void bubbleSort(long int s[],long int n, int& counter);
void outputarray(long int s[], long int n);
void shuffle(long int s[], long int n);
void nearlysorted(long int s[], long int n); 

//INSERTION 
void insertionSort (long int s[], long int n, int& counter){
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
   cout<<endl;
   cout<<"Number of Comparisons:"<<counter<<endl;
   cout<<endl;
}

//BUBBLE
void bubbleSort (long int s[], long int n, int& counter)
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
      cout<<endl;
      cout<<"Number of Comparisons: "<<counter<<endl;
      cout<<endl;
}




int main()
{

  int n, n2, algorithm_num;
  int counter = 0;
  int count, count2;   

   n = 1000;
   long int s[n];

   for(long int i=0;i<n;i++){
      s[i]=rand()%1000;
   }



		cout<<endl; 
    cout<<"Bubble sort"<<endl;
    cout<<"-----------"<<endl;


    clock_t start2 = clock();
    bubbleSort (s, n, counter);
    clock_t finish2 = clock();

    cout<<"Sorted Array: ";
    outputarray(s, n);

    cout<<endl;
    cout<<endl;
    double finaltime2 = double(finish2-start2)/double(CLOCKS_PER_SEC*1000);
    cout << "Bubble Sort took " << finaltime2 << " milliseconds\n";




    n2 = 1000;
   long int s2[n2];

   for(long int i=0;i<n2;i++){
      s2[i]=rand()%1000;
   }


    cout<<endl;
    cout<<endl;
    cout<<"Insertion sort: "<<endl;
    cout<<"---------------"<<endl;

    clock_t start = clock();
    insertionSort (s2, n2, counter);
    clock_t finish = clock();


    cout<<"Sorted Array: ";
    outputarray(s2, n2);



cout<<endl;
cout<<endl;
double finaltime = double(finish-start)/double(CLOCKS_PER_SEC*1000); //static_cast<double>
cout << "Insertion Sort took " <<  finaltime << " milliseconds\n";

cout<<endl;


return 0; 


}


void outputarray(long int s[], long int n)
{
  for(long int i=0; i<n; i++)
  {
    // nearlysorted(a, n); 
         cout<<s[i]<<" ";

  }

}

void nearlysorted(long int s[], long int n)
{

   int max; 
   if (max > 1) {
      for (int i = 0; i<n; i++)
      {
         s[i] = (rand() % max) +1;
      }
   }else if (max ==1) {
      for (int i = 0; i<n; i++)
      {
         s[i] = i; 
      }
   }else if (max ==0) {
      for (int i = 0; i<n; i++)
      {
         s[i] = i;
      }
      shuffle(s, n);
   }else {
      for(int i=0; i<n; i++) {
         s[i] = n-i; 
      }
   }
}


void shuffle(long int s[], long int n)
{
  long int temp, i, j, k;

  for(i=0; i<2; i++)
  {
     j = rand()%n;
     k = rand()%n;
     temp = s[j];
     s[j] = s[k];
     s[k] = temp; 
  }

}

