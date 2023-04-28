/*
   TerraGeode
   CSC1720
   lab 3 counterTypeImp.cpp
*/

#include <iostream>
#include "counterType.h"

using namespace std;

void counterType::initializeCounter() {
   counter = 0;
}

void counterType::setCounter(int cnt) {
   if (cnt >= 0) {
      counter = cnt;
   } else {
      counter = 0;
   }
}

int counterType::getCounter() const {
   return counter;
}

void counterType::incrementCounter() {
   counter++;
}

void counterType::decrementCounter() {
   if (counter != 0) {
      counter--;
   }
}

void counterType::displayCounter() const {
   cout << counter << endl;
}

counterType::counterType(int cnt) {
   if (cnt >= 0) {
      counter = cnt;
   } else {
      counter = 0;
   }
}
counterType::counterType() {
   counter = 0;
}
