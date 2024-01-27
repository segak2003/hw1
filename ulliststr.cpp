#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


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

 /**
   * Returns a const reference to the back element
   */
std::string const & ULListStr::back() const 
{
  return tail_ -> val[tail_ -> last - 1];
}

/**
  * Returns a const reference to the front element
  */
std::string const& ULListStr::front() const 
{
  return head_ -> val[head_ -> first];
}


 /*
  * Removes a value from the back of the list
  */
void ULListStr::pop_back() 
{
  /*
   * makes sure we dont perform pop_back() on an empty list
   */
  if(head_ == nullptr || size_ == 0) {
    return;
  }

  /*
   * this performs the pop_back() by incrementing the tail -> last
   */
  --tail_ -> last;
  size_--;

   /*
    * checks if the current node is the only node in our list
    * and if this current node is empty after popping
    * if so delete empty node and our entire list is null (no nodes)
    */
  if((tail_ -> first == tail_ -> last) && head_ == tail_) {
    delete tail_;
    head_ = tail_ = nullptr;
    return;
  } 

  /*
   * checks if current node is empty after popping 
   * if so delete the empty node
   */
  if(tail_ -> first == tail_ -> last ) {
    Item * temp = tail_;
    tail_ = temp -> prev;
    tail_ -> next = nullptr;

    delete temp;
    return;
  }

  return;
}

void ULListStr::pop_front() 
{

   /*
   * makes sure we dont perform pop_front() on an empty list
   */
  if(head_ == nullptr || size_ == 0) {
    return;
  }

  /*
   * this performs the pop_front() by incrementing the head -> first
   */
  ++head_ -> first;
  size_--;
  

  /*
   * checks if the current node is the only node in our list
   * and if this current node is empty after popping
   * if so delete empty node and our entire list is null (no nodes)
   */
  if((head_ -> first == head_ -> last ) && head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
    return;
  }

  /*
   * checks if current node is empty after popping 
   * if so delete the empty node
   */
  if(head_ -> first == head_ -> last ) {
    Item * temp = head_;
    head_ = temp -> next;
    head_ -> prev = nullptr;
    delete temp;
  }

  return;
}

void ULListStr::push_back(const std::string& val) 
{
 
  /* 
   *if the list is empty create a new node that will
   * our head_ node and tail_ node
   */
  if(tail_ == nullptr) {
    tail_ = new Item();
    head_ = tail_;
    tail_ -> val[0] = val;
    ++tail_ -> last;
    size_++;
    return;
  }

  /* 
   * if the current node is full this makes a new node and 
   * adds the element to the front of the new node 
   */
  if(tail_ -> last >= ARRSIZE) {
    Item* tempTail = tail_;
    tail_ = new Item();
    tail_ -> prev = tempTail;
    tempTail -> next = tail_;
    tail_ -> val[0] = val;
    tail_ -> last++; 
    size_++;
    return;
  }

  /* 
   * this performs the push_back if the if statements above 
   * aren't executed 
   */
  tail_ -> val[tail_  -> last] = val;
  tail_ -> last++;
  size_++;

  return;
}

void ULListStr::push_front(const std::string& val) 
{
  /* 
   *if the list is empty create a new node that will
   * our head_ node and tail_ node
   */
  if(head_ == nullptr)  {

    head_ = new Item();
    head_ -> val[0] = val;
    tail_ = head_;
    tail_ -> last++;
    tail_ -> next = nullptr;
    size_++;
    return;
  }

  /* 
   * if the current node is full this makes a new node and 
   * adds the element to the front of the new node 
   */
  if(head_ -> first == 0) {

    Item* tempHead = head_;
    head_ = new Item();
    head_ -> val[9] = val;
    head_ -> last = 10;
    head_ -> first = 9;

    tempHead -> prev = head_;
    head_ -> next = tempHead;
    size_++;
    return;
  } 
  
  /* 
   * this performs the push_front if the if statements above 
   * aren't executed 
   */
  --head_ -> first;
  head_ -> val[head_ -> first ] = val;
  size_++;

  return;
}

std::string* ULListStr::getValAtLoc(size_t loc) const 
{
  /*
   * if the user passes an loc (index) that is greater 
   * than the size of our list
   */
  if(loc > size_) {
    return nullptr;
  }
  
  Item* temp = head_;

  while(temp != nullptr) {

    /*
     * if loc is < the size of the current node than it has to 
     * be in that node so we'll return it 
     */
    if(loc < (temp -> last - temp -> first)) {

      return &(temp -> val[(temp -> first) + loc]);
    }

    //incrementes to the next node as its not in the current one
    if(temp -> next != nullptr) {

      //substract the difference (size current node's array) from loc
      loc -= (temp -> last - temp -> first);
      temp = temp -> next;
    }
  }
  
  return nullptr;
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
