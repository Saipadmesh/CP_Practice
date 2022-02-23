// Given an m x n matrix, return all elements of the matrix in spiral order.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print_Vector(vector<int> ans) {
  for (auto ip = ans.begin(); ip != ans.end(); ip++) {

    int a = *ip;
    cout << a << ",";
  }
  cout << endl;
}

void printMatrix(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  if (m == 0) {
    return;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << ",";
    }
    cout << endl;
  }
}
// Maintain a total and count variable. Maintain variables for starting and
// ending rows and cols. While total<count, print first row, last column, last
// row and first column, and reduce the size of the considered matrix.
vector<int> spiral(vector<vector<int>> matrix) {
  vector<int> ans;
  int m = matrix.size(), n = matrix[0].size();
  int startRow = 0, endRow = m - 1, startCol = 0, endCol = n - 1;
  int total = m * n, count = 0;

  while (count < total) {
    // In every for loop, include count<total condition as well because there is
    // chance that an element may be printed twice.
    for (int i = startCol; count < total && i <= endCol; i++) {
      ans.push_back(matrix[startRow][i]);
      count++;
    }
    startRow++;
    for (int i = startRow; count < total && i <= endRow; i++) {
      ans.push_back(matrix[i][endCol]);
      count++;
    }
    endCol--;
    for (int i = endCol; count < total && i >= startCol; i--) {
      ans.push_back(matrix[endRow][i]);
      count++;
    }
    endRow--;
    for (int i = endRow; count < total && i >= startRow; i--) {
      ans.push_back(matrix[i][startCol]);
      count++;
    }
    startCol++;
  }

  return ans;
}

int main() {
  vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> ans = spiral(mat);
  print_Vector(ans);
}