#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int find_max_index(int arr[], int m) {
  int max = INT_MIN;
  int index = -1;
  for (int i = 0; i < m; i++) {
    if (arr[i] > max) {
      max = arr[i];
      index = i;
    }
  }
  // cout << "Starting index (temp) is " << index << " ";
  // cout << "Max (temp) is " << max << endl;
  // vector<int> ans = {index, max};
  return max;
}

int find_path_count(int **next, int start, int end) {
  // cout << "Entered find path count function" << endl;
  if (next[start][end] == -1) {
    return 0;
  }
  int count = 1;
  while (start != end) {
    // cout << start << endl;
    start = next[start][end];
    count++;
  }
  // cout << "Exited find path count function" << endl;
  return count;
}

int **find_start(int **arr, int m, int **next,
                 vector<int> potential_starting_points) {
  int **dp_table = new int *[m];
  for (int i = 0; i < m; i++) {
    dp_table[i] = new int[m];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      dp_table[i][j] = arr[i][j];
    }
  }

  for (int k = 0; k < m; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {

        if ((dp_table[i][k] + dp_table[k][j] > dp_table[i][j]) &&
            (dp_table[i][k] != -1) && (dp_table[k][j] != -1)) {
          dp_table[i][j] = dp_table[i][k] + dp_table[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }

  // print solution
  /*for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      int ans = (dp_table[i][j] < 0) ? 0 : dp_table[i][j];
      cout << ans << " ";
    }
    cout << endl;
  }*/

  return dp_table;
}
void find_path(int **arr, int m, int n, vector<int> potential_starting_points) {
  int **next = new int *[m];
  for (int i = 0; i < m; i++) {
    next[i] = new int[m];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      next[i][j] = (arr[i][j] != 0 && arr[i][j] != -1) ? j : -1;
    }
  }
  /*cout << "Next before function: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      int ans = next[i][j];
      cout << ans << " ";
    }
    cout << endl;
  }
  cout << "\n\n";*/
  int **dp_table = find_start(arr, m, next, potential_starting_points);

  // print next
  /*cout << "\n\n";
  cout << "Next after function: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      int ans = next[i][j];
      cout << ans << " ";
    }
    cout << endl;
  }
  cout << "\n\n";*/

  int total_max = INT_MIN, start = -1;
  /*cout << "Starting points: ";
  for (auto ip = potential_starting_points.begin();
       ip != potential_starting_points.end(); ip++) {
    cout << *ip << ",";
  }
  cout << endl;*/
  for (auto ip = potential_starting_points.begin();
       ip != potential_starting_points.end(); ip++) {
    // cout << *ip << endl;
    int temp_max = find_max_index(dp_table[*ip], m);
    if (total_max < temp_max) {
      total_max = temp_max;
      start = *ip;
    }

    // cout << "total_max " << total_max << endl;
    // start = (total_max < temp_max[1]) ? *(ip - 1) : start;

    // cout << "Starting index: " << start << endl;
  }
  // cout << "Final starting index is " << start << endl;
  int count[m], end = -1;
  bool check = true;
  int neg_count = 0;
  int max_for_count = INT_MIN;
  for (int i = 0; i < m; i++) {
    if (next[start][i] == -1) {
      neg_count++;
      continue;
    }
    count[i] = find_path_count(next, start, i);
    if (count[i] == n) {
      if (dp_table[start][i] > max_for_count) {
        max_for_count = dp_table[start][i];
        end = i;
      }
    }
  }

  int ans = (dp_table[start][end] < 0) ? 0 : dp_table[start][end];
  cout << ans << endl;
  if (next[start][end] == -1 || neg_count == m) {
    return;
  }
  cout << start + 1 << ",";
  while (start != end) {
    start = next[start][end];
    if (start == end) {
      cout << start + 1;
    } else {

      cout << start + 1 << ",";
    }
  }
  cout << endl;
}

int main() {
  int m, n;
  cin >> m >> n;
  int arr[m];
  vector<int> potential_starting_points;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  // create an adjacency matrix with edges between places where the difference
  // in priority is 1
  int **adj_mat = new int *[m];
  for (int i = 0; i < m; i++) {
    adj_mat[i] = new int[m];
    // for checking which indices could be the starting index
    if (arr[i] == 1) {
      potential_starting_points.push_back(i);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i == j) {
        adj_mat[i][j] = 0;
      } else {
        adj_mat[i][j] = (arr[j] - arr[i] == 1) ? abs(i - j) : -1;
      }
    }
  }

  /*cout << "Original array: " << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      int ans = (adj_mat[i][j] == -1) ? 0 : adj_mat[i][j];
      cout << ans << " ";
    }
    cout << endl;
  }
  cout << "\n\n";*/

  find_path(adj_mat, m, n, potential_starting_points);
}