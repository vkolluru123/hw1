#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr myULList;
  // push_back when list is empty
  myULList.push_back("4");
  myULList.printlist();
  // push_back when there is room in that item
  myULList.push_back("5");
  myULList.push_back("6");
  myULList.push_back("7");
  myULList.push_back("8");
  myULList.push_back("9");
  myULList.push_back("0");
  myULList.push_back("1");
  myULList.push_back("2");
  myULList.push_back("3");
  myULList.printlist();
  // push_back when no room in item, make new item
  myULList.push_back("4");
  myULList.push_back("5");
  myULList.printlist();
  // pop_back normally
  myULList.pop_back();
  myULList.pop_back();
  myULList.printlist();
  // pop_back when item becomes empty
  myULList.pop_back();
  myULList.printlist();

  // push_front when list is empty
  myULList.push_front("4");
  myULList.printlist();
  // push_front when there is room in that item
  myULList.push_front("5");
  myULList.push_front("6");
  myULList.push_front("7");
  myULList.push_front("8");
  myULList.push_front("9");
  myULList.push_front("0");
  myULList.push_front("1");
  myULList.push_front("2");
  myULList.push_front("3");
  myULList.printlist();
  // push_front when no room in item, make new item
  myULList.push_front("4");
  myULList.push_front("5");
  myULList.printlist();
  // pop_front normally
  myULList.pop_front();
  myULList.pop_front();
  myULList.printlist();
  // pop_front when item becomes empty
  myULList.pop_front();
  myULList.printlist();

  // front and back
  cout << "Front: " << myULList.front() << endl;
  cout << "Back: " << myULList.back() << endl;

  return 0;
}
