#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string firstName;
    string lastName;
    double cgpa;
};

// Global vector to store students
vector<Student> students;

// Function to add a student
void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;

    // Check for duplicate roll number
    for (const auto& stu : students) {
        if (stu.rollNumber == s.rollNumber) {
            cout << "Error: Student with this roll number already exists.\n";
            return;
        }
    }

    cout << "Enter First Name: ";
    cin >> s.firstName;
    cout << "Enter Last Name: ";
    cin >> s.lastName;
    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    students.push_back(s);
    cout << "Student added successfully.\n";
}

// Function to display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }

    cout << "Student Records:\n";
    for (const auto& s : students) {
        cout << "Roll: " << s.rollNumber
             << ", Name: " << s.firstName << " " << s.lastName
             << ", CGPA: " << s.cgpa << "\n";
    }
}

// Function to search student by roll number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to search: ";
    cin >> roll;

    for (const auto& s : students) {
        if (s.rollNumber == roll) {
            cout << "Student found: " << s.firstName << " " << s.lastName
                 << ", CGPA: " << s.cgpa << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to update student details
void updateStudent() {
    int roll;
    cout << "Enter Roll Number to update: ";
    cin >> roll;

    for (auto& s : students) {
        if (s.rollNumber == roll) {
            cout << "Updating details for " << s.firstName << " " << s.lastName << "\n";
            cout << "Enter new First Name: ";
            cin >> s.firstName;
            cout << "Enter new Last Name: ";
            cin >> s.lastName;
            cout << "Enter new CGPA: ";
            cin >> s.cgpa;
            cout << "Student record updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to delete a student record
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == roll) {
            students.erase(it);
            cout << "Student record deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\nStudent Records Management System\n";
        cout << "1. Add Student\n"
             << "2. Display All Students\n"
             << "3. Search Student\n"
             << "4. Update Student\n"
             << "5. Delete Student\n"
             << "6. Exit\n"
             << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
