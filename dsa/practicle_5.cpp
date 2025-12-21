#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
return (open == '(' && close == ')') ||
(open == '{' && close == '}') ||
(open == '[' && close == ']');
}

bool isBalanced(const string &expr) {
stack<char> s;
for (char ch : expr) {
if (ch == '(' || ch == '{' || ch == '[') {
s.push(ch);
} else if (ch == ')' || ch == '}' || ch == ']') {

if (s.empty() || !isMatching(s.top(), ch))
return false;
s.pop();
}
}
return s.empty();
}

int main() {
string input;
cout << "Enter an expression: ";
cin >> input;
if (isBalanced(input))
cout << "The expression is balanced." << endl;
else
cout << "The expression is not balanced." << endl;
return 0;
}