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

void ULListStr::push_back(const std::string& val){
  if (empty()||tail_->last == ARRSIZE){
    Item* append = new Item(); 
    Item* temp = tail_;
    append->prev = temp;
    tail_= append;
    append->next = NULL;
  }
    //changing val
    tail_->val[tail_->last] = val;
    tail_->last++;

  // check tail: if full make new Item; change tail; add val; change last; link the list(change prev and next)
 
  
}




void ULListStr::pop_back(){

}
void ULListStr::push_front(const std::string& val){

}
void ULListStr::pop_front(){

}
std::string const & ULListStr::back() const{
  return get(0);
}
std::string const & ULListStr::front() const{
    return get(0);

}
std::string* ULListStr::getValAtLoc(size_t loc) const{
  std::string const test= get(0);
  return NULL;
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
