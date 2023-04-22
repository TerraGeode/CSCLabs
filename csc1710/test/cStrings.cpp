//testing c string input/output

#include <iostream>

using namespace std;

int load(char a[]) {
   int i = 0;

   do {
   cin >> a[i];
   i++;
   } while (i > 30 && cin);
   i++;
   return i;
}
void print(char a[], int length) {
   int j;
   for (j = 0; j < length; j++) {
      cout << a[j];
   }
   cout << endl;
}
int main() {

   char test[30], test2[30];
   int length1, length2;

   length1 = load(test);

   print(test, length1);

   return 0;
}
