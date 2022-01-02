#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &arr) {
  int size = arr.size();
  int start = 0, end = size - 1;
  while (start <= end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
int main() {
  vector<int> arr;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  reverse(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}