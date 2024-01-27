/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  
  //base case (end of in list)
  if(in == nullptr){

    if(odds != nullptr) {
      odds -> next = nullptr;
    }

    if(evens != nullptr) {
      evens -> next = nullptr;
    }
    return;
  }

  // if its odd
  else if (in -> value % 2 == 1)  {
    cout << "entered odds " << endl;
    /*this takes care of the first call (when the odds
    list is empty) by intiazing the odds list */
    if(odds == nullptr) {

      odds = in;
      in = in -> next;
      split(in , odds, evens);
    }
    else {
      cout << "entered evens " << endl;
      odds -> next = in;
      in = in -> next;
      split(in , odds -> next, evens);
    }
  }

  // if its even
  else {

    /*this takes care of the first call (when the evens
    list is empty) by intiazing the evens list */
    if(evens == nullptr) {
      evens = in;
      in = in -> next;
      split(in , odds, evens);
    }
    else {
      evens -> next = in;
      in = in -> next;
      split(in , odds, evens -> next);
    }
  }  
}

/* If you needed a helper function, write it here */
