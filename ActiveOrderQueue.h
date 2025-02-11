/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ActiveOrderQueue.h
 * Author: Elise Trad and Maya Halabi
 * The header file for ActiveOrderQueue
 */

#ifndef ACTIVEORDERQUEUE_H
#define ACTIVEORDERQUEUE_H
#include "Order.h"               
#include "CompletedOrderStack.h" 

class ActiveOrderQueue {
    
private:
    /*** Node class ***/
    class Node {
    public:
        Order data;
        Node* next;
        // Node constructor
        Node(Order order, Node * n = NULL)
        /*-------------------------------------------------------------------
          Precondition: value and n are received
          Postcondition: A Node has been constructed with value in its
          data part and its next part set to n (default NULL).
        ------------------------------------------------------------------*/
        : data(order), next(n)
        {}
    };
    typedef Node* NodePtr;
    
    /***** Data Members *****/   
    NodePtr myFront,          // Pointer to front of queue
            myBack;           // Pointer to back of queue
    
public:
    /***** Function Members *****/
    
    /***** Constructor *****/
    ActiveOrderQueue();
    /*-----------------------------------------------------------------------
      Construct a ActiveOrderQueue object.
    
      Precondition: None.
      Postcondition: An empty ActiveOrderQueue object has been constructed
      (myFront and myBack are initialized to null pointers).
    -----------------------------------------------------------------------*/    
    
    /***** Destructor *****/
    ~ActiveOrderQueue();
    /*-----------------------------------------------------------------------
      Class destructor 
      
      Precondition:  None.
      Postcondition: The linked list in the ActiveOrderQueue has 
      been deallocated.
    -----------------------------------------------------------------------*/

    void processNextOrder(CompletedOrderStack& stack);
    /*-----------------------------------------------------------------------
      Serve the next order in the ActiveOrderQueue, remove it from
      the queue and add it to the stack of completed orders.
     
      Precondition: ActiveOrderQueue is nonempty and stack exits.
      Postcondition: The front order is dequeued from the queue and added 
      to the stack of completed orders.
    -----------------------------------------------------------------------*/
    
    Order front() const;
    /*-----------------------------------------------------------------------
      Retrieve value at front of queue (if any).

      Precondition:  ActiveOrderQueue is nonempty.
      Postcondition: Value at front of ActiveOrderQueue is returned, unless 
      it's is empty; in that case, an error message is displayed and a 
      garbage(default) value is returned.
    -----------------------------------------------------------------------*/

    bool empty() const;
    /*-----------------------------------------------------------------------
      Check if queue is empty.

      Precondition:  None.
      Postcondition: Returns true if queue is empty and false otherwise.
    -----------------------------------------------------------------------*/

    
    void addOrder(const Order &order);
    /*-----------------------------------------------------------------------
      Add an order to a queue.
     
      Precondition: order is to be added to this queue.
      Postcondition: order is added at back of queue.
    -----------------------------------------------------------------------*/
    
    void displayActiveOrders(ostream& out) const;
    /*-----------------------------------------------------------------------
      Display orders stored in the queue.
     
      Precondition: Ostream out is open.
      Postcondition: Queue's contents, from front to back, have been
      output to out.
    -----------------------------------------------------------------------*/
    
    void deleteOrder(int id);
    /*----------------------------------------------------------------------- 
      Remove the order having the customerId id from queue (if any).
     
      Precondition: Queue is nonempty.
      Postcondition: Removes the order with the specified customerId from 
      the queue. If no such order exists, an error message is displayed.
    -----------------------------------------------------------------------*/
    
    void dequeue();
    /*-----------------------------------------------------------------------
      Remove value at front of queue (if any).

      Precondition:  Queue is nonempty.
      Postcondition: Value at front of queue has been removed, unless
      queue is empty; in that case, an error message is displayed 
      and execution allowed to proceed.
    -----------------------------------------------------------------------*/
    
    int size() const;
    /*-----------------------------------------------------------------------
      Returns the number of orders in the queue
     
      Precondition:  Queue is initialized.
      Postcondition: size of the queue is returned.
    -----------------------------------------------------------------------*/

}; // end of class declaration

#endif /* ACTIVEORDERQUEUE_H */

