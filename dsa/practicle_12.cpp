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