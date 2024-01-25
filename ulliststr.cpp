



#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"




#include <iostream>
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
//-------------->






/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){
    Item* temp = tail_;
    //last - first equals the amount of the array that is filled with strings
    //first is where the inclusive beginning of the filled array starts
    //last is where the exclusive end of the filled array
    if(head_ == nullptr && tail_ == nullptr){
        head_ = new Item();
        head_->val[0] = val;
        head_->first = 0;
        head_->last += 1;
        tail_ = head_;
    }else if(temp->last - temp->first < 10){  //If the difference is below than 10 which means that this will run only when <==========THIS IS THE PROBLEM
        temp->val[temp->last - temp->first] = val;
        temp->last += 1;
    }
      else if(!temp->val[9].empty()){
        temp->next = new Item();
        temp = temp->next;
        temp->prev = tail_;
        tail_ = temp;
        temp->val[temp->last - temp->first] = val;
        temp->last += 1;
    }
    size_ += 1;
  }
/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise,
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */

void ULListStr::push_front(const std::string& val){
    Item* temp = head_;
    //last - first equals the amount of the array that is filled with strings
    //first is where the inclusive beginning of the filled array starts
    //last is where the exclusive end of the filled array
    if(head_ == nullptr && tail_ == nullptr){
        head_ = new Item();
        head_->val[0] = val;
        head_->first = 0;
        head_->last += 1;
        tail_ = head_;
    }else if(!temp->val[0].empty()){  //If it is one, that means that you push front to new Item Node before the current Item Node
        head_ = new Item();
        head_->next = temp;
        temp->prev = head_;
        temp = head_;
        temp->last = 10;
        temp->first = 9;
        temp->val[temp->first] = val;
    }else if(temp->last - temp->first < 10){
        temp->first -= 1;
        temp->val[temp->first] = val;
    }
    size_ += 1;
}




 /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if(size_ == 1){
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    }else{
      head_->val[head_->first] = "";
      head_->first += 1;
      if(head_->first == 10){
        Item* temp = head_;
        head_ = head_->next;
        delete temp;
        head_->prev = nullptr; //<-------- THIS IS DA PROBLEM
      }
    }
    size_ -= 1;
  }


  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    if(size_ == 1){
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
    }else{
        tail_->val[tail_->last - 1] = "";
        tail_->last -= 1;
        if(tail_->last - 1 == -1){
            Item* temp = tail_;
            tail_ = tail_->prev;
            delete temp;
            tail_->next = nullptr;
        }
    }
    size_ -= 1;
  }


  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{  //Can't change pointer pointing at something else after this
    return tail_->val[tail_->last - 1];
  }


  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    //Const reference means that I can't change where the reference or pointer points to after this
    return head_->val[head_->first];
  }




/**
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n)
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc < 0 || loc > size_ - 1){
    return nullptr;
  }else{
//-----------------------> THIS WORKS for no loop
    Item* temp = head_;
    string * beg = &temp->val[temp->first];
    int remainder = 0;
    int modulo = 0;
    string* result;
    if(temp->first + loc > temp->last - 1){
  
        //remainder = temp->first + loc - (temp->last - 1);
        loc = temp->first + loc - (temp->last - 1);
        modulo = loc % 11;
        temp = temp->next;
        while(temp != nullptr && loc > 10 ){    
            if(temp->first == 0  && temp->last == 10 && loc > 10){
                loc -= 10;    
                temp = temp->next;
            }
        }
        result = &temp->val[loc - 1];
                
    }else{
        result = &temp->val[temp->first + loc];
    }
    return result;
  }
}


//-------------->
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





