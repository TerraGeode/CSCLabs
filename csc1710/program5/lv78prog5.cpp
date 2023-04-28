/* TerraGeode
   CSC1710-03
   Program 5:
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream inFile;
ofstream outFile;//associate in/out files with io stream

struct pixel {//set up a pixel variable to be refered to in program
   int red;
   int green;
   int blue;
};

struct imageType {//set up a struct variable to be refered to in program
   string type;
   string comment;
   int width, height, colorMax;
   pixel image[800][800];
};

int main() {
   //set up variables
   string fileName;
   int i, j;
   imageType original;//set up new image struct

   //get image file from user
   cout << "Please input a .ppm image." << endl;
   cin >> fileName;

   //open in and out files
   inFile.open(fileName);
   outFile.open("newImage.ppm");

   //check if in file opened
   if (!inFile) {
      cout << "Image file could not be opened." << endl; 
      return 1; //if no, exit
   }

   //read first line of file into string
   getline(inFile, original.type);

   //read second line into string
   getline(inFile, original.comment);

   //read width, height, and color max into their own ints
   inFile >> original.width >> original.height >> original.colorMax;

   //output head into pgm file
   outFile << "P6" << endl;
   outFile << original.comment << endl;
   outFile << original.width << " "  << original.height << endl;
   outFile << original.colorMax << endl;

   //for loop that runs width*height times
   for (i = 0; i < original.width; i++) {
      for (j = 0; j < original.height; j++) {
         //Assign R, G, and B from file
         inFile >> original.image[i][j].red >> original.image[i][j].green >> original.image[i][j].blue;
         //calculate grey value
         outFile << static_cast<unsigned char>(original.image[i][j].red);
         outFile << static_cast<unsigned char>(original.image[i][j].green);
         outFile << static_cast<unsigned char>(original.image[i][j].blue);
      }
   }

   //close in and out files
   inFile.close();
   outFile.close();

   return 0;
}
