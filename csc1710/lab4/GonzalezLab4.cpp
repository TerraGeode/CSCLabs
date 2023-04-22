/* Felecia Gonzalez
   Dr. Wei Yong
   CSC1710-03
   Lab 4: grades.cpp
*/

#include <iostream>
using namespace std;
int main() {

	//declare all variables
	double lab1, lab2, lab3, lab4, labAVG, quiz1, quiz2, quiz3, quizAVG, program, test, average;

	//get 4 lab grades from user and calculate lab average
	//cout << "Please enter 4 lab grades." << endl;
	cin >> lab1 >> lab2 >> lab3 >> lab4;
	labAVG = (lab1+lab2+lab3+lab4)/4.0;

	//get 3 quiz grades from user and calculate quiz average
	//cout << "Please enter 3 quiz grades." << endl;
	cin >> quiz1 >> quiz2 >> quiz3;
	quizAVG = (quiz1+quiz2+quiz3)/3.0;

	//get program grade from user
	//cout << "Please enter program grade." << endl;
	cin >> program;

	//get test grade from user
	//cout << "Please enter test grade." << endl;
	cin >> test;

	//output grade avreage
	average = 100*(labAVG*.1 + quizAVG*.1 + program*.06 + test*.1)/36;
	cout << average << "%" << endl;

	return 0;
}
