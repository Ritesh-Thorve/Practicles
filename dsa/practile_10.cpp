/*
10] Title: Searching, Sorting and Hashing
    Implement the Bubble Sort algorithm to sort an array of student marks
   Objectives:
1.	Understand the working principle of Bubble Sort through implementation.
2.	Apply the algorithm to sort student performance data.
3.	Analyse algorithm efficiency for small datasets like class marks.
*/

#include <iostream>
#include <algorithm>   // FIX: required for swap()
using namespace std;

void bubbleSort(int marks[], int n) {
    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;   // Optimization flag

        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                swap(marks[j], marks[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;   // Early termination if already sorted
    }
}

int main() {
    int marks[] = {85, 92, 78, 95, 88, 76, 90};
    int n = sizeof(marks) / sizeof(marks[0]);

    cout << "Original student marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    bubbleSort(marks, n);

    cout << "Sorted student marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    return 0;
}




/*
Theory
Theory:
📘 Theory Covered by the Program
1. Sorting Algorithm
•	The program implements Bubble Sort, a simple comparison-based sorting algorithm.
•	It repeatedly compares adjacent elements and swaps them if they are in the wrong order.
________________________________________
2. Bubble Sort Working Principle
•	In each pass, the largest element “bubbles up” to the end of the array.
•	After every pass, one element is placed in its correct position.
•	The process continues until the array becomes sorted.
________________________________________
3. Nested Loop Structure
•	Outer loop: Controls the number of passes.
•	Inner loop: Compares adjacent elements and performs swapping.
________________________________________
4. Optimization Using Flag
•	A boolean variable swapped is used.
•	If no swaps occur in a pass, the array is already sorted.
•	This allows early termination, improving efficiency.
________________________________________
5. In-Place Sorting
•	Bubble Sort does not require extra memory.
•	Sorting is done within the original array.
________________________________________
6. Application Context
•	The program sorts student marks in ascending order.
•	Useful for:
o	Result processing
o	Ranking systems
o	Simple educational datasets
________________________________________
7. Time Complexity
•	Best Case: O(n) (already sorted, due to optimization)
•	Average Case: O(n²)
•	Worst Case: O(n²)
________________________________________
8. Space Complexity
•	O(1) (constant extra space)

*/
