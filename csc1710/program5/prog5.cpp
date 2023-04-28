/* TerraGeode
   CSC1710-03
   Program 5: max 90%: Start with basic copy of lab 8. Replace regular variables with variables from an imageType and pixel struct. 
   Modify code to store a P3 image as a P6 image. Call a functin (loadImage) which prompts user for an image, add image validation. 
   Add a function that outputs a P6 image file.
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

void loadImage(imageType& img) {
   static string fileName;
   static int i, j;

   do {
      cout << "Please input a .ppm image." << endl;
      cin >> fileName;

      //open in file
      inFile.open(fileName);

   } while (!inFile);//verifies that a file is open

   //read first line of file into string
   getline(inFile, img.type);

   //read second line into string
   getline(inFile, img.comment);

   //read width, height, and color max into their own ints
   inFile >> img.width >> img.height >> img.colorMax;

   if (img.width > 800 || img.height > 800) {//checks if image size is valid
      cout << "Image size larger than 800x800." << endl;
      return;//exit function early
   }

   //for loop that runs width*height times
   for (i = 0; i < img.width; i++) {
      for (j = 0; j < img.height; j++) {
         //Assign R, G, and B from file
         inFile >> img.image[i][j].red >> img.image[i][j].green >> img.image[i][j].blue;
      }
   }
   inFile.close();//closes input file
}

void outputImage(imageType& img1) {//output P6 image from P3 image
   static int i, j;
   static string imageName;//declare variables

   cout << "Input new image name (add .ppm to the end)" << endl;
   cin >> imageName;

   outFile.open(imageName);//opens new file

   //output head into pgm file
   outFile << "P6" << endl;
   outFile << img1.comment << endl;
   outFile << img1.width << " "  << img1.height << endl;
   outFile << img1.colorMax << endl;//outputs colorMax as an int

   //for loop that runs width*height times
   for (i = 0; i < img1.width; i++) {
      for (j = 0; j < img1.height; j++) {
         //assign char value
         outFile << static_cast<unsigned char>(img1.image[i][j].red);
         outFile << static_cast<unsigned char>(img1.image[i][j].green);
         outFile << static_cast<unsigned char>(img1.image[i][j].blue);
      }
   }

   //close out file
   outFile.close();
}

int main() {
   //set up variables
   imageType image1;//set up new image structs

   loadImage(image1);//load in first image

   if (image1.width > 800 || image1.height > 800) {//checks if image size is valid
      return 1;//exits program if image is too large
  }

   outputImage(image1);//outputs converted P6 image

   return 0;
}
