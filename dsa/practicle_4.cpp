#include <iostream>
using namespace std;
// Node structure representing each process
struct Process {
char name;
int totalTime;
int remainingTime;
Process* next;
};
// Function to add process to circular linked list
void addProcess(Process* &tail, char name, int totalTime) {
Process* newProc = new Process;
newProc->name = name;
newProc->totalTime = totalTime;
newProc->remainingTime = totalTime;
if (!tail) {
newProc->next = newProc;
tail = newProc;
} else {
newProc->next = tail->next;
tail->next = newProc;
tail = newProc;
}
}
// Function to simulate round robin scheduling
void roundRobin(Process* &tail, int timeQuantum) {

int currentTime = 0;
while (tail) {
Process* prev = tail;
Process* curr = tail->next;
bool processRemoved = false;
do {
if (curr->remainingTime > 0) {
if (curr->remainingTime > timeQuantum) {
curr->remainingTime -= timeQuantum;
currentTime += timeQuantum;
} else {
currentTime += curr->remainingTime;
cout << curr->name << " " << currentTime << endl;
curr->remainingTime = 0;
// Remove completed process node from the list
if (curr == curr->next) {
delete curr;
tail = nullptr;
processRemoved = true;
break;
} else {
prev->next = curr->next;
if (curr == tail) tail = prev;
delete curr;
curr = prev->next;
processRemoved = true;

continue;
}
}
}
prev = curr;
curr = curr->next;
} while (!processRemoved && curr != tail->next);
}
}
int main() {
int n, timeQuantum;
cout << "Enter number of processes: ";
cin >> n;
cout << "Enter time quantum: ";
cin >> timeQuantum;
Process* tail = nullptr;
for (int i = 0; i < n; ++i) {
int totalTime;
cout << "Enter total time for process " << (char)('A' + i) << ": ";
cin >> totalTime;
addProcess(tail, 'A' + i, totalTime);
}
cout << "Completion order and time:" << endl;
roundRobin(tail, timeQuantum);
return 0;
}