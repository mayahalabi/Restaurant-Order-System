/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Order.h
 * Author: Elise Trad and Maya Halabi
 * the header file for order class
 */

#ifndef ORDER_H
#define ORDER_H
#include "MenuItem.h"            
#include "DynamicArrayList.h"    

class Order {
private:
    /***** Data Members *****/
    int orderId;               // int representing the id of the order
    string customerName;       // string representing the name of the customer
    DynamicArrayList itemList; /* DynamicArrayList object representing the items 
                                  bought by the customer */

public:
    /***** Function Members *****/
    
    /***** Constructor *****/
    Order(int i, string c, const DynamicArrayList& items);
    /*-------------------------------------------------------------------
      Class Constructor 
     
      Precondition: i, c and items are received
      Postcondition: An Order has been constructed with i in its
      orderId part, c in it's customerName part and items in its 
      itemList part.
    ------------------------------------------------------------------*/
    
    /***** Copy Constructor *****/
    Order(const Order& original);
    /*-----------------------------------------------------------------------
      Class Copy Constructor
     
      Precondition:  original is the order object to be copied and is 
      received as a const reference parameter.
      Postcondition: A copy of original has been constructed.
  -----------------------------------------------------------------------*/
    
    void setOrderId(int id);
    /*-------------------------------------------------------------------
      Setter for orderId
     
      Precondition: id is greater than 0.
      Postcondition: orderId data field is updated to the provided 
      id value if it's greater than 0, else to 1.
    ------------------------------------------------------------------*/
        
    void setCustomerName(string name);
    /*-------------------------------------------------------------------
      Setter for customerName 
     
      Precondition: None.
      Postcondition: customerName data field is updated 
      to the provided name value.
    ------------------------------------------------------------------*/
    
    int getOrderId() const;
    /*-------------------------------------------------------------------
      Getter for orderId
     
      Precondition: orderId should have been set.
      Postcondition: orderId is returned without modifying the 
      class.
    ------------------------------------------------------------------*/
        
    string getCustomerName() const;
    /*-------------------------------------------------------------------
      Getter for customerName
     
      Precondition: customerName should have been set.
      Postcondition: customerName is returned without modifying 
      the class.
    ------------------------------------------------------------------*/
        
    const DynamicArrayList& getItemList() const;
    /*-------------------------------------------------------------------
      Getter for itemList
     
      Precondition: itemList should have been initialized.
      Postcondition: DynamicArrayList object is returned by reference 
      without modifying the class.
    ------------------------------------------------------------------*/
    
    void display(ostream& out) const;
    /*-----------------------------------------------------------------------
      Display order's info in the menuItem object.
     
      Precondition: ostream out is open.
      Postcondition: order's info have been output to out.
    -----------------------------------------------------------------------*/

    double total() const;
    /*-----------------------------------------------------------------------
      Return the order's total revenue
     
      Precondition: itemList should have been initialized.
      Postcondition: sum of the items' prices in itemList is returned.
    -----------------------------------------------------------------------*/
    
}; // end of class declaration

ostream& operator<<(ostream& out, const Order& order);
/*-----------------------------------------------------------------------
  Overloaded << operator for the class order
     
  Precondition: ostream out is open and item is initialized.
  Postcondition: order's info have been output to out.
-----------------------------------------------------------------------*/
#endif /* ORDER_H */

