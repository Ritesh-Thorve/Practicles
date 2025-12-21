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