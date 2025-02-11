/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ActiveOrderQueue.cpp
 * Author: Elise Trad and Maya Halabi
 * The implementation file for the ActiveOrderQueue class
 */

#include "ActiveOrderQueue.h"
using namespace std;

// Constructor definition
ActiveOrderQueue::ActiveOrderQueue() : myFront(NULL), myBack(NULL) {}
    
// Destructor definition
ActiveOrderQueue::~ActiveOrderQueue() {
    NodePtr prev = myFront, ptr;
    while (prev != 0) {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

void ActiveOrderQueue::processNextOrder(CompletedOrderStack& stack) {
    if(!empty()) {
      cout << "Processing order for " << front().getCustomerName(); 
      stack.push(front());
      dequeue();
      cout << "\nOrder processed successfully!\n";    
    }
}

//--- Definition of front()
Order ActiveOrderQueue::front() const {
    if (!empty())
        return (myFront->data);
    else {
        cerr << "*** Queue is empty --- returning garbage ***\n";
        return Order(0, " ", DynamicArrayList());  
    }
}

//--- Definition of empty()
bool ActiveOrderQueue::empty() const { 
   return (myFront == 0); 
}

void ActiveOrderQueue::addOrder(const Order &order) {
    NodePtr newptr = new Node(order);
    if (empty())
      myFront = myBack = newptr;
    else {
      myBack->next = newptr;
      myBack = newptr;
    }
}
    
void ActiveOrderQueue::displayActiveOrders(ostream& out) const{
    out << "--- Active Orders ---\n";
    NodePtr ptr;
    for (ptr = myFront; ptr != NULL; ptr = ptr->next)
        out << (ptr->data); // << is overloaded in Order class
}
    
void ActiveOrderQueue::deleteOrder(int id) {
    if (empty()) {
        cerr << "*** Queue is empty -- can't remove a value ***\n";
        return;
    }

    NodePtr ptr = myFront;

    // if the order to delete is the first node
    if (ptr->data.getOrderId() == id) {
        myFront = myFront->next;
        delete ptr;
        if (myFront == NULL) { // If the queue is now empty
            myBack = NULL;
        }
        return;
    }

    // if it's not the first node
    NodePtr prev = NULL; // Pointer to keep track of the previous node
    while (ptr != NULL && ptr->data.getOrderId() != id) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) { // Reached the end of the queue without finding the id
        cerr << "*** Id is not found in queue ***\n";
        return;
    }

    // Node to delete is ptr
    prev->next = ptr->next;
    if (ptr == myBack) { // If the node to delete is the last node
        myBack = prev;
    }
    delete ptr;
    cout << "Order dequeued successfully.\n";
}

//--- Definition of dequeue()
void ActiveOrderQueue::dequeue() {
    if (!empty()) {
      NodePtr ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
          myBack = 0;
    }   
    else
        cerr << "*** Queue is empty -- can't dequeue a value ***\n";
}

//--- Definition of size
int ActiveOrderQueue::size() const {
     int count = 0;
     NodePtr temp = myFront; 
     while (temp != NULL) {
        count++;            // Increment the count for each node
        temp = temp->next;  // Move to the next node
    }
    return count;        
 }