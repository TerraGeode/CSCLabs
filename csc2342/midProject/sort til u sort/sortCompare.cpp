/*
    This code was originally written about a month before we started our midterm group project.
    Acording to my Algorithms teacher, I was not allowed to use more than two of the sorting
    functions in our group's final code.
    Most of this code was written as my class learned merge and quick sort
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void randArr(int arr[], int n, int max);//generates a random array bases off the input from max(can be put in reverse, and slightly out of order)
void bubble(int arr[], int n, unsigned long long &c);//bubble sort
void selection(int arr[], int n, unsigned long long &c);//selection sort
void insertion(int arr[], int n, unsigned long long &c);//insertion sort
void merge(int arr[], int n, unsigned long long &c);//merge sort, this portion divides the array
void combineM(int arr1[], int n1, int arr2[], int n2, int arr[], unsigned long long &c);//merge sort, this portion knits the array back together
void printA(int arr[], int n);//print arrays for debugging purposes
void quick(int arr[], int a, int b, unsigned long long &c);//quick sort, this portionlargely does basic checks
void partion(int arr[], int low, int high, int &pp, unsigned long long &c);//quick sort, this portion does most of the heavy liftiing
void copy(int arrO[], int arrN[], int n);//function to copy original array to a new array to ensure that each function worked with the same data set

int main() {
    int x, m;

    unsigned long long s;

    srand(time(0));

    //some default values for testing between itterations
    s = 0;
    x = 100;
    m = 1;

    //cout << "Elements: ";
    //cin >> x;
    //cout << "Maximum: ";
    //cin >> m;

    int *num = new int[x];
    int *ori = new int[x];

    randArr(ori, x, m);

    copy(ori, num, x);
    bubble(num, x, s);
    //printA(num, x);
    cout << "Bubble steps: " << s << endl;
    cout << endl;
    s = 0;

    copy(ori, num, x);
    selection(num, x, s);
    //printA(num, x);
    cout << "Selection steps: " << s << endl;
    cout << endl;
    s = 0;

    copy(ori, num, x);
    insertion(num, x, s);
    //printA(num, x);
    cout << "Insertion steps: " << s << endl;
    cout << endl;
    s = 0;

    copy(ori, num, x);
    merge(num, x, s);
    //printA(num, x);
    cout << "Merge steps: " << s << endl;
    cout << endl;

    copy(ori, num, x);
    quick(num, 0, x - 1, s);
    //printA(num, x);
    cout << "Quick steps: " << s << endl;

    return 0;
}

void randArr(int arr[], int n, int max) {
    int i;
    if (max > 1) {
        for (i = 0; i < n; i++) {
            arr[i] = (rand() % max) +1;
        }
    } else {
        for (i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    }
    //printA(arr, n);
}

void bubble(int arr[], int n, unsigned long long &c) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n -i -1; j++) {
            c++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection(int arr[], int n, unsigned long long &c) {
    int temp, small;

    for (int i = 0; i < n; i++) {
        small = i;
        for (int j = i + 1; j < n; j++) {
            c++;
            if (arr[small] > arr[j]) {
                small = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

void insertion(int arr[], int n, unsigned long long &c) {
    int temp, j;

    for (int i = 0; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        c++;
        while (j >= 0 && temp < arr[j]) {
            c+=1;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int n, unsigned long long &c) {
    if (n > 0) {
        int a, b;
        a = floor(n/2);
        b = n - a;
        int arrA[a];
        int arrB[b];

        for (int i = 0; i < a; i++) {
            arrA[i] = arr[i];
        }
        for (int i = 0; i < b; i++) {
            arrB[i] = arr[a+i];
        }
        merge(arrA, a, c);
        merge(arrB, b, c);
        combineM(arrA, a, arrB, b, arr, c);
    }
}

void combineM(int arr1[], int n1, int arr2[], int n2, int arr[], unsigned long long &c) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        c++;
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    c++;
    if (i < n1) {
        for (i; i < n1; i++) {
            arr[k] = arr1[i];
            k++;
        }
    } else {
        for (j; j < n2; j++) {
            arr[k] = arr1[j];
            k++;
        }
    }
}

void printA(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quick(int arr[], int a, int b, unsigned long long &c) {
    int pivotP;

    if (a < b) {
        partion(arr, a, b, pivotP, c);
        quick(arr, a, pivotP - 1, c);
        quick(arr, pivotP + 1, b, c);
    }
}

void partion(int arr[], int low, int high, int &pp, unsigned long long &c) {
    int i, j = low;
    int temp;
    int pivotI = arr[low];

    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivotI) {
            j++;
            temp = arr[j];
            arr[j]= arr[i];
            arr[i] = temp;
        }
        c+=1;
    }
    pp = j;
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
}

void copy(int arrO[], int arrN[], int n) {
    for (int i = 0; i < n; i++) {
        arrN[i] = arrO[i];
    }
}