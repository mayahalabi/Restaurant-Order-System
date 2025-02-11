/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Order.cpp
 * Author: Elise Trad and Maya Halabi
 * The implementation file for Order class
 */

#include "Order.h" 
using namespace std;

//--- Definition of class constructor    
Order::Order(int i, string c, const DynamicArrayList& items)
: orderId(i), customerName(c), itemList(items) {} 

//--- Definition of copy constructor
Order::Order(const Order& orig) 
    : orderId(orig.orderId), 
      customerName(orig.customerName), 
      itemList(orig.itemList) // DynamicArrayList defines a copy constructor
{}

//--- Definition of orderId setter
void Order::setOrderId(int id) {
    if(id > 0)
        orderId = id;
    else 
        orderId = 1;
}
  
//--- Definition of customerName setter
void Order::setCustomerName(string name) {
    customerName = name;
}
        
//--- Definition of orderId getter    
int Order::getOrderId() const {
    return orderId;
}

//--- Definition of customerName getter
string Order::getCustomerName() const {
    return customerName;
}
        
//--- Definition of itemList getter
const DynamicArrayList& Order::getItemList() const {
    return itemList;
}

//--- Definition of the display function
void Order::display(ostream& out) const {
    out << "Order ID: " << orderId 
            << ", Customer: " << customerName
            << "\nItems:\n";
    for(int i = 0; i < itemList.getSize(); i++) {
        out << "- "
                << itemList.get(i).getName() 
                << "($" << itemList.get(i).getPrice() << ")" 
                << endl;
    }
    out << "Status: Pending" << endl;
}

//--- Definition of total function
double Order::total() const {
    double sum = 0;
    for(int i = 0; i < itemList.getSize(); i++)
        sum += itemList.get(i).getPrice();
    return sum;
}


//--- Definition of the overloaded operator <<
ostream& operator<<(ostream& out, const Order& order) {
    order.display(out);
    return out;
}
    
