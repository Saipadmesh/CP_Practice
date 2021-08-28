#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> divide(vector<int> &arr, int begin, int end) {
  if (begin > end) {
    return vector<int>{0, -1};
  }

  int middle = (end == begin) ? end : (end + begin) / 2;

  vector<int> a = divide(arr, begin, middle - 1);

  if (a[0] == 1) {
    return a;
  } else if (arr[middle] == middle) {
    return (a[0] == 0) ? vector<int>{1, middle} : a;
  } else {
    vector<int> b = divide(arr, middle + 1, end);
    if (b[0] == 1) {

      return b;
    } else {
      return vector<int>{0, -1};
    }
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

    vector<int> ans = divide(nums, 0, j - 1);
    if (ans[0] == 0) {
      cout << "False " << ans[1] << endl;
    } else {
      cout << "True " << ans[1] << endl;
    }
  }
  return 0;
}