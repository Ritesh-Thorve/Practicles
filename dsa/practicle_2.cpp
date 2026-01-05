//Create a C++ program using a 2D array to store & display marks of multiple students in multiple subjects using encapsulation

#include <iostream>
#include <string>
using namespace std;

class StudentMarks {
private:
    string studentNames[100];   // Array to store student names
    int marks[100][10];         // 2D array: 100 students, 10 subjects
    int numStudents;            // Current number of students
    int numSubjects;            // Total number of subjects

public:
    // Constructor
    StudentMarks(int subjects) {
        numStudents = 0;
        numSubjects = subjects;
    }

    // Function to insert student name and marks
    void insertStudentMarks(string name, int studentMarks[]) {
        if (numStudents < 100) {
            studentNames[numStudents] = name;
            for (int i = 0; i < numSubjects; i++) {
                marks[numStudents][i] = studentMarks[i];
            }
            numStudents++;
            cout << "Marks for \"" << name << "\" added successfully.\n";
        } else {
            cout << "Student list is full!\n";
        }
    }

    // Function to display all student marks
    void displayAllMarks() {
        if (numStudents == 0) {
            cout << "No student marks available.\n";
            return;
        }

        cout << "\nStudent Marks:\n";
        cout << "--------------------------------------------------\n";
        cout << "Name\t\t";
        for (int i = 1; i <= numSubjects; i++) {
            cout << "Sub" << i << "\t";
        }
        cout << endl;

        for (int i = 0; i < numStudents; i++) {
            cout << studentNames[i] << "\t\t";
            for (int j = 0; j < numSubjects; j++) {
                cout << marks[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    int subjects;
    cout << "Enter number of subjects: ";
    cin >> subjects;
    cin.ignore();

    StudentMarks myClass(subjects);

    int choice;
    do {
        cout << "\n===== Student Marks Menu =====" << endl;
        cout << "1. Insert Student Marks" << endl;
        cout << "2. Display All Marks" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name;
            int studentMarks[10]; // Max 10 subjects

            cout << "Enter student name: ";
            getline(cin, name);

            for (int i = 0; i < subjects; i++) {
                cout << "Enter marks for Subject " << (i + 1) << ": ";
                cin >> studentMarks[i];
            }
            cin.ignore();

            myClass.insertStudentMarks(name, studentMarks);
            break;
        }
        case 2:
            myClass.displayAllMarks();
            break;
        case 3:
            cout << "Exiting Student Marks Manager. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}



/*
Theory:
This C++ program demonstrates how marks of multiple students in multiple subjects can be stored and displayed using a 2D array while following the principle of encapsulation in Object-Oriented Programming (OOP).

The program defines a class StudentMarks that encapsulates data members and member functions. Student names are stored in a one-dimensional array, while marks are stored in a two-dimensional array, where:

Rows represent students

Columns represent subjects

Encapsulation is achieved by declaring data members (studentNames, marks, numStudents, numSubjects) as private, which prevents direct access from outside the class. Interaction with the data is allowed only through public member functions, ensuring data security and controlled access.

A constructor is used to initialize the number of subjects and set the initial student count to zero. This ensures proper object initialization at runtime.

The program uses:

2D arrays for structured data storage

Loops to insert and display marks

Menu-driven logic to allow user interaction

Overall, this program provides a clear example of using encapsulation with 2D arrays in C++ to manage student marks efficiently in an organized and secure manner.

*/
