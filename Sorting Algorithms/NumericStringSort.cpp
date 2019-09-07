//This Programme uses a comparator to sort the array in Numerical order instead of Alphanumeric order

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool NumericSort(string a, string b){
  while (a[0] == '0'){
    a.erase(a.begin());
  }
  while (b[0] == '0'){
    b.erase(b.begin());
  }
  int n = a.length();
  int m = b.length();
  if (n == m)
    return a < b;
  return n < m;
}

int main(){
  int n;
  cout << "Enter number of elements to be sorted Numerically\n";
  cin >> n;
  vector<string> v(n);
  cout << "Enter the string of Numbers\n";
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  cout << "Elements sorted normally \n";
  for (int i = 0; i < n; i++){
    cout << v[i] << " ";
  }
  cout << "\n";
  sort(v.begin(), v.end(), NumericSort);
  cout << "Elements sorted Numerically \n";
  for (int i = 0; i < n; i++){
    cout << v[i] << " ";
  }
  return 0;
}
