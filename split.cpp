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
//#include <iostream>
//using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  //std::cout << "CALL" << std::endl;
  
  //base case (end of in list)
  if(in == nullptr){

    //std::cout << "in is NULL" << std::endl;

    if(odds != nullptr) {
      odds -> next = nullptr;
    }

    if(evens != nullptr) {
      evens -> next = nullptr;
    }
    return;
  }

  //std::cout << "b4 if  in val: " << in -> value << " address: " << in  << std::endl << std::endl;
  // if its odd
  else if (in -> value % 2 == 1)  {
    /*this takes care of the first call (when the odds
    list is empty) by intiazing the odds list */
    if(odds == nullptr) {
     // std::cout << "INITIALZING ODDS" << std::endl;

      odds = in;
      in = in -> next;
      split(in , odds, evens);

      //std::cout << "init odds val: " << odds  << std::endl;
    }
    else {
     // std::cout << "creating an odd node" << std::endl;
      odds -> next = in;
      in = in -> next;
      //odds = odds -> next;
      split(in , odds -> next, evens);
      //std::cout << "odds val: " << odds -> value << std::endl;
      
    }
  }

  // if its even
  else {
    /*this takes care of the first call (when the evens
    list is empty) by intiazing the evens list */
    if(evens == nullptr) {
      //std::cout << "INITIALZING EVENS" << std::endl;

      evens = in;

      //std::cout << "init evens val: " << evens -> value << "     address: " << evens  << std::endl << std::endl;
      //std::cout << "in val: " << in -> value << " address: " << in  << std::endl << std::endl;

      in = in -> next;
      split(in , odds, evens);
      //std::cout << "post increment in val: " << in -> value << "     address: " << in  << std::endl << std::endl;
      
      //std::cout << "init evens val: " << evens -> value << "    address: " << evens  << std::endl << std::endl;
    }
    else{
      //std::cout << "creating an even node" << std::endl;
      //std::cout << "during if   evens val: " << evens -> value << "     address: " << evens  << std::endl << std::endl;

      evens -> next = in;
      in = in -> next;
     // evens = evens -> next;
      split(in , odds, evens -> next);
     // std::cout << "during if   evens val: " << evens -> value << "     address: " << evens  << std::endl << std::endl;
      
    }
  }

  //std::cout << "post if   evens val: " << evens -> value << "      address: " << evens  << std::endl << std::endl;
  //std::cout << "post if   in val: " << in -> value << "      address: " << in  << std::endl << std::endl;
  //split(nxt, odds, evens);
  
}

/* If you needed a helper function, write it here */
