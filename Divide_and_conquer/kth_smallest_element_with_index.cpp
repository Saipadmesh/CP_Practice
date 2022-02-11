#include <iostream>
#include <map>
#include <vector>
using namespace std;

// get a pivot value where the values before pivot are sorted
int get_pivot(vector<int> &nums, int begin, int end) {
  int p_index = begin, pivot = nums[begin];
  for (int i = begin + 1; i <= end; i++) {
    // if a number in the array is less than pivot, push pivot to the right
    if (nums[i] < pivot) {
      nums[p_index] = nums[i];
      nums[i] = nums[p_index + 1];
      nums[p_index + 1] = pivot;
      p_index++;
    }
  }

  return p_index;
}

int quick_sort(vector<int> &nums, int begin, int end, int k) {
  vector<int> ans;
  // default case where element is not found
  if (begin >= end) {
    return nums[begin];
  }
  int pivot = get_pivot(nums, begin, end);
  // count of elements till pivot
  int count = pivot - begin + 1;

  if (count == k) {
    return nums[pivot];
  } else if (k < count) {
    return quick_sort(nums, begin, pivot - 1, k);
  } else {
    return quick_sort(nums, pivot + 1, end, k - count);
  }
}

int main() {

  int N, k;
  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<int> nums;
    map<int, int> index_map;
    int num;
    int j = 0;
    while (true) {
      cin >> num;
      nums.push_back(num);
      index_map.insert(pair<int, int>(num, j));
      if (cin.peek() == '\n') {
        break;
      }
      j++;
    }
    cin >> k;
    int n = nums.size();
    int ans = quick_sort(nums, 0, n - 1, k);
    cout << ans << "," << index_map.find(ans)->second << endl;
  }
}
