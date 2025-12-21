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
