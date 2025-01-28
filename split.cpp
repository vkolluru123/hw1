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
#include <cstddef>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */

  // BASE CASE: empty list

  // odds and evens lists are done building, add NULL at end
  if (in == NULL) {
    odds = NULL;
    evens = NULL;
    return;
  }

  // RECURSIVE STEP: sort the next term of the list into 
  //     either odds or evens
  //     then move to the next term, repeat

  // save current in value in tempVar
  // isolate tempVar from the original list
  Node* tempVar = in;
  
  // update in for the next iteration (becomes next node)
  in = in->next;
  // splitting the list
  // odds
  if (tempVar->value % 2 == 1) {
    //cout << "ODD ENTERED" << endl;
    odds = tempVar;   // update odds list
    // move to next term before next recursion step
    tempVar->next = NULL;
    split(in, odds -> next, evens);
  }
  // evens
  else if (tempVar->value % 2 == 0) {
    //cout << "EVEN ENTERED" << endl;
    evens = tempVar;    // update evens list
    // move to next term before next recursion step
    tempVar->next = NULL;
    split(in, odds, evens -> next);
  }
  

}

/* If you needed a helper function, write it here */
