/* TerraGeode
   CSC1710-03
   Program 3: Level 100. Create a game of rock paper scissor lizard spock. Winner is first to 3 wins, ties do not count.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

string compChoice(int game) {//this will decide what the computer will play
   int cpuNum;
   string cpuChoice;
   srand(time(0));//set the random seed

   if (game == 1) {
      cpuNum = rand() % 3;
   } else if (game == 2) {
      cpuNum = rand() % 5;
   }

   switch (cpuNum) { //asociates a number with a choice
      case 0:
         cpuChoice = "rock";
         break;
      case 1:
         cpuChoice = "paper";
         break;
      case 2:
         cpuChoice = "scissors";
         break;
      case 3:
         cpuChoice = "Spock";
         break;
      case 4:
         cpuChoice = "lizard";
         break;
   }

   return cpuChoice; //returns a string with the computers choice
}

string userChoice(int game) {
   static string result;

   if (game == 1) {//basic RPS game
      cout << "rock, paper, scissors" << endl;
      cin >> result;

      if (result != "rock" && result != "paper" && result != "scissors") {//checks against allowed for basic
         userChoice(1);//checks that the user choice is valid, otherwise asks the user for input again
      }
   } else if (game == 2) {
      cout << "rock, paper, scissors, lizard, Spock" << endl;
      cin >> result;//gets user choice

      if (result != "rock" && result != "paper" && result != "scissors" && result != "Spock" && result != "lizard" ) {
         userChoice(2);//checks that the user choice is valid, otherwise asks the user for input again
      }
   }

   return result;
}

string isWinner(string myChoice, string compChoice) {//checks both parameters to determine which choice wins
   static string result;

   if ((myChoice == "rock" || compChoice == "rock") && (myChoice == "scissors" || compChoice == "scissors" || myChoice == "lizard" || compChoice == "lizard")) {
      result = "rock";
   } else if ((myChoice == "paper" || compChoice == "paper") && (myChoice == "rock" || compChoice == "rock" || myChoice == "Spock" || compChoice == "Spock")) {
      result = "paper";
   } else if ((myChoice == "scissors" || compChoice == "scissors") && (myChoice == "paper" || compChoice == "paper" || myChoice == "lizard" || compChoice == "lizard")) {
      result = "scissors";
   } else if ((myChoice == "lizard" || compChoice == "lizard") && (myChoice == "paper" || compChoice == "paper" || myChoice == "Spock" || compChoice == "Spock")) {
      result = "lizard";
   } else if ((myChoice == "Spock" || compChoice == "Spock") && (myChoice == "rock" || compChoice == "rock" || myChoice == "scissors" || compChoice == "scissors")) {
      result = "Spock";
   }

   return result;
}

void art(string hand) {
   if (hand == "rock") {
      cout << " ____" << endl;
      cout << " VVVV" << endl;
      cout << "/=>  |" << endl;
      cout << "\\____/" << endl;
   } else if (hand == "paper") {
      cout << " ^^^^" << endl;
      cout << " ||||" << endl;
      cout << "^   |" << endl;
      cout << "\\___/" << endl;
   } else if (hand == "scissors") {
      cout << " ^  ^" << endl;
      cout << "  \\/__" << endl;
      cout << "/=> VV" << endl;
      cout << "\\____/" << endl;
   } else if (hand == "lizard") {
      cout << "/==>" << endl;
      cout << "\\ _/" << endl;
      cout << "| |" <<endl;
   } else if (hand == "Spock") {
      cout << " ^^ ^^" << endl;
      cout << " ||//" << endl;
      cout << "/=> |" << endl;
      cout << "\\___/" << endl;
   }
}

int main() {
   string userHand, cpuHand, winHand;
   int userWins = 0, cpuWins = 0, gameType;//declare and initialize variables

   cout << "Enter 1 for rock-paper-scissors.\nEnter 2 for rock-paper-scissors-lizard-Spock." << endl;//get user choice in game.
   cin >> gameType;

   //start do while loop which runs until cpu or user wins
   do {
      cout << "_____________"  << endl;//separate individual rounds

      userHand = userChoice(gameType);//get user choice

      cpuHand = compChoice(gameType);//get computer choice

      cout << "User: " << userHand << endl;//desplay hands
      art(userHand);
      cout << "Computer: " << cpuHand << endl;
      art(cpuHand);

      if (userHand == cpuHand) {//check for tie
         cout << "Tie!" << endl;
         continue;
      }

      winHand = isWinner(userHand, cpuHand);//decide winning hand

      cout << "~~~~~~~~~~" <<endl;
      art(winHand);
      cout << winHand << " wins, point goes to ";//declare winning hand

      if (userHand == winHand) {//compare winning hand to computer and user choice, increase winners win count
         userWins++;
         cout << "User!" << endl;
      } else if (cpuHand == winHand) {
         cpuWins++;
         cout << "Computer!" << endl;
      }

      cout << "User: " << userWins << endl;//show current score
      cout << "Computer: " << cpuWins << endl;
   } while (userWins != 3 && cpuWins != 3);

   cout << "======================================" << endl;
   if (userWins == 3) {//declare game winner by checking who won 3 games
      cout << "User wins the game!" << endl;
   } else if (cpuWins == 3) {
      cout << "Computer wins the game!" << endl;
   }

   return 0;
}
