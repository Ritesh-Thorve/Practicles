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