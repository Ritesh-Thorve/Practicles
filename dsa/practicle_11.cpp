/* 11
Title: Searching, Sorting and Hashing
Problem Statement: - Implement the Selection Sort algorithm to sort product
prices in a shop inventory
Objectives:
 Master Selection Sort implementation in C++ for real-world inventory
applications.
 Analyse algorithm performance on shop price datasets.
 Demonstrate in-place sorting for memory-efficient price organization.
*/

#include <iostream>
using namespace std;
void selectionSort(int prices[], int n) {
for(int i = 0; i < n-1; i++) {
int min_idx = i;

for(int j = i+1; j < n; j++) {
if(prices[j] < prices[min_idx]) {
min_idx = j;
}
}
swap(prices[i], prices[min_idx]);
}
}
int main() {
int prices[] = {250, 180, 320, 150, 290, 200, 175};
int n = sizeof(prices) / sizeof(prices[0]);
cout << "Original shop prices: ";
for(int i = 0; i < n; i++) cout << prices[i] << " ";
cout << endl;
selectionSort(prices, n);
cout << "Sorted shop prices: ";
for(int i = 0; i < n; i++) cout << prices[i] << " ";
cout << endl;
return 0;
}



/*
Theory:
Theory: Selection Sort Algorithm

This program demonstrates the Selection Sort technique, which is a simple comparison-based sorting algorithm used to arrange elements in ascending order.

Working Principle

Selection Sort divides the array into two parts:

Sorted part (initially empty)

Unsorted part (initially the whole array)

In each pass:

The smallest element is selected from the unsorted part.

This minimum element is swapped with the first element of the unsorted part.

The boundary of the sorted part moves one position to the right.

This process continues until the entire array is sorted.

Algorithm Characteristics

Performs a fixed number of comparisons regardless of input order.

Places exactly one element in its correct position in each pass.

Sorting is done in place, without using extra memory.

Time Complexity

Best Case: O(n²)

Average Case: O(n²)

Worst Case: O(n²)

(Selection sort always scans the remaining elements to find the minimum.)

Space Complexity

O(1) (constant extra space)

Applications

Suitable for small datasets

Useful when memory usage must be minimal

Commonly used for educational purposes to explain sorting concepts

*/
