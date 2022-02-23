#include <iostream>
#include <vector>
using namespace std;

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

// with temp array
void setZeroes(vector<vector<int>> &matrix) {
  int m = matrix.size();
  if (m == 0) {
    return;
  }
  int n = matrix[0].size();
  int tempSize = m + n;
  vector<int> checkZeros(tempSize);
  for (int i = 0; i < tempSize; i++) {
    checkZeros[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        checkZeros[i] = 0;
        checkZeros[j + m] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (checkZeros[i] == 0 || checkZeros[j + m] == 0) {
        matrix[i][j] = 0;
      }
    }
  }
}

// Space optimized solution - Use first row and column as buffer
void setZeroes_S(vector<vector<int>> &matrix) {
  int m = matrix.size();
  if (m == 0) {
    return;
  }
  int n = matrix[0].size();
  bool row, column;
  // find if 0 exists in first row and column
  for (int i = 0; i < m; i++) {
    if (matrix[i][0] == 0) {
      column = true;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (matrix[0][i] == 0) {
      row = true;
      break;
    }
  }
  // Check other rows and columns
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // change the rows and columns to zeros
  for (int i = 1; i < m; i++) {
    if (matrix[i][0] == 0) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int j = 1; j < n; j++) {
    if (matrix[0][j] == 0) {
      for (int i = 0; i < m; i++) {
        matrix[i][j] = 0;
      }
    }
  }

  // change the first row and column
  if (row) {
    for (int j = 0; j < n; j++) {
      matrix[0][j] = 0;
    }
  }

  if (column) {
    for (int j = 0; j < m; j++) {
      matrix[j][0] = 0;
    }
  }
}

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  setZeroes_S(matrix);
  printMatrix(matrix);
}