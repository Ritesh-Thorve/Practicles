/*
12] Title: Searching, Sorting and Hashing
    Problem Statement: - Implement the Insertion Sort algorithm to sort student
    names in ascending order
    Objectives:
    • Implement Insertion Sort for string comparison and sorting in C++.
    • Apply the algorithm to student records for lexicographical ordering.
    • Evaluate performance on name datasets typical in educational environments.

*/
#include <iostream>
#include <string>
using namespace std;

void insertionSort(string names[], int n) {
for(int i = 1; i < n; i++) {
string key = names[i];
int j = i - 1;
while(j >= 0 && names[j] > key) {
names[j + 1] = names[j];
j--;
}
names[j + 1] = key;
}
}
int main() {
string names[] = {"Rahul", "Priya", "Amit", "Sneha", "Vikram",
"Deepa"};
int n = sizeof(names) / sizeof(names[0]);
cout << "Original student names: ";
for(int i = 0; i < n; i++) cout << names[i] << " ";
cout << endl;
insertionSort(names, n);
cout << "Sorted student names: ";
for(int i = 0; i < n; i++) cout << names[i] << " ";
cout << endl;
return 0;
}



/*
Theory: Insertion Sort Algorithm

This program demonstrates the Insertion Sort algorithm used to arrange student names (strings) in alphabetical order.

Working Principle

Insertion Sort works in a way similar to arranging playing cards in hand.

The array is divided into:

Sorted part (initially containing the first element)

Unsorted part (remaining elements)

Each element from the unsorted part is picked and placed at its correct position in the sorted part.

Elements larger than the selected element are shifted one position to the right to make space.

Algorithm Characteristics

It is a comparison-based sorting algorithm.

Sorting is done in place, without using extra memory.

Works efficiently when the data is nearly sorted.

Maintains the relative order of equal elements (stable sort).

Time Complexity

Best Case: O(n) (already sorted)

Average Case: O(n²)

Worst Case: O(n²) (reverse order)

Space Complexity

O(1) (constant extra space)

Applications

Suitable for small datasets

Efficient for partially sorted lists

Commonly used in:

Name sorting

Small database records

Online insertion of data
*/
