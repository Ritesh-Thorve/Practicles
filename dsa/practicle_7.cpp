//7] Implement tree traversal techniques to display hierarchical employee structures in a company.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Employee {
string name;
vector<Employee*> subordinates;
Employee(string n) : name(n) {}
};
// Pre-order traversal: Print manager before subordinates
void preorder(Employee* root, int level=0) {
if (!root) return;
for(int i=0; i<level; i++) cout << " "; // indentation by level
cout << root->name << endl;
for (auto sub : root->subordinates) {
preorder(sub, level + 1);
}
}
// Level-order traversal: Print employees level-wise
void levelOrder(Employee* root) {
if (!root) return;
queue<Employee*> q;
q.push(root);
while (!q.empty()) {
int n = q.size();
for (int i=0; i<n; i++) {

Employee* curr = q.front();
q.pop();
cout << curr->name << " ";
for (auto sub : curr->subordinates)
q.push(sub);
}
cout << endl;
}
}

/*
Theory:
Explanation of the Program

This program represents an organizational hierarchy using a tree data structure and demonstrates two important tree traversal techniques: pre-order traversal and level-order traversal.

1. Tree Data Structure (Hierarchical Representation)

Each employee is represented as a node in a tree.

The Employee structure contains:

name: employee’s name (data)

subordinates: a dynamic list (vector) of pointers to child nodes

This forms a general tree, where a node can have multiple children (subordinates).

2. Use of Dynamic Data Structures

vector<Employee*> is used to store subordinates.

Allows a manager to have any number of subordinates dynamically.

Demonstrates flexible, non-fixed-size hierarchical storage.

3. Pre-order Tree Traversal

Order: Root → Children

The manager (root) is printed before all subordinates.

Uses recursion to traverse the hierarchy.

Indentation based on level visually represents the reporting structure.

Application:
Displaying organizational charts where higher authorities appear first.

4. Level-order Tree Traversal (Breadth-First Traversal)

Traverses the tree level by level from top to bottom.

Uses a queue to manage nodes at each level.

Prints all employees at the same hierarchy level on one line.

Application:
Viewing organization structure department-wise or level-wise.

5. Use of Queue

Queue follows FIFO (First In First Out) principle.

Essential for level-order traversal to process nodes in correct order.

6. Recursion

Pre-order traversal uses recursion to explore each subtree.

Simplifies tree traversal logic.

7. Indentation and Levels

The level parameter helps format output.

Shows depth of each employee in the hierarchy.
*/
