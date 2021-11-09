#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int pipe_end[100], pipe_receive[100], final_diameter[100];
int ans;

vector<vector<int>> final;
vector<int> a, b, c;
int update(int start) {
  if (pipe_end[start] == 0) {
    return start;
  }
  if (final_diameter[start] < ans) {
    ans = final_diameter[start];
  }
  return update(pipe_end[start]);
}

void pipe_fit(int **arr, int p, int q) {

  for (int i = 0; i < q; i++) {
    int start = arr[i][0];
    int end = arr[i][1];
    int d = arr[i][2];
    pipe_end[start] = end;
    final_diameter[start] = d;
    pipe_receive[end] = start;
  }
  final.clear();
  a.clear();
  b.clear();
  c.clear();
  for (int j = 1; j <= p; j++) {
    if (pipe_receive[j] == 0 && pipe_end[j]) {
      ans = INT_MAX;
      int w = update(j);
      final.push_back(vector<int>{j, w, ans});
      a.push_back(j);
      b.push_back(w);
      c.push_back(ans);
      // cout << "IN if" << endl;
    }
  }

  cout << final.size() << endl;
  for (int j = 0; j < final.size(); j++) {
    cout << final[j][0] << " " << final[j][1] << " " << final[j][2] << endl;
  }
}
int main() {
  int p, q;
  cin >> p >> q;
  int **arr = new int *[q];
  int start, end, weight, x;
  char y;
  for (int i = 0; i < q; i++) {
    arr[i] = new int[3];
  }
  // cout << "Done" << endl;
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> x >> y;
      arr[i][j] = x;
    }
    cin >> x;
    arr[i][2] = x;
  }
  pipe_fit(arr, p, q);

  /*for (int i = 0; i < q; i++) {
    for (int j = 0; j < 3; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }*/
}