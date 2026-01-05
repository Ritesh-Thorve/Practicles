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
void preorder(Employee* root, int level = 0) {
    if (!root) return;

    for (int i = 0; i < level; i++)
        cout << "  ";   // indentation

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
        for (int i = 0; i < n; i++) {
            Employee* curr = q.front();
            q.pop();

            cout << curr->name << " ";

            for (auto sub : curr->subordinates)
                q.push(sub);
        }
        cout << endl;
    }
}

// Function to free memory (post-order deletion)
void deleteTree(Employee* root) {
    if (!root) return;

    for (auto sub : root->subordinates)
        deleteTree(sub);

    delete root;
}

int main() {
    // Create company hierarchy
    Employee* CEO = new Employee("CEO");
    Employee* mgr1 = new Employee("Manager1");
    Employee* mgr2 = new Employee("Manager2");
    Employee* emp1 = new Employee("Employee1");
    Employee* emp2 = new Employee("Employee2");
    Employee* emp3 = new Employee("Employee3");

    CEO->subordinates.push_back(mgr1);
    CEO->subordinates.push_back(mgr2);
    mgr1->subordinates.push_back(emp1);
    mgr1->subordinates.push_back(emp2);
    mgr2->subordinates.push_back(emp3);

    cout << "Pre-order Traversal (Hierarchy display):" << endl;
    preorder(CEO);

    cout << "\nLevel-order Traversal (Layer-wise display):" << endl;
    levelOrder(CEO);

    // Proper memory cleanup
    deleteTree(CEO);

    return 0;
}


/*
Theory Covered by the Program (Employee Hierarchy Using Tree Traversals)

This program demonstrates how a tree data structure can be used to represent an organizational hierarchy and how different tree traversal techniques are applied to process hierarchical data.

1. Tree Data Structure

A tree is a non-linear data structure used to represent hierarchical relationships.

In this program, each Employee acts as a node.

The topmost employee (CEO) is the root node.

Managers and employees are represented as child nodes.

Since an employee can have multiple subordinates, the structure is a general tree.

2. Node Representation

Each node stores:

Employee name (data)

A list of subordinates (children)

A dynamic list (vector) is used to store child nodes, allowing flexibility in the number of subordinates.

3. Pre-order Traversal

Traversal order: Root → Children

The manager is processed before subordinates.

Uses recursion to visit all nodes.

Indentation based on depth visually shows hierarchy.

Use case:
Displaying an organization chart where senior employees appear before juniors.

4. Level-order Traversal (Breadth-First Traversal)

Traverses the tree level by level.

Uses a queue to manage nodes.

All employees at the same level are displayed together.

Use case:
Viewing employees department-wise or level-wise.

5. Use of Recursion

Pre-order traversal is implemented recursively.

Each function call processes a node and then its subtrees.

6. Use of Queue (FIFO Principle)

Level-order traversal relies on the queue data structure.

Queue follows First In First Out (FIFO) principle.

Ensures correct processing order for breadth-first traversal.

7. Dynamic Memory Allocation

Employee nodes are created using new.

Memory is freed using post-order deletion.

Demonstrates safe handling of dynamically allocated memory.

8. Hierarchical Data Modeling

The program models real-world hierarchical systems such as:

Company organization

Management structure

Reporting relationships

Conclusion
*/
