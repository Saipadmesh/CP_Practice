#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// for comparing in priority queue
struct compare_pq {
  constexpr bool operator()(pair<int, int> const &a,
                            pair<int, int> const &b) const noexcept {
    return a.second > b.second;
  }
};

void print_array(bool arr[], int n) {
  cout << "Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}

void print_mst(vector<pair<int, int>> mst) {
  // cout << "Printing stage" << endl;
  for (auto it = mst.begin(); it < mst.end(); it++) {

    cout << it->first << " - " << it->second << endl;
  }
}

// recursive function
void make_mst(
    int **graph, int n,
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pq> &pq,
    vector<pair<int, int>> &mst, bool visited[], int keys[], int prev_index) {

  // cout << "Recursion stage" << endl;

  if (pq.empty()) {
    return;
  }
  int curr_index = pq.top().first;
  if (visited[curr_index] == true) {
    return;
  }
  if (prev_index != -1) {
    mst.push_back(make_pair(prev_index, curr_index));
  }
  pq.pop();                   // remove the element with least weight
  visited[curr_index] = true; // mark as visited
  // print_array(visited, n);
  for (int j = 0; j < n; j++) {
    if (j == curr_index || graph[curr_index][j] <= 0) {
      continue;
    }

    if (visited[j] == false && keys[j] > graph[curr_index][j]) {

      keys[j] = graph[curr_index][j];
      pq.push(make_pair(j, graph[curr_index][j]));
    }
  }
  // print_mst(mst);

  make_mst(graph, n, pq, mst, visited, keys, curr_index);
}

void prim(int **graph, int n, int start_index) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pq> pq;
  if (start_index >= n) {
    return;
  }
  pq.push(make_pair(start_index, 0));
  int keys[n];
  fill_n(keys, n, INT_MAX);
  keys[start_index] = 0;
  vector<pair<int, int>> mst;
  bool visited[n];
  fill_n(visited, n, false);
  // cout << "just before recursion stage" << endl;

  make_mst(graph, n, pq, mst, visited, keys, -1);
  print_mst(mst);
}

int main() {
  int n;
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  prim(arr, n, 0);
}