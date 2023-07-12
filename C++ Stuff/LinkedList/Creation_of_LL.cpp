//Creation of Linked List & Utility Functions

#include <iostream>
#include <bits/stdc++.h>

//Class for a Node in a Linekd List
class Node {
  public:
    int data;
    Node* next;
};

//Utility Functions for Singly Linked List
void printLL(Node* n);
Node* findNode(Node** headptr , int position);
bool insertNode_head(Node** headptr , int data);
bool insertNode_end(Node** headptr , int data);
bool insertNode_any(Node** headptr , int data , int position);
bool deleteNode_head(Node** headptr);
bool deleteNode_end(Node** headptr);
bool deleteNode_any(Node** headptr , int postion);


//Print out the current linked list
void printLL(Node* n)
{
  if (n == nullptr){
    std::cout << "Empty Linked List!\n";
  }

  while (n != NULL){
    std::cout << n->data << "\n";
    n = n->next;
  }
}

//insert at the head of the LL
bool insertNode_head(Node** headptr , int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = (*headptr);
  (*headptr) = newNode;

  return true;
}

//insert at the end of the LL
bool insertNode_end(Node** headptr , int data)
{
  Node* temp;
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;

  temp = (*headptr);

  //This will loop until we reach the last node
  while (temp->next != NULL){
    temp = temp->next;
  }

  temp->next = newNode;

  return true;
}

//insert at a particular location in LL
bool insertNode_any(Node** headptr , int data , int position)
{
  Node* temp;
  Node* next;
  Node* newNode = new Node();
  newNode->data = data;

  if ((*headptr) == nullptr){
    return false;
  }

  temp = (*headptr);

  while (position > 0){

    temp = temp->next;
    if (temp == nullptr){
      return false;
    }
    position--;
  }

  next = temp->next;
  temp->next = newNode;
  newNode->next = next;

  return true;
}

//delete a node from the head of the LL
bool deleteNode_head(Node** headptr)
{
  if (*headptr == nullptr || (*headptr)->next == nullptr ){
    return false;
  }
  (*headptr) = (*headptr)->next;

  return true;
}

//delete a node from the end of the LL
bool deleteNode_end(Node** headptr)
{
  Node* temp;
  if ((*headptr) == nullptr){
    return false;
  }

  temp = (*headptr);
  while (temp->next->next != nullptr){
    temp = temp->next;
  }
  temp->next = temp->next->next;

  return true;
}

//delete a node from a position that the user input
bool deleteNode_any(Node** headptr , int position)
{
  Node* temp;
  Node* pre;
  if ((*headptr) == nullptr){
    return false;
  }

  temp = (*headptr);
  pre = findNode(headptr , position);
  if (pre == nullptr){
    return false;
  }

  pre->next = pre->next->next;

  return true;
}

//find a node by position and return the node
//return null when the node cannot be found
Node* findNode(Node** headptr , int position)
{
  Node* temp = nullptr;
  if ((*headptr) == nullptr){
    return nullptr;
  }

  temp = (*headptr);
  while (position > 0){
    temp = temp->next;
    position--;
  }
  return temp;
}


int main()
{

  Node* newNode = nullptr;
  Node* randomNode = nullptr;
  
  //allocate node in the heap mem
  newNode = new Node();

  newNode->data = 4;
  newNode->next = nullptr;

  insertNode_head(&newNode , 5);
  insertNode_end(&newNode , 6);
  insertNode_any(&newNode , 10 , 1);
  printLL(newNode);

  //randomNode = findNode(&newNode , 1);
  //std::cout << randomNode->data << "\n";
  std::cout << "\n";
  //deleteNode_head(&newNode);
  //deleteNode_end(&newNode);
  deleteNode_any(&newNode , 1);
  printLL(newNode);

  return 0;
}


