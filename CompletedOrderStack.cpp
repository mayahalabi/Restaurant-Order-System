/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   CompletedOrderStack.cpp
 * Author: Elise Trad and Maya Halabi
 * The implementation file of the CompletedOrderStack class 
 */

#include "CompletedOrderStack.h"
using namespace std;
    
//--- Definition of class constructor
CompletedOrderStack::CompletedOrderStack(): myTop(NULL) {}
     
//--- Definition of Destructor    
CompletedOrderStack::~CompletedOrderStack() {
    // Set pointers to run through the stack
    NodePtr currentPtr = myTop,  // node to be deallocated
            nextPtr;   // its successor
   
    while (currentPtr != NULL) {
        nextPtr = currentPtr->next;
        delete currentPtr;
        currentPtr = nextPtr;
    }
}
    
//--- Definition of copy constructor
CompletedOrderStack::CompletedOrderStack(const CompletedOrderStack& original) {
    myTop = NULL;
    if (!original.empty()) {
        // Copy first node
        myTop = new Node(original.top());
        
        // Set pointers to run through the stack's linked lists
        NodePtr lastPtr = myTop, origPtr = original.myTop->next;
            
        while (origPtr != NULL) {
            lastPtr->next = new CompletedOrderStack::Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    }
}
 
//--- Definition of display function
void CompletedOrderStack::displayCompletedOrders(ostream& out) const {
    out << "\nCompleted Orders:\n";
    // Set pointer to run through the stack's linked lists
    NodePtr ptr;
    for (ptr = myTop; ptr != NULL; ptr = ptr->next)
      out << ptr->data << endl; // Order class overloads the << operator
}
    
//--- Definition of calculateTotalRevenue function
double CompletedOrderStack::calculateTotalRevenue() const {
    if(empty())
        return 0;
    
    double revenue = 0;
    NodePtr ptr; // pointer to loop through the stack's linked lists
    int i = 1; // keep track of the order's number
    
    for(ptr = myTop; ptr != NULL; ptr = ptr->next) {
        cout << "Order " << i << ":\n";
        revenue += ptr->data.total(); // add the total of each order
        i++;
    }
    return revenue;    
}
   
//--- Definition of saveCompletedOrders function
void CompletedOrderStack::saveCompletedOrders(ofstream& file) const {
    if (!file.is_open()) {
        cerr << "Error: file is not open." << endl;
        return;
    }
    for(NodePtr loop = myTop; loop != NULL; loop = loop->next) {
        file << loop->data; 
    }    
}
    
//--- Definition of empty()
bool CompletedOrderStack::empty() const { 
    return (myTop == NULL); 
}
    
//--- Definition of top()
Order CompletedOrderStack::top() const {
    if (!empty())
        return (myTop->data);
    else {
        cerr << "*** Stack is empty -- returning garbage ***\n";
        Order garbage(0, "", DynamicArrayList());
        return garbage;
    }
}

//--- Definition of push
void CompletedOrderStack::push(const Order& value) {
    myTop = new Node(value, myTop);
}

//--- Definition of pop
 void CompletedOrderStack::pop() {
     if(!empty()) {
        NodePtr ptr = myTop;
        myTop = myTop->next;
        delete ptr;
     }   
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
 }
 
