#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void randArr(int arr[], int n, int max);
void bubble(int arr[], int n, unsigned long &c);
void printA(int arr[], int n);
void copy(int arrO[], int arrN[], int n);
void selection(int arr[], int n, unsigned long &c);
void insertion(int arr[], int n, unsigned long &c)


int main() {
    int x, m;

    unsigned long s;

    srand(time(0));

    s = 0;
    x = 6;
    m = 0;

    //cout << "Elements: ";
    //cin >> x;
    //cout << "Maximum: ";
    //cin >> m;

    int *num = new int[x];
    int *ori = new int[x];

    randArr(ori, x, m);

    copy(ori, num, x);
    //printA(num, x);
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
    printA(num, x);
    cout << "Insertion steps: " << s << endl;
    cout << endl;
    s = 0;
/*
    copy(ori, num, x);
    merge(num, x, s);
    printA(num, x);
    cout << "Merge steps: " << s << endl;
    cout << endl;

    copy(ori, num, x);
    quick(num, 0, x - 1, s);
    printA(num, x);
    cout << "Quick steps: " << s << endl;
*/
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
    } else {
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    }
}

void bubble(int arr[], int n, unsigned  long &c) {
    int temp, i, j;
    i = 0;
    bool notSorted = true;
    c+=4;

    while (notSorted && i < n) {
        notSorted = false;
        c++;
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                notSorted = true;
                c+=5;
            }
        }
        i++;
        c++;
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

void selection(int arr[], int n, unsigned long &c) {
    int temp, small;
    c+=2;

    for (int i = 0; i < n; i++) {
        small = i;
        c++;
        for (int j = i + 1; j < n; j++) {
            c+=2;
            if (arr[small] > arr[j]) {
                small = j;
                c++;
            }
        }
        c+=3;
        temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
        c++;
    }
}

void insertion(int arr[], int n, unsigned  long &c) {
    int temp, j, i = 0;
    bool reverse = true;
    c+=5;

    for ( i = 0; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        c+=3;
        while (j >= 0 && temp < arr[j]) {
            c+=3;
            arr[j + 1] = arr[j];
            j--;
        }
        c++;
        arr[j + 1] = temp;
    }
}