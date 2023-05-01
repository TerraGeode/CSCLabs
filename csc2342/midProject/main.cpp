//genorate dataset
//
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void printArray(int arr[], int size);
void exchange(int& a, int& b, unsigned int &c);
void partition (int arr[], int low, int high, int& pivotpoint, unsigned int &c);
void quicksort (int arr[], int low, int high, unsigned int &c);

void mergeSort (int n, int S[], unsigned int &c2);
void merge2 (int h, int m, const int U[], const int V[], int S[], unsigned int &c2);

int main ()
{
   
   int arr[] = {10, 7, 8, 9, 3, 4};
   int high = sizeof(arr)/sizeof(arr[0]);
   int low = 0;
   unsigned int c, c2;
   
   double finaltime, finaltime2;
   
   clock_t start = clock();
//   quicksort(arr,low,high-1, c);
   clock_t finish = clock();
   printArray(arr, high);
   
   clock_t start2 = clock();
   mergeSort(high, arr, c2);
   clock_t finish2 = clock();
   printArray(arr, high);

   cout << c << endl;
   cout << c2 << endl;
   
   finaltime=double(finish-start)/double(CLOCKS_PER_SEC*1000);
   cout << "You took " << fixed << finaltime << " milliseconds\n";
   
   finaltime2=double(finish2-start2)/double(CLOCKS_PER_SEC*1000);
   cout << "You took " << fixed << finaltime << " milliseconds\n";
   
   return 0;
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

void exchange(int& a, int& b, unsigned int &c)
{
   int t = a;
   a = b;
   b = t;
   c++;
}

void printArray(int arr[], int size)
{
   int i;
   for (i=0; i<size; i++)
      cout << arr[i] << " ";
   cout << endl;
}


//----MergeSort
 
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
