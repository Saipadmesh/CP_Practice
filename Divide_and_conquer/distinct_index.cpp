#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
  if (arr[begin] == begin) {
    return vector<int>{1, middle};
  }
  vector<int> a = divide(arr, begin, middle - 1);
  vector<int> b = divide(arr, middle + 1, end);
  if (a[0] == 1) {
    return a;
  } else if (b[0] == 1) {
    return b;
  } else if (a[0] == 1 && b[0] == 1) {
    return (a[1] < b[1]) ? a : b;
  } else {
    return vector<int>{0, -1};
  }

  //   else if (arr[middle] > middle) {

  //     return divide(arr, middle + 1, end);
  //   }
  //   else {
  //     return divide(arr, begin, middle - 1);
  //   }
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
    // printArray(nums);
    vector<int> ans = divide(nums, 0, j - 1);
    if (ans[0] == 0) {
      cout << "False " << ans[1] << endl;
    } else {
      cout << "True " << ans[1] << endl;
    }
  }
  return 0;
}