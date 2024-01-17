/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
using namespace std;

//Singly Linked List
class LinkedList{
  public:
    LinkedList(int val){
      //cout << "VAL: " << val << endl;
      start = new Node(val, nullptr);
    }
    ~LinkedList(){  //When making singly linked list, make two temp pointers to start memory address
     //Leave this commented
      /*
      Node* temp = start;
      Node* temp_two = start;
      while(temp != nullptr){
        temp = temp->next;
        delete temp_two;
        temp_two = temp;
      }
      */
    }
    void AddNode(int val){
      
      Node* temp = start;
      while(temp->next != nullptr){
        temp = temp->next;
      }
      temp->next = new Node(val, nullptr);
      
    }

    void printLinkedList() const{
      
      Node* temp = start;
      while(temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
      }
      
    }

  //private:
    Node* start;

};

void printNodesSeries(Node* content){
  
  Node* temp = content;
  while(temp != nullptr){
      cout << temp->value << " ";
      temp = temp->next;
  }
  
}
void DeleteNodesSeries(Node* content){
  
  Node* temp = content;
  Node* temp_two = content;
  while(temp != nullptr){

    temp = temp->next;
    delete temp_two;
    temp_two = temp;
  }
  
}
int main(int argc, char* argv[])
{
  cout << "test_split" << endl;
  


  LinkedList l1(1);
  l1.AddNode(3);
  l1.AddNode(5);
  l1.AddNode(7);
  l1.AddNode(9);
  l1.AddNode(11);
  l1.AddNode(12);
  l1.printLinkedList();

  Node* odd = nullptr;
  Node* even = nullptr;
  //Node* ex = nullptr;
  split(l1.start, odd, even);

  cout << "odd: ";
  printNodesSeries(odd);
  cout << endl;
  cout << "even: ";
  printNodesSeries(even);
  cout << endl;

  DeleteNodesSeries(odd);
  DeleteNodesSeries(even);

  if(l1.start == nullptr){
    cout << "l1.start: " << " is a nullptr" << endl;
  }
  return 0;
}
