/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Elise Trad and Maya Halabi
 *
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
#include "ActiveOrderQueue.h"
#include "DynamicArrayList.h"  
#include "CompletedOrderStack.h" 

void displayOptions(DynamicArrayList& list, 
                    ActiveOrderQueue& myActiveOrders, 
                    CompletedOrderStack& myCompletedOrders) {
    int choice;
    do {
    cout << "\n--- Restaurant Order Management System ---\n";
    cout << "1. Display Menu\n"
            << "2. Add Menu Item\n"
            << "3. Delete Menu Item\n"
            << "4. Reset Menu\n"
            << "5. Add New Order\n"
            << "6. Process next Order\n"
            << "7. Display Orders\n"
            << "8. Delete Order\n"
            << "9. Calculate Total Amount of Sold Orders\n"
            << "10. Save Completed Orders to File\n"
            << "11. Exit\n"
            << "Enter your choice: ";
    cin >> choice;
    cout << choice;
    cin.ignore(); // Ignore the newline character after reading choice

    cout << endl << endl;

    switch (choice) {
        case 1:
            list.displayMenu(cout); // Display the menu
            break;
        case 2: {
            string name, description;
            double price;
            cout << "--- Adding a new Item ---" << endl;
            cout << "Enter name: ";
            getline(cin, name); // read a string for the name
            cout << name << endl;
            cout << "Enter description: ";
            getline(cin, description); // read a string for the description
            cout << description << endl;
            cout << "Enter price: ";
            cin >> price; // cin to read the double for the price
            cout << price << endl;
            // To consume the leftover newline character after reading the price
            cin.ignore(); 
            // add item with generated id using the size of the array
            MenuItem newItem(list.getSize() + 1, name, description, price);
            list.addMenuItem(newItem);
            cout << "The item " 
                    << name 
                    << " has been added to the menu with the id " 
                    << newItem.getId()
                    << endl;
        }
        break; 
        case 3: {
            int id;
            cout << "Deleting item --- Enter the id: ";
            cin >> id;
            cin.ignore();
            list.deleteMenuItem(id);
        }    
        break;
        case 4:
            list.resetMenu();
            cout << "Menu reseted successfully!" << endl;
            break;
        case 5: {
            cout << "Enter customer name: " << endl;
            string name;
            getline(cin, name);
            
            cout << "Enter item IDs (0 to finish):" << endl;
            DynamicArrayList boughtItems;
            int nb;
            
            // Read item IDs until the user enters 0 to stop
            while (true) {                
                cin >> nb;
                cin.ignore(); // Consume the leftover newline character from previous input

                if (nb == 0) {
                    break; // exit loop if the user enters 0
                } 
                else // send nb - 1 as argument because the id is added using size + 1
                    boughtItems.addMenuItem(list.get(nb - 1));
            }
            Order order(myActiveOrders.size() + 1, name, boughtItems);
            myActiveOrders.addOrder(order);
            cout << "Order added successfully!" << endl;
        }
        break;
        case 6:
            myActiveOrders.processNextOrder(myCompletedOrders);
            break;
        case 7:
            myActiveOrders.displayActiveOrders(cout);
            myCompletedOrders.displayCompletedOrders(cout);
            break;
        case 8: {
            cout << "--- Deleting order ---\nPlease enter order's id: ";
            int id;
            cin >> id;
            cin.ignore();
            myActiveOrders.deleteOrder(id);
            break;
        }
        case 9:
            myCompletedOrders.calculateTotalRevenue();
            break;
        case 10: {
            ofstream file("C:\\Users\\HP\\Desktop\\fall 24-25\\DS\\project given\\completed_orders.txt"); 
            if (file.is_open()) {
                myCompletedOrders.saveCompletedOrders(file); // Call saveCompletedOrders to write to file
                file.close(); // Close the file
                cout << "Completed Orders saved to file successfully." << endl;
            } 
            else {
                cerr << "Error: could not open file to save menu." << endl;
            }
        }
        break;
        case 11:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
    } while(choice != 11);
}

int main(int argc, char** argv) {
    // Open the file
    ifstream file("C:\\Users\\HP\\Desktop\\fall 24-25\\DS\\project given\\menu.txt");
    DynamicArrayList list(20);
    list.loadMenuFromFile(file);
    ActiveOrderQueue myActiveOrders;
    CompletedOrderStack myCompletedOrders;
    displayOptions(list, myActiveOrders, myCompletedOrders);

    //file.close();
    return 0;
}
