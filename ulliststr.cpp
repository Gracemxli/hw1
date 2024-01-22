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
  if (empty()){
    head_  = tail_ = new Item(); 
  }
  if (tail_->last == ARRSIZE){
    Item* append = new Item(); 
    tail_->next = append; 
    append->prev = tail_;
    tail_= append;
  }
  //changing val
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}




void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  
  tail_->last--;
  size_--;

  if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_ ->next= NULL;
    delete temp; 
  }


}
void ULListStr::push_front(const std::string& val){
  if (empty()){
    head_  = tail_ = new Item();
    head_->first= ARRSIZE; 
    head_->last =ARRSIZE; 
  }
  else if (tail_->first == 0){
    Item* append = new Item(); 
    head_->prev = append; 
    append->next = head_;
    head_ = append;
    head_->first= ARRSIZE; 
    head_->last =ARRSIZE;
  }
  //changing val
  head_->first--;
  head_->val[head_->first] = val;
  size_--;
}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  
  head_->first++;
  size_--;

  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    head_ ->prev= NULL;
    delete temp; 
  }
}
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const{
    return head_->val[head_->first];

}
std::string* ULListStr::getValAtLoc(size_t loc) const{\
  
  int total = 0; 
  Item * p = head_;
  while( p != NULL){
    int count = p->last - p->first;
    if ((total+count) >= loc){
      return &p->val[p->first +loc];
    }    
    total += count;
    p = p->next;
  }
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
