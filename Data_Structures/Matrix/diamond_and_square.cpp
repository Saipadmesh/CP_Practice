#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int print_diamond_sum(vector<vector<int>> arr, int n)
{
    int mid = n / 2;
    int sum = 0;
    for (int i = 0; i <= mid; i++)
    {
        if (i == 0)
        {
            sum += arr[i][mid];
            continue;
        }
        sum += arr[i][mid + i];
        sum += arr[i][mid - i];
    }
    for (int i = mid - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            sum += arr[n - i - 1][mid];
            continue;
        }
        sum += arr[n - 1 - i][mid + i];
        sum += arr[n - i - 1][mid - i];
    }
    return sum;
}

int square_sum(vector<vector<int>> arr, int n)
{
    int minsum = INT_MAX, sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
            minsum = min(minsum, sum);
        }
    }
    return minsum;
}

int main()
{
    vector<vector<int>> arr;
    for (int i = 0; i < 5; i++)
    {
        vector<int> temp = {1, 2, 3, 4, 5};
        arr.push_back(temp);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << print_diamond_sum(arr, arr.size()) << " " << square_sum(arr, arr.size());
}