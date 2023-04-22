/*  Felecia Gonzalez
    Date: 04/28/2022
    Path: ~fgonzalez/csc1710/programs/Program5/prog5.cpp
    About: The goal of this program was to create a guessing game where a user can
          choose between guessing the top cards rank or suit.
    Compilation g++ prog5.cpp -o cards
    Execution: ./cards

    Notes/other: I did not want to mess what ever is seeding random_shuffle,
                so I made the deck get shuffled between 1 and 7 times between
                games to increase randomness.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct card {
    string name;
    string rank;
    string suit;
};

void createDeck(vector<card> &myDeck);
/*  Function to create a deck of cards
    Precon: an empty card vector is passed in.
    Postcon: the card vector is loaded with cards
*/

bool gameSuit(const string suit);
/*  Function to guess and compare suits
    Precon: suit of top card is passed in
    Postcon: returns true if guess is correct
*/

bool gameRank(const string rank);
/*  Function to guess and compare card rank
    Precon: rank of card is passed in
    Postcon: returns true if guess is correct
*/

int main() {
    srand(time(0));//sets seed based on time

    vector<card> deck;//vector to contain card deck
    bool correct;//variablt to hold wheather or not a guess is correct
    int choice, score = 0;//player choice of game/replay and score counter
    int shuffles;//variable to hold amout of times deck is shuffle between games
    int shuffled;//tracks how many times deck was shuffled

    createDeck(deck);//generate the deck

    do {
        shuffles = rand() % 7 + 1;//sets deck to shuffle 1-7 times

        for (shuffled = 0; shuffled <= shuffles; shuffled++) {
            random_shuffle(deck.begin(), deck.end());//shuffles deck 1-7 times
        }

        cout << "Enter 1 to guess rank." << endl;
        cout << "Enter 2 to guess suit." << endl;
        cin >> choice;//get game choice from user

        cout << endl;//spacing

        if (choice == 1) {
            correct = gameRank(deck[0].rank);//determines whether user guess was right
        } else if (choice == 2) {
            correct = gameSuit(deck[0].suit);//determines whether user guess was right
        }

        cout << deck[0].name << endl;//outputs the name of the top card

        if (correct) {//reveals results
            cout << "You got it right!" << endl;
            score++;//increments score if correct
        } else {
            cout << "Incorrect, sorry." << endl;
        }

        cout << "Correct guesses: " << score << endl;//displays number of correct guesses

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//spacing

        cout << "Enter 1 to play again, enter any other number to quit." << endl;
        cin >> choice;//get user choice on replaying

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//spacing
    } while (choice == 1);//loops until user chooses 1 at end of gain

    return 0;
}

void createDeck(vector<card> &myDeck) {
    card temp;//card to temporarily hold information

    for (int i = 0; i < 4; i++) {//loop for suit
        for (int j = 0; j < 13; j++) {//loop for rank
            switch (j) {//rank switch statement
                case 0 :
                    temp.name = "Ace";
                    temp.rank = "A";
                    break;
                case 1 :
                    temp.name = "2";
                    temp.rank = "2";
                    break;
                case 2 :
                    temp.name = "3";
                    temp.rank = "3";
                    break;
                case 3 :
                    temp.name = "4";
                    temp.rank = "4";
                    break;
                case 4 :
                    temp.name = "5";
                    temp.rank = "5";
                    break;
                case 5 :
                    temp.name = "6";
                    temp.rank = "6";
                    break;
                case 6 :
                    temp.name = "7";
                    temp.rank = "7";
                    break;
                case 7 :
                    temp.name = "8";
                    temp.rank = "8";
                    break;
                case 8 :
                    temp.name = "9";
                    temp.rank = "9";
                    break;
                case 9 :
                    temp.name = "10";
                    temp.rank = "10";
                    break;
                case 10 :
                    temp.name = "Jack";
                    temp.rank = "J";
                    break;
                case 11 :
                    temp.name = "Queen";
                    temp.rank = "Q";
                    break;
                case 12 :
                    temp.name = "King";
                    temp.rank = "K";
                    break;
            }

            temp.name += " of ";//adds space to complete card name

            switch (i) {//suit switch statement
                case 0 :
                    temp.name += "Spades";
                    temp.suit = "Spades";
                    break;
                case 1 :
                    temp.name += "Hearts";
                    temp.suit = "Hearts";
                    break;
                case 2 :
                    temp.name += "Clubs";
                    temp.suit = "Clubs";
                    break;
                case 3 :
                    temp.name += "Diamonds";
                    temp.suit = "Diamonds";
                    break;
            }

            myDeck.push_back(temp);//adds temp card to deck
        }
    }
}

bool gameSuit(const string suit) {
    string guess;

    cout << "Choose from:" << endl;
    cout << "Spades, Hearts, Diamonds, or Clubs" << endl;
    cout << "Guess: ";
    cin >> guess;//gets guess from user

    return (guess == suit);//compares answer and guess
}

bool gameRank(const string rank) {
    string guess;

    cout << "Choose from:" << endl;
    cout << "A,2,3,4,5,6,7,8,9,10,J,Q,K" << endl;
    cout << "Guess: ";
    cin >> guess;//gets guess from user

    return (guess == rank);//compares answer and guess
}