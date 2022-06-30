// Given heights of n towers and a value k. We need to either increase or
// decrease the height of every tower by k (only once) where k > 0. The task is
// to minimize the difference between the heights of the longest and the
// shortest tower after modifications and output this difference.

#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int minimizeHeight(int arr[], int n, int k)
{
  // Sort the array
  sort(arr, arr + n);
  // Initially, the maximum difference in heights would be maxElement-minElement
  int ans = arr[n - 1] - arr[0];
  // These variables store the initial min and max values in the array. To
  // reduce the height difference, it is clear that we need to increase the
  // least element in the array by k and reduce the highest element in the array
  // by k.
  int minimum = arr[0] + k, maximum = arr[n - 1] - k;
  int min1, max1;
  // loop from first element of the array to the second last element
  for (int i = 0; i < n - 1; i++)
  {
    // Check whether a[0]+k>a[i+1]-k for i from 0..n-2. If it is, then a[i+1]-k
    // is the current minimum element.
    min1 = min(minimum, arr[i + 1] - k);
    // Check whether a[n-1]-k<a[i]+k for i from 0..n-2. If it is, then a[i]+k is
    // the current maximum element.
    max1 = max(maximum, arr[i] + k);
    // If the current min is lesser than 0, the difference in max height
    // increases, so we don't consider that
    if (min1 < 0)
    {
      continue;
    }
    // Change the previous max height value based on the difference between
    // currMax and currMin.
    ans = min(max1 - min1, ans);
  }
  return ans;
}

int main()
{
  int num[] = {3, 9, 12, 16, 20};
  int k = 3;
  int length = sizeof(num) / sizeof(num[0]);
  int sum = minimizeHeight(num, length, k);
  cout << sum << endl;
}
