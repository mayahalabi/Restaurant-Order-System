/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   DynamicArrayList.h
 * Author: Elise Trad and Maya Halabi
 * The header file for DynamicArrayList class
 */

#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H
#include "MenuItem.h"
#include <fstream>
#include <iostream>
#include <cassert>

class DynamicArrayList {

private:
    /***** Data Members *****/ 
    MenuItem* array;          // Pointer to the dynamic array containing the menu items
    int size;                 // Size of the array
    int capacity;             // Capacity of the array
    
    // resizing of array when capacity is exceeded 
    void resize();
    
public:
    /***** Function Members *****/
    
    /***** Constructor *****/
    DynamicArrayList(int maxSize = 10);
    /*-----------------------------------------------------------------------
      Construct a DynamicArrayList object.
    
      Precondition: None.
      Postcondition: A DynamicArrayList object has been constructed with 
      the specified capacity or a default capacity of 10 if none is provided.
      The list is initially empty (size is set to 0), and the internal
      array is allocated dynamically.
    -----------------------------------------------------------------------*/
    
    /***** Destructor *****/
    ~DynamicArrayList();
    /*------------------------------------------------------------------------
      Class destructor
    
      Precondition:  None
      Postcondition: The dynamic array has been deallocated.
    ------------------------------------------------------------------------*/
    
    /***** Copy Constructor *****/
    DynamicArrayList(const DynamicArrayList& original);
    /*-----------------------------------------------------------------------
      Class Copy Constructor
     
      Precondition:  original is the dynamic array to be copied and is 
      received as a const reference parameter.
      Postcondition: A copy of original has been constructed.
    -----------------------------------------------------------------------*/
    
    void loadMenuFromFile(ifstream& file);
    /*-----------------------------------------------------------------------
      Load menu items from a file into a custom DynamicArrayList
    
      Precondition: ifstream file is open.
      Postcondition: array is filled with the menu items; size 
      and capacity are modified to represent the number of items.
    -----------------------------------------------------------------------*/
    
    void displayMenu(ostream& out) const;
    /*-----------------------------------------------------------------------
      Display items stored in the array
     
      Precondition: ostream out is open.
      Postcondition: array's contents have been output to out.
    -----------------------------------------------------------------------*/
    
    void addMenuItem(const MenuItem& item);
    /*-----------------------------------------------------------------------
      Add an item to the array
     
      Precondition: item is to be added to this array.
      Postcondition: item is added at back of this array
      (provided there is room), if not resize() function is called.
    -----------------------------------------------------------------------*/
    
    void deleteMenuItem(int n);
    /*----------------------------------------------------------------------- 
      Remove the item having n as the corresponding id from array (if any)
     
      Precondition: Array is nonempty.
      Postcondition: Item with n as id has been removed, unless
      array is empty; in that case, an error message is displayed
      and execution allowed to proceed.
    -----------------------------------------------------------------------*/
    
    void resetMenu();
    /*-----------------------------------------------------------------------
      Clear all array items
     
      Precondition: None.
      Postcondition: The array is cleared during the program's execution 
      without destroying the object.
    -----------------------------------------------------------------------*/
    
    void saveMenu(ofstream& file);
    /*-----------------------------------------------------------------------
      Save the updated menu list to a file
      
      Precondition: The ofstream file stream is open and writable.
      Postcondition: All items in the array are written to the 
      file in the order they are retrieved from the array.
    ------------------------------------------------------------------------*/
    
    int getSize() const;
    /*-------------------------------------------------------------------
      Getter for size 
     
      Precondition: size should have been initialized.
      Postcondition: size is returned without modifying the class.
    ------------------------------------------------------------------*/
    
    const MenuItem* getArray() const;
    /*-------------------------------------------------------------------
      Getter for array
     
      Precondition: array should have been initialized.
      Postcondition: array is returned without modifying the class.
    ------------------------------------------------------------------*/
    
    MenuItem get(int index) const;
    /*-------------------------------------------------------------------
      Getter for MenuItem at index 
     
      Precondition: index should be in the range [0, size - 1].
      Postcondition: if the index is valid, the MenuItem at the specified 
      index is returned; else an error message is printed and 
      execution is terminated.
    ------------------------------------------------------------------*/
    
}; // end of class declaration

ostream & operator<<(ostream& out, const DynamicArrayList& list);
/*-----------------------------------------------------------------------
  Overloaded << operator for the DynamicArrayList class
     
  Precondition: ostream out is open and list is initialized.
  Postcondition: array's contents have been output to out.
-----------------------------------------------------------------------*/

#endif /* DYNAMICARRAYLIST_H */
