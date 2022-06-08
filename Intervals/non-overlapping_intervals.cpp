#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printMatrix(vector<vector<int>> v)
{
    cout << "[ ";

    for (auto v1 : v)
    {
        cout << "[";
        for (auto v2 : v1)
        {
            cout << v2 << ",";
        }
        cout << "] ";
    }
    cout << "]\n";
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    // printMatrix(intervals);
    vector<int> prev = intervals[0];
    int count = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        // cout << (intervals[i][0] >= intervals[i + 1][0]) << " ";
        // cout << (intervals[i + 1][0] < intervals[i][1]) << "\n";
        if (intervals[i][0] < prev[1])
        {
            count++;
            prev[1] = min(prev[1], intervals[i][1]);
        }
        else
        {
            prev = intervals[i];
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    cout << eraseOverlapIntervals(intervals);
}