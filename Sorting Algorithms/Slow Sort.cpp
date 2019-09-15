#include <iostream>
using namespace std;

void SlowSort(int a[], int i, int j){
  if (i >= j)
    return;
  int m = i + (j - i) / 2; //midpoint, implemented this way to avoid overflow
  int temp;
  SlowSort(a, i, m);
  SlowSort(a, m + 1, j);
  if (a[j] < a[m]){
    temp = a[j]; //swapping a[j] & a[m]
    a[j] = a[m];
    a[m] = temp;
  }
  SlowSort(a, i, j - 1);
}

int main(){
  int size;
  cout << "\nEnter the number of elements : ";
  cin >> size;
  int arr[size];
  cout << "\nEnter the unsorted elements : ";
  for (int i = 0; i < size; ++i){
    cout << "\n";
    cin >> arr[i];
  }
  SlowSort(arr, 0, size);
  cout << "Sorted array\n";
  for (int i = 0; i < size; ++i){
    cout << arr[i] << " ";
  }
  return 0;
}
