/* TerraGeode
   Original by: Teacher
   Date: 04/13/2022
   Path: ~TerraGeode/csc1720/programs/program4/linkedStack.h
   About: Header file for linkedStack
*/

#ifndef H_LinkedStackType
#define H_LinkedStackType
 
#include <iostream>
#include <cassert> 
 
#include "stackADT.h"

using namespace std;

//Definition of the node 
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType: public stackADT<Type>
{
public:
    const linkedStackType<Type>& operator=
                              (const linkedStackType<Type>&);
      //Overload the assignment operator.

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty;
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns false.

    void initializeStack();
      //Function to initialize the stack to an empty state. 
      //Postcondition: The stack elements are removed; 
      //               stackTop = nullptr;

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top 
      //               element of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.

    linkedStackType(); 
      //Default constructor
      //Postcondition: stackTop = nullptr;

    linkedStackType(const linkedStackType<Type>& otherStack); 
      //Copy constructor

    ~linkedStackType();
      //Destructor
      //Postcondition: All the elements of the stack are 
      //               removed from the stack.

    void reverseStack(const linkedStackType<Type> &otherStack);
    /*function to copy a linked list stack into a new array stack
       in reverse order
      precon: Original linked stack exists in current order
      postcon: new linked list is the original linked list in reverse order
    */

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};


    //Default constructor
template <class Type> 
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == nullptr);
} //end isEmptyStack

template <class Type>
bool linkedStackType<Type>:: isFullStack() const
{
    return false;
} //end isFullStack

template <class Type>
void linkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp; //pointer to delete the node

    while (stackTop != nullptr)  //while there are elements in 
                              //the stack
    {
        temp = stackTop;    //set temp to point to the 
                            //current node
        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;    //deallocate memory occupied by temp
    }
} //end initializeStack


template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;  //pointer to create the new node

    newNode = new nodeType<Type>; //create the node

    newNode->info = newElement; //store newElement in the node
    newNode->link = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the 
                              //top node
} //end push


template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element 
}//end top

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;   //pointer to deallocate memory

    if (stackTop != nullptr)
    {
        temp = stackTop;  //set temp to point to the top node

        stackTop = stackTop->link;  //advance stackTop to the 
                                    //next node
        delete temp;    //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type> 
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != nullptr) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = nullptr;  //set the link field of the
                                //node to nullptr
        last = stackTop;        //set last to point to the node
        current = current->link;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

    //copy constructor
template <class Type>   
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}//end copy constructor

    //destructor
template <class Type> 
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}//end destructor

    //overloading the assignment operator
template <class Type>   
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{ 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
}//end operator=

template <class Type>
void linkedStackType<Type>::reverseStack(const linkedStackType<Type> &otherStack) {
    if (!this->isEmptyStack()) {//checks if stack is not empty
        this->initializeStack();//empties stack if not empty
    }

    if (otherStack.isEmptyStack()) {//checks if otherStack is empty
        this->stackTop = nullptr;//sets stackTop to nullptr if so
    } else {
        nodeType<Type> *cur, *temp, *prev;//declare nodeType variables
        cur = otherStack.stackTop;//sets cur to point to stackTop of otherStack
        temp = new nodeType<Type>;//points temp to a new nodeType

        temp->info = cur->info;//copies info from cur->info to temp->info
        temp->link = nullptr;//points temp->link to nullptr

        prev = temp;//sets prev to point temp node
        cur = cur->link;//moves cur to next item in otherStack without
                        //destroying it
        
        while (cur != nullptr) {
            temp = new nodeType<Type>;//points temp to a new nodeType
            temp->info = cur->info;//copies info from cur->info to temp->info
            temp->link = prev;//points temp->link to prev node
            prev = temp;//makes prev point to temp node
            cur = cur->link;//moves cur to next linked node
        }

        this->stackTop = temp;//points stackTop to temp node
    }
}
#endif