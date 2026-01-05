//4] Implement a circular linked list to stimulate a round-robin scheduling algorithm for CPU process

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




/*
Theory:
1. Round Robin Scheduling Algorithm

Round Robin is a preemptive CPU scheduling algorithm.

Each process is assigned a fixed time quantum.

If a process does not complete within the time quantum, it is placed at the end of the ready queue.

Ensures fair CPU time distribution and prevents starvation.

2. Circular Linked List

The ready queue of processes is implemented using a circular singly linked list.

The last node points back to the first node, enabling continuous cyclic traversal.

Ideal for Round Robin scheduling because processes are accessed repeatedly in a loop.

3. Dynamic Memory Allocation

Each process node is created dynamically using new.

Memory is freed using delete when a process completes execution.

Demonstrates efficient memory management.

4. Process Control Block (PCB) Representation

Each node represents a process, similar to a PCB in operating systems.

Stores:

Process name

Total CPU burst time

Remaining execution time

Pointer to the next process

5. Time Quantum Concept

A fixed time slice that limits how long a process can execute in one turn.

Smaller quantum improves responsiveness but increases context switching.

Larger quantum behaves closer to FCFS scheduling.

6. Preemption

The CPU is preempted after the time quantum expires.

The process resumes later with updated remaining execution time.

Demonstrates preemptive multitasking.

7. Linked List Traversal

Traverses the circular linked list repeatedly until all processes finish.

Uses pointer manipulation to move between processes.

8. Node Deletion in Linked List

When a process completes, its node is removed from the list.

Pointer links are updated correctly to maintain list integrity.

Handles special cases like deleting the last remaining node.

9. Simulation of CPU Execution Time

Maintains a currentTime variable to simulate CPU clock time.

Displays process completion order and finish time.

10. Menu-less Scheduling Simulation

Automatically schedules processes without user intervention after input.

Focuses on algorithmic behavior rather than UI.
*/
