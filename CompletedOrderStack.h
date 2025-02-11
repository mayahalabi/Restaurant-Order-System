/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   CompletedOrderStack.h
 * Author: Elise Trad and Maya Halabi
 * The header file of the CompletedOrderStack class
 */

#ifndef COMPLETEDORDERSTACK_H
#define COMPLETEDORDERSTACK_H
#include "Order.h"
#include <iostream>

class CompletedOrderStack {

private:
    /*** Node class ***/
    class Node {
    public:
        Order data;
        Node * next;
        //--- Node constructor
        Node(Order value, Node * link = NULL)
        /*------------------------------------------------------------------- 
          Precondition: None.
          Postcondition: A Node has been constructed with value in its data
          part and its next part set to link (default 0).
        -------------------------------------------------------------------*/
        : data(value), next(link)
        {}
    };

    typedef Node * NodePtr;

    /***** Data Members *****/
    NodePtr myTop; // Pointer to top of stack
    
public:
    /***** Function Members *****/
    
    /***** Constructor *****/
    CompletedOrderStack();
    /*-----------------------------------------------------------------------
      Construct a CompletedOrderStack object
     
      Precondition:  None.
      Postcondition: An empty CompletedOrderStack object has been constructed
      (myTop is initialized to a null pointer).
    ------------------------------------------------------------------------*/
    
    /***** Destructor *****/
    ~CompletedOrderStack();
    /*------------------------------------------------------------------------
      Class destructor
    
      Precondition:  None
      Postcondition: The linked list in the stack has been deallocated.
    ------------------------------------------------------------------------*/
    
    /***** Copy Constructor *****/
    CompletedOrderStack(const CompletedOrderStack & original);
    /*------------------------------------------------------------------------
      Copy Constructor 
     
      Precondition:  original is the stack to be copied and is received as 
      a const reference parameter.
      Postcondition: A copy of original has been constructed.
    ------------------------------------------------------------------------*/
    
    void displayCompletedOrders(ostream& out) const;
    /*-----------------------------------------------------------------------
      Display values stored in the stack.
      
      Precondition:  ostream out is open.
      Postcondition: Stack's contents have been output to out.
    ------------------------------------------------------------------------*/
    
    double calculateTotalRevenue() const;
    /*-----------------------------------------------------------------------
      Calculate the total revenue of completed orders
      
      Precondition: Stack is nonempty.
      Postcondition: the total revenue is returned (as a double) by summing 
      the revenue of all completed orders in the stack; 
      if the stack is empty, returns 0.
    ------------------------------------------------------------------------*/
    
    void saveCompletedOrders(ofstream& file) const;
    /*-----------------------------------------------------------------------
      Write details of all completed orders to a file.
      
      Precondition: The ofstream file stream is open and writable. 
      Postcondition: All orders in the stack are written to the 
      file in the order they are retrieved from the stack.
    ------------------------------------------------------------------------*/
    
    bool empty() const;
    /*------------------------------------------------------------------------
      Check if stack is empty.
     
      Precondition: None
      Postcondition: Returns true if stack is empty and false otherwise.
    -----------------------------------------------------------------------*/
    
    Order top() const;
    /*------------------------------------------------------------------------
      Retrieve value at the top of stack (if any).
     
      Precondition:  Stack is nonempty
      Postcondition: Value at top of stack is returned, unless the stack is 
      empty; in that case, an error message is displayed and a "garbage
      value" is returned.
    -----------------------------------------------------------------------*/

    void push(const Order& value);
    /*------------------------------------------------------------------------
      Add a value to a stack.

      Precondition:  value is to be added to this stack.
      Postcondition: value is added at top of stack provided.
    -----------------------------------------------------------------------*/
    
    void pop();
    /*------------------------------------------------------------------------
      Remove value at top of stack (if any).

      Precondition:  Stack is nonempty.
      Postcondition: Value at top of stack has been removed, unless the stack
      is empty; in that case, an error message is displayed and
      execution allowed to proceed.
    -----------------------------------------------------------------------*/
    
}; // end of class declaration
    
#endif /* COMPLETEDORDERSTACK_H */
