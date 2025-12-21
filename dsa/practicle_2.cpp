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
