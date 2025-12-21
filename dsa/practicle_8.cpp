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