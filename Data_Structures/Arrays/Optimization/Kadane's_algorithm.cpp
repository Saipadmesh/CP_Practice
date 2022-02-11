#include <climits>
#include <iostream>

using namespace std;
// find the maximum sum of a contiguous subarray in an array containing negative
// and positive numbers, in O(n) time complexity.
int maxSum(int numbers[], int size) {
  int max_till_now = INT_MIN;
  int max_ending_here = 0;
  for (int i = 0; i < size; i++) {
    max_ending_here += numbers[i];
    // if the maximum till current index is greater than total max, change total
    // max.
    if (max_till_now < max_ending_here) {
      max_till_now = max_ending_here;
    }
    // if the max ending at an index is less than 0, it is changed to 0 because
    // we might as well not include the previous elements and have the maximum
    // sum as 0.
    if (max_ending_here < 0) {
      max_ending_here = 0;
    }
  }
  // return global max.
  return max_till_now;
}

int main() {
  int num[] = {1, 2, -3, 4, 9, -8, 5};
  int length = sizeof(num) / sizeof(num[0]);
  int sum = maxSum(num, length);
  cout << sum;
}
