// 8] Implement DFS to find paths in a city’s metro rail system represented as a graph using an adjacency list.

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
string name;
int rollNo;

public:
void setPerson(string n, int r) {
name = n;
rollNo = r;
}

void displayPerson() {
cout << "Name: " << name << ", Roll No: " << rollNo << endl;
}
};

// Academic class – virtual inheritance
class Academic : virtual public Person {
protected:
float marksMath;
float marksScience;

public:
void setAcademic(float m, float s) {
marksMath = m;
marksScience = s;
}

void displayAcademic() {
cout << "Academic Marks: Math = " << marksMath
<< ", Science = " << marksScience << endl;
}
};

// Extracurricular class – virtual inheritance
class Extracurricular : virtual public Person {

protected:
int sportsScore;
int artScore;

public:
void setExtracurricular(int sport, int art) {
sportsScore = sport;
artScore = art;
}

void displayExtracurricular() {
cout << "Extracurricular Scores: Sports = " << sportsScore
<< ", Art = " << artScore << endl;
}
};

// Final derived class using hybrid inheritance
class Result : public Academic, public Extracurricular {
public:
void displayResult() {
displayPerson();
displayAcademic();
displayExtracurricular();

float totalAcademic = marksMath + marksScience;
int totalExtra = sportsScore + artScore;
cout << "Total Academic = " << totalAcademic << ", Total Extracurricular = " <<
totalExtra << endl;
}
};

// Main function
int main() {
Result student;

// Setting values
student.setPerson("Amar", 101);
student.setAcademic(85.5, 92.0);
student.setExtracurricular(8, 9);

// Displaying complete result
cout << "\n--- Student Report ---\n";
student.displayResult();

return 0;
}


/*
Theory:
Theory Covered by the Program

This program demonstrates Object-Oriented Programming (OOP) concepts in C++, with special focus on inheritance types, especially virtual inheritance and hybrid inheritance.

1. Object-Oriented Programming (OOP)

The program is designed using classes and objects.

Data and related functions are bundled together, improving modularity and reusability.

2. Base Class

Person is the base (parent) class.

It stores common attributes such as name and roll number.

These attributes are shared by all derived classes.

3. Inheritance

Inheritance allows one class to acquire properties of another class.

a) Single Inheritance

Academic and Extracurricular both inherit from Person.

b) Virtual Inheritance

Both Academic and Extracurricular inherit Person virtually.

This avoids duplication of Person data members when inherited by the final class.

Solves the Diamond Problem in multiple inheritance.

4. Diamond Problem

Occurs when two classes inherit from the same base class and a derived class inherits from both.

Without virtual inheritance, multiple copies of base class members would exist.

Virtual inheritance ensures only one shared copy of the base class.

5. Multiple Inheritance

Result class inherits from both Academic and Extracurricular.

Combines academic and extracurricular performance into one final result.

6. Hybrid Inheritance

The program uses hybrid inheritance, which is a combination of:

Single inheritance

Multiple inheritance

Virtual inheritance

Result is derived from multiple classes that themselves inherit from a common base.

7. Encapsulation

Data members are declared as protected, allowing controlled access to derived classes.

Access to data is managed through member functions.

8. Method Reuse

Functions like displayPerson(), displayAcademic(), and displayExtracurricular() are reused in the Result class.

Promotes code reusability and maintainability.

9. Data Aggregation and Processing

The program calculates:

Total academic marks

Total extracurricular scores

Demonstrates combining data from multiple inheritance paths.
*/
