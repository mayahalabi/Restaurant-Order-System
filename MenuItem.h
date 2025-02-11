/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MenuItem.h
 * Author: Elise Trad and Maya Halabi
 * The header file for MenuItem class
 */

#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>   
#include <iostream> 
using namespace std;

class MenuItem {
private:
    /***** Data Members *****/ 
    int id;                   // represents the id of the item
    string name;              // represents the name of the item
    string description;       // represents the description of the item
    double price;             // represents the price of the item
    
public:
    /***** Function Members *****/
    
    /***** Constructor *****/
    MenuItem(int i = 0, string n = "", string d = "", double p = 0);
    /*-------------------------------------------------------------------
      Class Constructor 
     
      Precondition: i, n, d and p are received
      Postcondition: A MenuItem has been constructed with i in its id
      part, n in it's name part, d in its description part and its price 
      part set to p (if provided, if not their default values are used).
    ------------------------------------------------------------------*/
    
    void setId(int i);
    /*-------------------------------------------------------------------
      Setter for id
     
      Precondition: i should be greater to 0.
      Postcondition: id data field is updated to the provided i value 
      if greater than 0 and to 1 if not.
    ------------------------------------------------------------------*/
    
    void setName(string n);
    /*-------------------------------------------------------------------
      Setter for name
     
      Precondition: None.
      Postcondition: name data field is updated to the provided 
      n value.
    ------------------------------------------------------------------*/
    
    void setDescription(string d);
    /*-------------------------------------------------------------------
      Setter for description 
     
      Precondition: None.
      Postcondition: description data field is updated to the 
      provided d value.
    ------------------------------------------------------------------*/
    
    void setPrice(double p);
    /*-------------------------------------------------------------------
      Setter for price 
     
      Precondition: p is greater than 0.
      Postcondition: price data field is updated to the provided p 
      value if it's greater than 0 and 1 if not.
    ------------------------------------------------------------------*/
    
    int getId() const;
    /*-------------------------------------------------------------------
      Getter for id 
     
      Precondition: None.
      Postcondition: id is returned without modifying the class.
    ------------------------------------------------------------------*/
    
    string getName() const;
    /*-------------------------------------------------------------------
      Getter for name 
     
      Precondition: None.
      Postcondition: name is returned without modifying the class.
    ------------------------------------------------------------------*/
    
    string getDescription() const;
    /*-------------------------------------------------------------------
      Getter for description 
     
      Precondition: None.
      Postcondition: description is returned without modifying 
      the class.
    ------------------------------------------------------------------*/
    
    double getPrice() const;
    /*-------------------------------------------------------------------
      Getter for price 
     
      Precondition: None.
      Postcondition: price is returned without modifying the class.
    ------------------------------------------------------------------*/
    
    void display(ostream& out) const;
    /*-----------------------------------------------------------------------
      Display item's info in the menuItem object.
     
      Precondition: ostream out is open.
      Postcondition: item's info have been output to out.
    -----------------------------------------------------------------------*/
    
}; // end of class declaration
    
ostream& operator<<(ostream& out, const MenuItem& item);
/*-----------------------------------------------------------------------
  Overloaded << operator for the class MenuItem
     
  Precondition: ostream out is open and item is initialized.
  Postcondition: item's info have been output to out.
-----------------------------------------------------------------------*/

#endif /* MENUITEM_H */
