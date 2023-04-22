/*make data lol*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
ofstream oFile;

int main() {
   string name, file;
   int i = 0, j;
   srand(time(0));

   cout << "file name: ";
   cin >> file;
   oFile.open(file);
   cout << "person name: ";
   cin >> name;
   while (name != "end" && i < 28) {
      oFile << name;
      for (j = 0; j < 5; j++) {
         oFile << " " << rand() % 101;
      }
      oFile << endl;
      i++;
      cout << i << endl;
      cout << "person name: ";
      cin >> name;
   }
   return 0;
}
