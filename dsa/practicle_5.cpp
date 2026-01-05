//5] Use the stack ADT to check whether parentheses in an arithmetic expression are balanced.

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



/*
Theory:
Theory Covered by the Program: Balanced Parentheses Using Stack

This program demonstrates how a stack data structure is used to check whether an expression has balanced parentheses. The following key theoretical concepts are covered:

1. Stack Data Structure

A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

Elements are added using push and removed using pop operations.

The program uses the C++ STL stack to store opening brackets.

2. Balanced Parentheses Problem

An expression is said to be balanced if:

Every opening bracket has a corresponding closing bracket.

Brackets are closed in the correct order.

The program checks balance for three types of brackets:

(), {}, []

3. Stack-Based Validation Technique

Opening brackets are pushed onto the stack.

When a closing bracket is encountered:

The stack is checked for emptiness.

The top element is compared with the closing bracket.

If they match, the opening bracket is popped.

If they do not match or the stack is empty, the expression is unbalanced.

4. Matching Logic

A helper function is used to verify correct pairing of brackets.

Ensures type safety between opening and closing symbols.

5. Expression Traversal

The expression is scanned character by character.

Demonstrates sequential traversal of a string.

6. Error Detection

Detects:

Extra closing brackets
Mismatched bracket types

Unclosed opening brackets

Ensures correctness of syntactic structure.

7. Use of STL (Standard Template Library)

Utilizes stack<char> from STL.

Reduces complexity and improves code reliability.

8. Algorithm Efficiency

Time Complexity: O(n), where n is the length of the expression.

Space Complexity: O(n) in the worst case due to stack usage.
*/
