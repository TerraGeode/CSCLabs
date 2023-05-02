/*
   TerraGeode
   Teacher
   03/31/2023

   Program: The goal of this program is to input a file to generate a graph W, and in addition perform 
      Floyd's algorithm to generate graph Dn. This program will them read path information from a file
      and out put paths, as well as whether or not their is a path.

   Compilation: g++ floyds.cpp -o floyd
   Execution: ./floyd

*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

#define INFINITY 2000;
ifstream fin;
ofstream fout;

void printA(int arr[], int n);//function to print an array.
void printA2(int **arr, int n);//function to print 2 dimensional arrays
void makeGraph(int **arr, int n);//reads file to generate W[][]
int getNum(string vNum);//returns a number from a string passed as "vN" when N is a number.
void Floyd(int ***arr, int n, int **pArr);//Floyd's algorithm
void detPathF(int **arr, int **pArr, int q, int r);//container function to first determine if a path can be found, and then outputs the path between the two nodes
void path(int q, int r, int **pArr);//path function

int main() {
   string dat;//variable to hold data file name
   int size, rp, from, to;//size is the amount of vertices
   //rp is the amount of paths generated
   //from will be passed to path as q
   //to will be passed to path as r
   do {//gets the data file. loops until a file is found.
      cout << "Data file: ";
      cin >> dat;

      fin.open(dat);
   } while (!fin);
   fin >> size;//determine's the size of the array.

   //pointerception
   int ***W, **P;//could only get dynamic nd array working in main function
   W = new int**[size+1];//W is an array of pointers pointing to other arrays W[1:size] will represent D1:size
   P = new int*[size];//P will be a secondary array for Floyd's to store path information.
   for (int j = 0; j < size; j++) {//generating multidimensional pointer arrays
      W[j] = new int*[size];
      P[j] = new int[size];
      for (int i = 0; i < size; i++) {
         W[j][i] = new int[size];
         P[j][i] = 0;//initializing P
      }
   }
   W[size] = new int*[size];//fixes issue where last array is technically not made.
   for (int k = 0; k < size; k++) {
      W[size][k] = new int[size];
   }

   makeGraph(W[0], size);

   printA2(W[0], size);
   Floyd(W, size, P);
   cout << "P" << endl;
   printA2(P, size);


   if (!fin) {//checks if there is any path being called
      fin.close();
   } else {
      fin >> rp;
      for (int l = 0; l < rp; l++) {
         fin >> dat;//reads in data from file
         from = getNum(dat);
         fin >> dat;
         to = getNum(dat);
         detPathF(W[size], P, from, to);
      }
      fin.close();
   }

   return 0;
}

void printA(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      if (arr[i] == 2000) {//for some reason if statements do not work if I use INFINITY instead of 2000
         cout << "|" << setw(5) << "INF" << " ";
      } else {
         cout << "|" << setw(5) << arr[i] << " ";
      }
   }
   cout << "|" << endl;
}

void makeGraph(int **arr, int n) {
   int rep, p, x, y;
   string temp;
   fin >> rep;//gets how many edges there are
   for (int i = 0; i < n; i++) {//fills array with infinity
      for (int j = 0; j < n; j++) {
         if (i == j) {
            arr[i][j] = 0;
         } else {
            arr[i][j] = INFINITY;
         }
      }
   }

   //places the edges in the array
   for (int k = 0; k < rep; k++) {
      fin >> temp;
      x = getNum(temp);
      fin >> temp;
      y = getNum(temp);
      fin >> p;
      arr[x-1][y-1] = p;//offset for out of bounds issue
   }
}

int getNum(string vNum) {
   if (vNum[0] == 'v' || vNum[0] == 'D') {
      vNum.erase(0,1);
      return stoi(vNum);
   } else {
      return stoi(vNum);
   }
}

void printA2(int **arr, int n) {
   cout << "     |";
   for (int j = 0; j < n; j++) {
      cout << "  v" << j+1 << "  |";
   }
   cout << endl;
   cout << setfill('-') << setw(n*7+7) << "\n";
   cout << setfill(' ');
   for (int i = 0; i < n; i++) {
      cout << "v" << i+1 << "   ";
      printA(arr[i], n);
   }
   cout << setfill('-') << setw(n*7+7) << "\n";
   cout << setfill(' ');
}

void Floyd(int ***arr, int n, int **pArr) {
   //i starts at 1, however will be offset to account for true position of the 2d arrays
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n; j++) {
         for (int k = 0; k < n; k++) {
            if (arr[i-1][i-1][k] + arr[i-1][j][i-1] < arr[i-1][j][k]) {
               pArr[j][k] = i;
               arr[i][j][k] = arr[i-1][i-1][k] + arr[i-1][j][i-1];
            } else {
               arr[i][j][k] = arr[i-1][j][k];
            }

         }
      }
      cout << "D" << i << endl;
      printA2(arr[i], n);// prints D array as each is created.
   }
}

void detPathF(int **arr, int **pArr, int q, int r) {
   //q and r require an offset to account for true positions.
   if (arr[q-1][r-1] == 2000) {//catches no path
      cout << "There is no path from v" << q << " to v" << r << "." << endl;
   } else {
      cout << "The path from v" << q << " to v" << r << " ==>";
      path(q, r, pArr);
      cout << endl;
   }
}

void path(int q, int r, int **pArr) {
   if (pArr[q-1][r-1] != 0) {
      path(q, pArr[q-1][r-1], pArr);
      cout << " v" << pArr[q-1][r-1];
      path(pArr[q-1][r-1], r, pArr);
   }
}