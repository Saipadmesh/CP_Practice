// Given an integer array nums, return an array answer such that answer[i] is
// equal to the product of all the elements of nums except nums[i].

// You must write an algorithm that runs in O(n) time and without using the
// division operation.
#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

vector<int> productExceptSelf_M(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans(n);

  int prod = 1;
  ans[0] = prod;
  for (int i = 1; i < n; i++) {
    prod = prod * nums[i - 1];
    ans[i] = prod;
  }

  prod = 1;
  for (int i = n - 2; i >= 0; i--) {
    prod = prod * nums[i + 1];
    ans[i] *= prod;
  }

  return ans;
}

// Use two arrays. First element in left arr is 1 and last element in right arr
// is 1. Each index in left array should be the product of elements upto that
// point from the left. Same in right. Multiply left and right array elements.
vector<int> productExceptSelf(vector<int> &nums) {
  vector<int> ans;
  int n = nums.size();
  int left[n];
  int right[n];
  left[0] = 1;
  int prod = 1;
  for (int i = 1; i < n; i++) {
    prod = prod * nums[i - 1];
    left[i] = prod;
  }
  right[n - 1] = 1;
  prod = 1;
  for (int i = n - 2; i >= 0; i--) {
    prod = prod * nums[i + 1];
    right[i] = prod;
  }
  for (int i = 0; i < n; i++) {
    ans.push_back(left[i] * right[i]);
  }
  return ans;
}

void print_Vector(vector<int> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    int a = *ip;
    cout << a << ",";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {2, 4, 6};
  vector<int> ans = productExceptSelf_M(arr);
  print_Vector(ans);
}