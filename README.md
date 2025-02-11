# Restaurant Order Management System (C++)

## Overview

The Restaurant Order Management System is designed to assist restaurant staff in managing menu items and customer orders efficiently. Developed in C++, this system provides a simple and intuitive interface for restaurant operations. It leverages custom data structures such as dynamic arrays, dynamic-array lists, stacks, and queues to ensure smooth management of orders.

Key features of the system include:
- Loading menu items from a file.
- Displaying and managing menu items.
- Managing customer orders through a queue.
- Serving orders and maintaining a stack of completed orders.
- Calculating total revenue based on completed orders.
- Saving both the menu and completed orders to files.

## Features

- **Load Menu from File**: Load menu items from a file into a dynamic array list.
- **Display Menu**: View all current menu items.
- **Add Menu Item**: Add new items to the menu.
- **Delete Menu Item**: Remove items from the menu.
- **Reset Menu**: Clear the entire menu.
- **Add Order**: Add a customer order (which can include multiple items) to the order queue.
- **Process Next Order**: Serve the next order from the queue and move it to the stack of completed orders.
- **Display Orders**: Display both active and completed orders.
- **Delete Order**: Cancel an active order.
- **Calculate Total Revenue**: Calculate the revenue generated from completed orders.
- **Save Completed Orders to File**: Save details of completed orders to a file.
- **Save Menu to File**: Save the updated menu to a file.

## Data Structures Used

- **DynamicArrayList**: A custom dynamic array class to manage menu items.
- **Queue**: A custom queue class to manage customer orders.
- **Stack**: A custom stack class to manage completed orders.

## Requirements

To build and run the system, you need:
- C++ compiler (e.g., GCC, Clang, MSVC)
- Basic knowledge of C++ and data structures like dynamic arrays, queues, and stacks.

## Getting Started

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/your-username/restaurant-order-management-system.git
    ```

2. Navigate into the project directory:
    ```bash
    cd restaurant-order-management-system
    ```

3. Compile the C++ files:
    ```bash
    g++ -o restaurant_system main.cpp DynamicArrayList.cpp Queue.cpp Stack.cpp
    ```

4. Run the program:
    ```bash
    ./restaurant_system
    ```

## File Structure

- `main.cpp`: The entry point of the application.
- `DynamicArrayList.cpp`: Implementation of the dynamic array list for managing the menu.
- `Queue.cpp`: Implementation of the queue for managing active orders.
- `Stack.cpp`: Implementation of the stack for completed orders.
- `menu.txt`: Example file containing menu items (for loading into the system).
- `completed_orders.txt`: File to save completed order details.

## Contributing

Feel free to fork the repository and submit pull requests for any improvements or bug fixes. All contributions are welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
