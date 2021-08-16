#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*vector<int> merge(vector<int> &arr, int left, int right, vector<int> prev_max)
{ int max_count = 1; int mid = (left + right) / 2; int max_index = left; for
(int i = left + 1; i <= right; i++) { if (arr[i] == arr[max_index]) {
      max_count++;
    } else {
      max_count--;
    }
    if (max_count == 0) {
      max_index = i;
      max_count = 1;
    }
  }
  vector<int> ans = (max_count > prev_max[1])
                        ? vector<int>{arr[max_index], max_count}
                        : prev_max;
  return ans;
}*/

void printArray(vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

vector<int> divide(vector<int> &arr, int begin, int end) {
  if (begin > end) {
    return vector<int>{0, -1};
  }

  int middle = (end == begin) ? end : (end + begin) / 2;
  // cout << "middle: " << middle << endl;
  if (arr[middle] == middle) {
    return vector<int>{1, middle};
  } else if (arr[middle] > middle) {

    return divide(arr, middle + 1, end);

  } else {
    return divide(arr, begin, middle - 1);
  }
}

int main() {

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<int> nums;

    int num;
    int j = 1;
    while (true) {
      cin >> num;
      nums.push_back(num);

      if (cin.peek() == '\n') {
        break;
      }
      j++;
    }
    printArray(nums);
    vector<int> ans = divide(nums, 0, j - 1);
    if (ans[0] == 0) {
      cout << "False " << ans[1] << endl;
    } else {
      cout << "True " << ans[1] << endl;
    }
  }
  return 0;
}