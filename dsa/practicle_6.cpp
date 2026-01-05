//6] Implement a queue to simulate a customer service system where customers join and leave in FIFO order.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Customer {
    string name;
    int id;
    Customer(string n, int i) : name(n), id(i) {}
};

int main() {
    queue<Customer> service_queue;
    int choice, customer_id = 1;
    string customer_name;

    while (true) {
        cout << "1. Join Queue\n"
             << "2. Serve Customer\n"
             << "3. Display Queue\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter customer name: ";
            cin >> customer_name;

            service_queue.push(Customer(customer_name, customer_id++));
            cout << "Customer added to queue.\n";
        } 
        else if (choice == 2) {
            if (!service_queue.empty()) {
                Customer c = service_queue.front();
                cout << "Serving customer: " << c.name
                     << " (ID: " << c.id << ")\n";
                service_queue.pop();
            } else {
                cout << "Queue is empty!\n";
            }
        } 
        else if (choice == 3) {
            queue<Customer> temp = service_queue;
            cout << "Current queue:\n";
            while (!temp.empty()) {
                Customer c = temp.front();
                cout << c.name << " (ID: " << c.id << ")\n";
                temp.pop();
            }
        } 
        else if (choice == 4) {
            break;
        } 
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}



/*
Theory:
Theory Covered by the Program: Customer Service System Using Queue

This program demonstrates the use of a queue data structure to model a customer service system. The main theoretical concepts covered are:

1. Queue Data Structure

A queue is a linear data structure that follows the FIFO (First In, First Out) principle.

The first element added to the queue is the first one to be removed.

Common operations:

Enqueue (push): Add an element at the rear.

Dequeue (pop): Remove an element from the front.

Front: Access the first element.

2. Real-Life Queue Simulation

The program simulates a service counter where customers join a queue and are served in arrival order.

This reflects real-world scenarios such as banks, ticket counters, or call centers.

3. Use of STL Queue

Uses queue<Customer> from the C++ Standard Template Library (STL).

STL provides built-in, efficient, and reliable implementations of data structures.

Simplifies queue operations without manual implementation.

4. Structure for Data Representation

A struct Customer is used to store customer details:

Customer name

Customer ID

Demonstrates data encapsulation within a structure.

5. FIFO Scheduling Logic

Customers are served strictly in the order they arrive.

Ensures fairness and prevents starvation.

6. Dynamic Queue Handling

Queue size grows and shrinks dynamically as customers join and leave.

No fixed size limitation compared to arrays.

7. Queue Traversal

To display all customers, a temporary queue copy is used.

Preserves the original queue while traversing its elements.

8. Menu-Driven Program

Uses a continuous loop and conditional statements to allow:

Adding customers

Serving customers

Viewing queue status

Enhances user interaction and control flow.

9. Error Handling

Checks for empty queue before serving customers.

Prevents invalid dequeue operations.
*/
