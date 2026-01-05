//Name: Create An array to store student names  in class, allowing: insertions, deletions and traversal


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



Theory:
Theory Explanation of Student List Program (C++)
1. Purpose of the Program
This program implements a Student List Management System using Object-Oriented Programming (OOP) concepts in C++.
It allows the user to:
•	Insert student names
•	Delete student names
•	Display the list of students
using a menu-driven approach.
________________________________________
2. Header Files Used
#include <iostream>
#include <string>
•	<iostream>: Used for input and output operations (cin, cout).
•	<string>: Used to handle string data type for student names.
________________________________________
3. Class Definition: StudentList
The program uses a class to represent the student list, following encapsulation.
Private Data Members
string students[100];
int count;
•	students[100]: Array to store up to 100 student names.
•	count: Keeps track of the current number of students.
Private access ensures data security.
________________________________________
4. Constructor
StudentList() {
    count = 0;
}
•	Initializes the student count to zero.
•	Automatically called when an object of the class is created.
•	Ensures the list starts empty.
________________________________________
5. Member Functions
a) Insert Student
void insertStudent(string name)
•	Checks if the list is not full.
•	Adds the student name at the next available index.
•	Increments the count.
•	Displays a success message.
Concept Used:
Array insertion, condition checking.
________________________________________
b) Delete Student
void deleteStudent(string name)
•	Searches for the student name in the array.
•	If found, shifts remaining elements left to fill the gap.
•	Decreases the count.
•	If not found, displays an error message.
Concept Used:
Linear search and array deletion.
________________________________________
c) Display Students
void displayStudents()
•	Checks if the list is empty.
•	Displays all student names with serial numbers.
Concept Used:
Looping and formatted output.
________________________________________
6. Main Function
int main()
•	Creates an object myClass of StudentList.
•	Uses a do-while loop to display a menu repeatedly.
•	Uses switch-case for menu selection.
•	Takes user input and calls appropriate class functions.
________________________________________
7. Menu-Driven Approach
The program provides four options:
1.	Insert student name
2.	Delete student name
3.	Display all students
4.	Exit program
This approach improves user interaction and control flow.
________________________________________
8. Key Concepts Demonstrated
•	Object-Oriented Programming (Class & Object)
•	Encapsulation
•	Arrays
•	Strings
•	Looping (for, do-while)
•	Conditional statements
•	Menu-driven programming
________________________________________

9. Advantages of the Program
•	Simple and easy to understand
•	Organized using OOP principles
•	Prevents data overflow using size checks
•	Suitable for small-scale student management
________________________________________
10. Limitation
•	Fixed array size (maximum 100 students)
•	No data persistence (data lost when program ends)

