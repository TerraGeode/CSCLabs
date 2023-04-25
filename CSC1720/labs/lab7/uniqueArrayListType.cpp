/* Felecia Gonzalez
   fgonzalez~/csc1720/labs/lab7/uniqueArrayListType.cpp
   implementation file for uniqueArrayListType
*/
#include <iostream>
#include <string>
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "uniqueArrayListType.h"

using namespace std;

uniqueArrayListType::uniqueArrayListType(int size)
                   : unorderedArrayListType(size)
{
}

void uniqueArrayListType::insertAt(int location, string insertItem) {
   if (unorderedArrayListType::seqSearch(insertItem) == -1) {//ensures no matching item exists in list
      unorderedArrayListType::insertAt(location, insertItem);
   } else {
      cerr << insertItem << " already exists" << endl;
   }
}

void uniqueArrayListType::insertEnd(string insertItem) {
   if (unorderedArrayListType::seqSearch(insertItem) == -1) {//ensures no matching item exists in list
      unorderedArrayListType::insertEnd(insertItem);
   } else{
      cerr << insertItem << " already exists" << endl;
   }
}

void uniqueArrayListType::replaceAt(int location, string repItem) {
   if (unorderedArrayListType::seqSearch(repItem) == -1) {//ensures no matching item exists in list
      unorderedArrayListType::replaceAt(location, repItem);
   } else{
      cerr << repItem << " already exists" << endl;
   }
}