/* TerraGeode
   CSC1710-03
   Lab 11: Practice using functions to load, reorganize, and search arrays
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream iFile;

int loadArray(int arr[], string file) {
   static int i = 0, n;//create variables

   iFile.open(file);//opens input file

   iFile >> n;//n is meant to check if -1 or negative before assigining to an array slot

   while (n != -1 && iFile && i < 99) {//stops assigning after -1 or file ends or max index is reached
      if (n < 0) {//checks for negative numbers
         iFile >> n;
         continue;
      }

      arr[i] = n;//assigns input value to an array slot
      i++;//increases array index
      iFile >> n;//assign the next number to n
   }

   iFile.close();//closes input file

   return i;//returns the array length
}

void printArray(int arr[], int length) {//print a given array
   static int i;//value for getting an index in a loop

   for (i = 0; i < length; i++) {//loops until a certain index is reached
      cout << "myList[" << i << "]=" << arr[i] << endl;//outputs array index value and associated index
   }
}

void sortArray(int arr[], int length) {//sorts array from smallest to greatest
   static int i, j, smallest, temp;//used to track index locations in loops or temporarily hold values for reassignment

   for (i = 0; i < length; i++) {
      smallest = i;//assumes current index is the smallest value by default

      for (j = i + 1; j < length; j++) {
         if (arr[j] < arr[smallest]) {//checks if every value above current index i is smaller than the value of the i index
            smallest = j;//assigns index j to be the smallest if previous smallest index value is larger
         }
      }

      temp = arr[smallest];//temporarily stores smallest value
      arr[smallest] = arr[i];//assigns the value of the current index to the position of the smallest index
      arr[i] = temp;//assigns the smallest value to the current index
   }
}

double median(int arr[], int length) {//return the median of an array and outputs min, max and median values
   double median;
   static int i;

   sortArray(arr, length);//ensures order before running

   if (length % 2 == 1) {//calculates median for when length is odd
      median = arr[(length -1)/2];
      cout << "Minimum: myList[0]=" << arr[0] << endl;
      cout << "Median: myList[" << (length -1)/2 << "]=" << median << endl;
      cout << "Maximum: arr[" << length-1 << "]=" << arr[length-1] << endl;
   } else {//calculate median for when length is even
      median = (arr[length/2]+arr[length/2-1])/2.0;
      cout << "Minimum: myList[0]=" << arr[0] << endl;
      cout << "Median: (myList[" << length/2 << "]+myList[" << length/2-1 << "])/2=" << median << endl;
      cout << "Maximum: arr[" << length-1 << "]=" << arr[length-1] << endl;
   }
   return median;
}

void searchArray(const int arr[], int length) {//see how many times a particular number occured in an array, and outputs the ammount of occurences
   static int i, num, count = 0;

   cout << "Choose a positive number." << endl;
   cin >> num;//gets a number from user

   for (i = 0; i < length; i++) {
      if (arr[i] == num) {//checks each index value against the chosen number. increases count if match
         count++;
      }
   }

   cout << num << " appeared " << count << " time(s)." << endl;
}

int main() {
   string fileName;//will hold the name of the file for array loading
   int arrLength, myList[100], middle;

   cout << "Please input file name." << endl;
   cin >> fileName;//gets file from user

   arrLength = loadArray(myList, fileName);//loads the array and assigns the array length to length variable

   printArray(myList, arrLength);//prints myList before sorting

   sortArray(myList, arrLength);//sorts myList

   cout << "_______" << endl;//dividing line for readability
   printArray(myList, arrLength);//prints myList after sorting

   middle = median(myList, arrLength);//print and output min, median, and max values of myList

   searchArray(myList, arrLength);//search the array for a number defined by user in the function

   return 0;
}
