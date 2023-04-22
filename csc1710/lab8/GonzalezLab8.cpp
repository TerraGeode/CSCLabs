/* Felecia Gonzalez
   Dr. Yong Wei
   CSC1710-03
   Lab 8: turn colored P3 ppm images into greyscale P2 pgm images.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   //associate in/out files with io stream
   ifstream inFile;
   ofstream outFile;

   //set up variables
   string fileName, imgType, comment;
   int width, height, colorMax, R, G, B, i;

   //get image file from user
   cout << "Please input a .ppm image." << endl;
   cin >> fileName;

   //open in and out files
   inFile.open(fileName);
   outFile.open("greyImage.pgm");

   //check if in file opened
   if (!inFile) {
      cout << "Image file could not be opened." << endl; 
      return 1; //if no, exit
   }

   //read first line of file into string
   getline(inFile, imgType);

   //read second line into string
   getline(inFile, comment);

   //read width, height, and color max into their own ints
   inFile >> width >> height >> colorMax;

   //output head into pgm file
   outFile << "P2" << endl;
   outFile << comment << endl;
   outFile << width << " "  << height << endl;
   outFile << colorMax << endl;

   //get RGB values and set up while loop
   /*inFile >> R >> G >> B;
   //check that rgbis still true
   while (R && G && B) {
      //calculate grey value
      outFile << static_cast<int>(R*.3+G*.4+B*.3) << endl;
      //reassign RGB values
      inFile >> R >> G >> B;
   }*/

   //for loop that runs width*height times
   for (i = 0; i < width*height; i++) {
      //Assign R, G, and B from file
      inFile >> R >> G >> B;
      //calculate grey value
      outFile << static_cast<int>(R*.3+G*.4+B*.3) << endl;
   }

   //close in and out files
   inFile.close();
   outFile.close();

   return 0;
}
