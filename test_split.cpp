/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

  // make odds and evens pointers
  Node* odds = NULL;
  Node* evens = NULL;

  // create linked list using Node*s
  Node* lastOne = new Node(8,NULL);
  Node* nextLast = new Node(7,lastOne);
  Node* nextnextLast = new Node(6,nextLast);
  Node* myLLhead = new Node(5,nextnextLast);

  // print initial linked list values
  Node* curr = myLLhead;
  while (curr) {
    cout << curr -> value << ", ";
    curr = curr -> next;
  }
  cout << "NULL (original)" << endl;

  cout << "myLLhead: " << myLLhead << endl;
  cout << "next: " << myLLhead->next << endl;

  // call split function
  split(myLLhead, odds, evens);

  // print odds and evens
  Node* curr2 = odds;
  while (curr2) {
    cout << curr2 -> value << ", ";
    curr2 = curr2 -> next;
  }
  cout << "NULL (odds)" << endl;
  Node* curr3 = evens;
  while (curr3) {
    cout << curr3 -> value << ", ";
    curr3 = curr3 -> next;
  }
  cout << "NULL (evens)" << endl;

  // print original linked list values (should be empty)
  Node* curr4 = myLLhead;
  while (curr4) {
    cout << curr4 -> value << ", ";
    curr4 = curr4 -> next;
  }
  cout << "NULL (nothing should have been printed)" << endl;

  // deallocation
  Node* tempO = odds;
  Node* tempE = evens;
  while (tempO) {
    Node* Onext = tempO -> next;
    delete tempO;
    tempO = Onext;
  }
  while (tempE) {
    Node* Enext = tempE -> next;
    delete tempE;
    tempE = Enext;
  }

}
