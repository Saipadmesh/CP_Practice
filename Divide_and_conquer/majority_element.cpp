#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &arr, int left, int right, vector<int> prev_max) {
  int max_count = 1;
  int mid = (left + right) / 2;
  int max_index = left;
  for (int i = left + 1; i <= right; i++) {
    if (arr[i] == arr[max_index]) {
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
}

void printArray(vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

vector<int> divide(vector<int> &arr, int begin, int end) {
  if (begin >= end - 1) {
    return vector<int>{-1, 1};
  }

  int middle = (end + begin) / 2;
  vector<int> a = divide(arr, begin, middle);
  vector<int> b = divide(arr, middle + 1, end);
  printArray(a);
  printArray(b);
  vector<int> max = (a[1] > b[1]) ? a : b;
  max = merge(arr, begin, end, max);
  if (max[0] > middle / 2) {
    return max;
  } else {
    return vector<int>{-1, 1};
  }
}

int main() {

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<int> nums;
    map<int, int> num_map;
    int num;
    int j = 1;
    while (true) {
      cin >> num;
      /*if (num_map.find(num) == num_map.end()) {
        num_map.insert(pair<int, int>(num, 1));
      } else {
        int count = num_map.find(num)->second;
        count++;
        num_map[num] = count;
      }*/

      if (cin.peek() == '\n') {
        break;
      }
      j++;
    }
    /*map<int, int>::iterator it;
    bool not_found = true;
    for (it = num_map.begin(); it != num_map.end(); it++) {
      // cout << it->first << ", " << it->second << endl;
      if (it->second > j / 2) {
        cout << it->first << endl;
        not_found = false;
      }
    }
    if (not_found == true) {

      cout << "-1" << endl;
    }*/
    vector<int> ans = divide(nums, 0, j - 1);
    printArray(ans);
  }
  return 0;
}