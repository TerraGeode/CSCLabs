#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

struct heap {
   int *S;
   int heapsize;
};


void randArr(int S[], int n, int max);
void printA(int S[], int n);
void shuffle(int S[], int n);
void siftDown(heap &H, int i, unsigned int &counter);
int root(heap &H, unsigned int &counter);
void removeKeys(int n, heap &H, int arr[], unsigned int &counter);
void makeHeap(int n, heap &H, unsigned int &counter);
void heapSort(int n, heap &H, int S[], unsigned int &counter);

int main() {
   srand(time(0));
   int m=100, *test, size= 100; 
   unsigned int c = 0;
   double tTime;
   heap nums;

   cout << "Array length: ";
   cin >> size;
   cout << "Array items: ";
   cin >> m;

   test = new int[size];

   randArr(test, size, m);
   //printA(test, size);

   //printA(nums.S, size);
   clock_t start = clock();
   heapSort(size, nums, test, c);
   clock_t finish = clock();
   tTime = double(finish-start)/double(CLOCKS_PER_SEC*1000.0);

   //printA(test, size);
   cout << "Comparisons: " << c << endl;
   cout << "Time: " << tTime << " miliseconds" << endl;
    
   return 0;
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
   siftDown(H, 1, s);//restores heap property
   return keyout;//returns key value
}

void removeKeys(int n, heap &H, int arr[], unsigned int &counter) {
   int i;
   for (i = n; i > 0; i--) {
      arr[i-1] = root(H, s);//places the root of H in the back of the array
      //i-1 to account for index offset to stop siftDown from breaking
   }
}

void makeHeap(int n, heap &H, unsigned int &counter) {
   int i;
   H.heapsize = n;//sets heapsize to array length
   //array arr should have alreeady been set to H.S.
   for (i = floor(n/2); i >= 1; i--){//subtrees have depth >1 from 0 to floor(n/2)
      siftDown(H, i, s);//sifts down on all subtrees with a depth greater than 1
      //printA(H.S, H.heapsize);
   }
}

void heapSort(int n, heap &H, int S[], unsigned int &counter) {
   H.S = S;
   makeHeap(n, H, s);//creates initial heap
   removeKeys(n, H, H.S, s);//actual sort
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
