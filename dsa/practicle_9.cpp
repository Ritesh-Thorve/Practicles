//9] Sort a dataset of e-commerce product prices using quick sort algorithm in C++.

#include <iostream>
#include <algorithm>   // FIX: required for swap()
using namespace std;

// Partition function: Places pivot in correct position
int partition(double prices[], int low, int high) {
    double pivot = prices[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (prices[j] <= pivot) {
            i++;
            swap(prices[i], prices[j]);
        }
    }
    swap(prices[i + 1], prices[high]);
    return i + 1;
}

// Recursive quick sort function
void quickSort(double prices[], int low, int high) {
    if (low < high) {
        int pi = partition(prices, low, high);
        quickSort(prices, low, pi - 1);
        quickSort(prices, pi + 1, high);
    }
}

int main() {
    double productPrices[] = {299.99, 49.99, 1250.00, 89.50, 599.00,
                              19.99, 750.75, 34.99, 1999.99, 275.25};
    int numProducts = 10;

    cout << "Original Product Prices: ";
    for (int i = 0; i < numProducts; i++) {
        cout << productPrices[i] << " ";
    }
    cout << endl;

    quickSort(productPrices, 0, numProducts - 1);

    cout << "Sorted Product Prices (Ascending): ";
    for (int i = 0; i < numProducts; i++) {
        cout << productPrices[i] << " ";
    }
    cout << endl;

    return 0;
}



/*
Theory
📘 Theory Covered by the Program
1. Sorting Algorithm

The program implements Quick Sort, a divide-and-conquer sorting algorithm.

It recursively divides the array into smaller sub-arrays and sorts them.

2. Quick Sort Concept

Quick Sort works in three main steps:

Choose a pivot element

Partition the array around the pivot

Recursively sort the left and right sub-arrays

3. Partition Technique

The last element is chosen as the pivot.

Elements smaller than or equal to the pivot are placed on the left.

Elements greater than the pivot are placed on the right.

After partitioning, the pivot is in its correct sorted position.

4. Recursion

Quick Sort uses recursion to sort sub-arrays.

Each recursive call reduces the problem size.

Base condition stops recursion when the sub-array has one or zero elements.

5. In-Place Sorting

Quick Sort sorts the array in place.

No extra memory is required for another array.

Makes it memory efficient.

6. Application Context

The program sorts product prices in ascending order.

Useful in real-world applications like:

E-commerce price sorting

Inventory systems

Financial data analysis

7. Time Complexity

Best Case: O(n log n)

Average Case: O(n log n)

Worst Case: O(n²) (when pivot selection is poor)

8. Space Complexity

O(log n) due to recursive call stack.
*/
