/* TerraGeode
   CSC1710-03
   Program 4: Secure Message Center: encrypt a message using various shifts, as defined by the user. Shift should only affect letters, not capitalization or punctuation.
   88%: store up to 50 messages, use a key to retrieve and decode any messages that match the key. Also include a menu.
   +6% add an input validation - no 0 shift
   +6% allow multiple words in a message
*/

#include <iostream>
#include <string>

using namespace std;

int search(string words[]) {//look for the first empty sting in an array
   static int i;
   i = 0;//declare and initialize values

   while (words[i] != "" && i < 50) {//checks all available index spaces until an empty one is found, goes to fifty to catch storage full.
      i++;
   }

   if (i == 50) {//50 means storage is full
      i = -1;//implies mo matching index
   }

   return i;
}

string coder(const string phrase, int key) {//encrypt/decrypt a string.
   static int shift, i, temp, size;
   static string result;
   static char myChar;
   shift = key % 26;
   result = "";
   size = phrase.length();//declare and initialize variables

   for (i = 0; i < size; i++) {
      temp = static_cast<int>(phrase[i]);//assigns the ascii value to temp from phrase
      if (temp >= 65 && temp <= 90) {//checks for capital letters
         temp += shift;//shifts the ascii value up or down by the shift value
         if (temp > 90) {
            temp -= 26;//places the ascii back in the capital letter range if it goes beyond it.
         } else if (temp < 65) {
            temp += 26;//same hat
         }
      } else if (temp >= 97 && temp <= 122) {//checks for lowecase letters below follows same process except for lowercase letters.
         temp += shift;
         if (temp > 122) {
            temp -= 26;
         } else if (temp < 97) {
            temp += 26;
         }
      }
      myChar = static_cast<char>(temp);
      result.insert(i, 1, myChar);//assigns the converted ascii value to the string.
   }
   return result;//returns the modified string
}

void loadMsg(string codes[], int keys[]) {
   static int store, aKey;
   static string message;//initializes variables

   store = search(codes);//finds first empty string
   if (store == -1) {
      cout << "Storage full, please delete a message." << endl;
      return;//exits function if array is full
   }
   cout << "Please input message." << endl;
   getline(cin, message);//get entire line for user message
   

   do {
      cout << "Please input a key value." << endl;
      cin >> aKey;
   } while (aKey % 26 == 0);//ask for key until key is not divisible by 26
   keys[store] = aKey;//stores key in key array

   cin.clear();
   cin.ignore(200, '\n');//resets the input stream incase getline is called again

   codes[store] = coder(message, aKey);//encrypts the message and stores it in the array
}

void decrypt(string codes[], int keys[]) {//print the decrypted meesage for all katching keys
   static int i, key, check, decrypter;
   check = 0;//declare and initialize variables

   do {
      cout << "Input a non 0 key." <<endl;
      cin >> key;
      cin.clear();
      cin.ignore(200, '\n');//resets the input stream incase getline is called again
   } while (key == 0);//gets a non 0 key from user

   for (i = 0; i < 50;  i++) {
      if (keys[i] == key) {//checks array for matching keys
         decrypter = key * -1;
         cout << coder(codes[i], decrypter) << endl;//decrypts phrases
         check++;//counts number of matching keys
      }
   }

   if (check == 0) {//catches no matches
      cout << "No matching keys." << endl;
   }
}

void print(string codes[]) {
   static int i, check;
   check = 0;//declare and initiate variables

   for (i = 0; i < 50; i++) {
      if (codes[i] != "") {
         cout << "[" << i << "]: " <<  codes[i] << endl;//if not an empty string, outputs the encrypted message
         check++;
      }
   }
   if (check == 0) {//catches an empty array
      cout << "No messages stored. Try adding some." << endl;
   }
}

void remove(string codes[], int keys[]) {//removes a message and key from the array based off index position
   static int index;//initialize variable

   do {
      cout << "Which index would you like to delete? (0-49)" << endl;
      cin >> index;

      cin.clear();
      cin.ignore(200, '\n');//resets the input stream incase getline is called again
   } while (index < 0 || index > 49);//asks user for index until a valid index is given.

   codes[index] = "";//sets index value to an empty string
   keys[index] = 0;//sets key value to 0 (not searchable by decrypter function)
}

int main() {
   int myKeys[50], i;
   string myCodes[50]; 

   do {
      //menu/"home screen" set up
      cout << "SECURE MESSAGE CENTER\n" << endl;
      cout << "1: Store new key and message.\n" << endl;
      cout << "2: Decrypt stored message.\n" << endl;
      cout << "3: Display all stored messages.\n" << endl;
      cout << "4: Delete stored message.\n" << endl;
      cout << "5: Exit.\n" << endl;
      cin >> i;//gets users option choice

      cin.clear();
      cin.ignore(200, '\n');//resets the input stream incase getline is called again

      switch (i) {//calls function based on user choice
         case 1:
            loadMsg(myCodes, myKeys);
            break;
         case 2:
            decrypt(myCodes, myKeys);
            break;
         case 3:
            print(myCodes);
            break;
         case 4:
            remove(myCodes, myKeys);
            break;
      }
   } while (i != 5);//loops until exit value is called
   
   return 0;
}
