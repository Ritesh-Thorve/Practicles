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
