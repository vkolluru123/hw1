#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::printlist() const {
  Item* curr = head_;
  while (curr) {
    for (unsigned int i = curr->first; i < curr->last; i++) {
      cout << curr->val[i] << " ";
    }
    curr = curr -> next;
  }
  cout << endl;
}

void ULListStr::push_back(const std::string& val) {
  // increment size_
  size_ += 1;
  // if list is empty, create new item and add val there
  if (tail_ == NULL) {
    tail_ = new Item();
    tail_ -> val [tail_ -> last] = val;
    tail_ -> last += 1;
    head_ = tail_;
  }
  // if there is room in last item to push back, update last item
  else if (tail_ -> last < ARRSIZE) {
    tail_ -> val [tail_ -> last] = val;
    tail_ -> last += 1;  // move last one down
  }
  // if there is no room to push back, create new item
  else if (tail_ -> last >= ARRSIZE) {
    // make new node
    Item* newItem = new Item();
    // set node's data members
    newItem -> last = 1;
    newItem -> prev = tail_;
    newItem -> val[0] = val;
    // update tail_
    tail_ -> next = newItem;
    tail_ = newItem;
  }
}

void ULListStr::pop_back() {
  // decrement size_
  size_ -= 1;
  // remove last value by updating "last" variable
  tail_ -> last -= 1;
  // if the Item's array is empty, delete it
  if (tail_ -> first == tail_ -> last) {
    // we are saving the current tail before we change it
    Item* previous = tail_ -> prev;
    delete tail_;
    tail_ = previous;
    // if previous one exists, then next is null
    if (previous) {
      tail_ -> next = NULL;
    }
    // else, list is empty
    else {
      head_ = NULL;
    }
  }
}

void ULListStr::push_front(const std::string& val) {
  // increment size_
  size_ += 1;
  // if list is empty, create new item and add val there
  if (head_ == NULL) {
    head_ = new Item();
    head_ -> val [head_ -> first] = val;
    head_ -> last = head_ -> first + 1;
    tail_ = head_;
  }
  // if there is room in first item to push front, update first item
  else if (head_ -> first > 0) {
    head_ -> first -= 1;
    head_ -> val [head_ -> first] = val;
  }
  // if there is no room to push front, create new item
  else if (head_ -> first == 0) {
    Item* newItem = new Item();
    newItem -> next = head_;
    head_ -> prev = newItem;
    head_ = newItem;
    head_ -> first = ARRSIZE - 1;
    head_ -> last = ARRSIZE;
    head_ -> val [head_ -> first] = val;
  }
}

void ULListStr::pop_front() {
  // decrement size_
  size_ -= 1;
  // remove first value
  head_ -> first += 1;
  // if the Item's array is empty, delete it
  if (head_ -> first == head_ -> last) {
    // store current head before moving to next one
    Item* ogHead = head_;
    head_ = head_ -> next;
    // if next one exists, previous is null
    if (head_) {
      head_ -> prev = NULL;
    }
    else {
      // deleting last one
      tail_ = NULL;
    }
    delete ogHead;
  }
}

std::string const & ULListStr::back() const {
  // return last item's last value
  return tail_ -> val[tail_ -> last - 1];
}
std::string const & ULListStr::front() const {
  // return first item's first value
  return head_ -> val[head_ -> first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // if loc is invalid, return null
  if (loc >= size_) {
    return NULL;
  }
  // return ptr to item at index
  Item* curr = head_;
  unsigned int myIndex = loc;
  // go thru list and locate the value
  while (curr) {
    if (myIndex < (curr -> last - curr -> first)) {
      return &curr -> val[curr -> first + myIndex];
    }
    myIndex -= (curr -> last - curr -> first);
    curr = curr -> next;
  }
}









void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
