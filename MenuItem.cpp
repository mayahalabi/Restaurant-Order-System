/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MenuItem.h
 * Author: Elise Trad and Maya Halabi
 * The implementation file of the MenuItem class
 */
#include "MenuItem.h"

//--- Definition of constructor
MenuItem::MenuItem(int i, string n, string d, double p)
        : id(i), name(n), description(d), price(p) {}
    
//--- Definition of id setter
void MenuItem::setId(int i) {
    if(i > 0)
        id = i;
    else {
        cout << "Invalid ID. Setting ID to 1." << endl;
        id = 1;
    }
}
     
//--- Definition of name setter
void MenuItem::setName(string n) {
    name  = n;
}
      
//--- Definition of description setter
void MenuItem::setDescription(string d) {
    description = d;
}
    
//--- Definition of price setter
void MenuItem::setPrice(double p) {
    if(p > 0)
        price = p;
    else {
        cout << "Invalid price. Setting price to 1." << endl;
        price = 1;
    }
}
    
//--- Definition of id getter
int MenuItem::getId() const {
    return id;
}
    
//--- Definition name getter
string MenuItem::getName() const {
    return name;
}
    
//--- Definition of description getter
string MenuItem::getDescription() const {
    return description;
}
    
//--- Definition of price getter
double MenuItem::getPrice() const {
    return price;
}  

//--- Definition of the display function
void MenuItem::display(ostream& out) const{
    out <<   "ID: " << id
                << ", Name: " << name
                << ", Price: $" << price 
                << endl;
}

//--- Definition of the overloaded operator <<
ostream& operator<<(ostream& out, const MenuItem& item) {
    item.display(out);
    return out;
}