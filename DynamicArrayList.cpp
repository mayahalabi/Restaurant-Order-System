/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   DynamicArrayList.cpp
 * Author: Elise Trad and Maya Halabi
 * The implementation file for DynamicArrayList class
 */

#include "DynamicArrayList.h"
using namespace std;

//--- Definition of class constructor
DynamicArrayList::DynamicArrayList(int maxSize) {
    if(maxSize <= 0) { // check if the provided size is valid
        cerr << "Invalid capacity" << endl;
        maxSize = 10;  // Set to default value
    }
    array = new(nothrow) MenuItem[maxSize];
    assert(array != NULL); // check if memory available
    size = 0;
    capacity = maxSize;
}

//--- Definition of class destructor
DynamicArrayList::~DynamicArrayList() {
    delete[] array;
    array = NULL; // avoiding dangling pointers
}

//--- Definition of copy constructor
DynamicArrayList::DynamicArrayList(const DynamicArrayList& orig) 
: size(orig.size), capacity(orig.capacity) {
    array = new MenuItem[capacity];
    if (array != NULL)                     // check if memory available
        //--- Copy origList's elements into this new array
        for(int i = 0; i < size; i++)
            array[i] = orig.array[i];
    else {
      cerr << "*** Inadequate memory to allocate storage for list ***\n";
      exit(1);
    }
}
        
//--- Definition of loadMenuFromFile function
void DynamicArrayList::loadMenuFromFile(ifstream& file) {
    if (!file.is_open()) {
        cerr << "Error: file is not open." << endl;
        return;
    }

    int i = 0; // first position in the array
    int id;
    string name, description;
    double price;
    
    // loop as long as it reads a new id in the file
    while (file >> id) {                   
        file.ignore(1, ',');               // Skip comma after id
        getline(file, name, ',');          // Read name and comma
        getline(file, description, ',');   // Read description and comma
        file >> price;                     // Read price
        file.ignore(1, '\n');              // Skip newline

        // check if array's capacity is sufficient
        if (i >= capacity) {
            resize(); // Double the capacity if needed
        }
        
        // construct a temporal menuItem object
        MenuItem temp(id, name, description, price); 
        array[i++] = temp; // add it to the array then increments i
    }

    size = i; // Update the size to the number of items added to the aray
}

//--- Definition of the display function
void DynamicArrayList::displayMenu(ostream& out) const {
    out << "--- Menu Items ---" << endl;
    for(int i = 0; i < size; i++) { // operator << is overloaded in MenuItem 
        out << "ID: " << array[i] 
                << endl;
    }
}

//--- Definition of the overloaded operator <<
ostream& operator<<(ostream & out, const DynamicArrayList & list) {
    list.displayMenu(out);
    return out;
}
 
//--- Definition of addMenuItem function
void DynamicArrayList::addMenuItem(const MenuItem& item) {
    if(size == capacity)
        resize();
    // Now add item then increase list's size  
    array[size++] = item;
}
        
//--- Definition of deleteMenuItem function
void DynamicArrayList::deleteMenuItem(int n) {
    if(size == 0) { // array is empty
        cerr << "*** List is empty ***\n";
        return;
    }

    int index = -1; // represents the index of the item to delete
    // loop to search for the item to delete
    for(int i = 0; i < size; i++) {
        if(n == array[i].getId()) {
            index = i; // if found update index
            break;
        }
    }

    if (index == -1) { // item is not in the list
        cerr << "*** ID not found -- List unchanged. ***\n";
        return;
    }

    // Shift the elements to fill the gap
    for(int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--; // decrement size by one
    cout << "The item with id " << n << " has been successfully deleted.\n";
}

//--- Definition of resetMenu function
void DynamicArrayList::resetMenu() {
    MenuItem temp;                   // construct a default(garbage) menuItem
    for (int i = 0; i < size; ++i) { // loop to add it to the array 
         array[i] = temp; 
    }
    // update size 
    size = 0; 
}

//--- Definition of saveMenu function
void DynamicArrayList::saveMenu(ofstream& file) {
    if (!file.is_open()) {
        cerr << "Error: file is not open." << endl; 
        return;
    }
    for (int i = 0; i < size; ++i) { // loop to display all items in the array
        file << array[i] << endl; // << operator is overloaded in menuItem
    }
} 

//--- Definition of size getter
int DynamicArrayList::getSize() const {
    return size;
}

//--- Definition of array getter
const MenuItem* DynamicArrayList::getArray() const {
    return array;
}

//--- Definition of get function
MenuItem DynamicArrayList::get(int index) const {
    if (index < 0 || index >= size) { // error message if index is invalid
        cerr << "Error: Index out of range --- returning garbage value.\n" 
                << endl;
        exit(1);
    }
    return array[index];
}

//--- Definition of resize function
void DynamicArrayList::resize() {
    capacity *= 2; // double initial capacity
    MenuItem* newArray = new MenuItem[capacity]; // allocate a temporary 
                                                 // array with doubled capacity
    for(int i = 0; i < size; i++) 
        newArray[i] = array[i];
    delete[] array;   // delete old array
    array = newArray; // assign the pointer to the new array
}