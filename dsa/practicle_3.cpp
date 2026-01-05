// Implement a Student record system using singly linked list that support creating, inserting, deleting and display record

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = nullptr;
    }

    // Insert a student at the end
    void insertStudent(int roll, string name, float marks) {
        Student* newNode = new Student();
        newNode->rollNo = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Student* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Record inserted successfully.\n";
    }

    // Delete a student by roll number
    void deleteStudent(int roll) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Student* temp = head;
        Student* prev = nullptr;

        if (temp != nullptr && temp->rollNo == roll) {
            head = temp->next;
            delete temp;
            cout << "Record deleted successfully.\n";
            return;
        }

        while (temp != nullptr && temp->rollNo != roll) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Record not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Record deleted successfully.\n";
    }

    // Display all student records
    void displayRecords() {
        if (head == nullptr) {
            cout << "No records to display.\n";
            return;
        }

        Student* temp = head;
        cout << "\n--- Student Records ---\n";
        while (temp != nullptr) {
            cout << "Roll No: " << temp->rollNo
                 << "\nName: " << temp->name
                 << "\nMarks: " << temp->marks << "\n\n";
            temp = temp->next;
        }
    }
};

int main() {
    StudentList list;
    int choice, roll;
    string name;
    float marks;

    do {
        cout << "\n===== Student Record Menu =====\n";
        cout << "1. Insert Student\n"
             << "2. Delete Student\n"
             << "3. Display Students\n"
             << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
            list.insertStudent(roll, name, marks);
            break;

        case 2:
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            list.deleteStudent(roll);
            break;

        case 3:
            list.displayRecords();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}



/*
Theory:
Theory Explanation: Student Record System Using Singly Linked List

This program implements a Student Record Management System using a singly linked list in C++. A linked list is a dynamic data structure in which elements (nodes) are connected using pointers, allowing efficient insertion and deletion without shifting elements, unlike arrays.

Singly Linked List Concept

Each student record is represented as a node containing:

Student roll number

Student name

Student marks

A pointer (next) to the next node in the list

The next pointer links one student record to the next, forming a chain-like structure. The last node points to NULL, indicating the end of the list.

Structure Definition

The Student structure defines the layout of each node. It combines data fields and a link pointer, which is a fundamental concept of linked lists.

Encapsulation Using Class

The StudentList class encapsulates the linked list operations:

The head pointer (private) stores the address of the first node.

All operations on the list are performed using public member functions, ensuring controlled access to the data.

Insertion Operation

Insertion is performed at the end of the linked list. A new node is dynamically created using memory allocation, its data fields are initialized, and it is linked to the last node. If the list is empty, the new node becomes the first node.

Deletion Operation

Deletion is carried out by searching for a student using the roll number. If the record is found:

The node is removed by adjusting pointer links.

The memory occupied by the node is freed.
This process ensures efficient deletion without shifting records.

Display Operation

The display function traverses the linked list from the head node to the last node and prints each student’s details. Traversal continues until a NULL pointer is encountered.

Menu-Driven Approach

The program uses a menu-driven interface, allowing users to insert, delete, and display student records interactively. This improves usability and demonstrates control flow using loops and conditional statements.

Key Advantages

Dynamic memory allocation

Efficient insertion and deletion

No fixed size limitation

Organized data management using linked lists
*/
