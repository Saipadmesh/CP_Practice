#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n1;
    int n = n1 = matrix.size();
    vector<int> temp;
    int i = 0;
    while (i < n / 2)
    {
        int tl = matrix[i][i], tr = matrix[i][n - 1 - i], bl[n - i - 1][i], br[n - i - 1][n - i - 1];
        for (int j = i; j < n - i; j++)
        {
        }
        i++;
    }
}