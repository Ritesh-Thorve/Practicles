#include <iostream>
#include <string>
using namespace std;

class StudentList {
private:
    string students[100]; // Array to store student names
    int count;            // Tracks number of students

public:
    // Constructor
    StudentList() {
        count = 0;
    }

    // Function to insert a student
    void insertStudent(string name) {
        if (count < 100) {
            students[count++] = name;
            cout << "Student \"" << name << "\" added successfully.\n";
        } else {
            cout << "Student list is full!\n";
        }
    }

    // Function to delete a student
    void deleteStudent(string name) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (students[i] == name) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                students[i] = students[i + 1];
            }
            count--;
            cout << "Student \"" << name << "\" deleted successfully.\n";
        } else {
            cout << "Student \"" << name << "\" not found!\n";
        }
    }

    // Function to display all students
    void displayStudents() {
        if (count == 0) {
            cout << "No students in the list.\n";
            return;
        }

        cout << "\nList of Students:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << students[i] << endl;
        }
    }
};

// Main function
int main() {
    StudentList myClass;
    int choice;
    string name;

    do {
        cout << "\n===== Student List Menu =====" << endl;
        cout << "1. Insert Student Name" << endl;
        cout << "2. Delete Student Name" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Handle newline

        switch (choice) {
        case 1:
            cout << "Enter student name to insert: ";
            getline(cin, name);
            myClass.insertStudent(name);
            break;

        case 2:
            cout << "Enter student name to delete: ";
            getline(cin, name);
            myClass.deleteStudent(name);
            break;

        case 3:
            myClass.displayStudents();
            break;

        case 4:
            cout << "Exiting Student List Manager. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
