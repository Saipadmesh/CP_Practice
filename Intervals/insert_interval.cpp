#include <vector>
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
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int start = newInterval[0];
    int end = newInterval[1];
    vector<vector<int>> ans;
    int i = 0;
    int n = intervals.size();
    while (i < n && intervals[i][1] < start)
    {
        ans.push_back(intervals[i++]);
    }
    if (i < n)
    {

        start = min(start, intervals[i][0]);
    }
    while (i < n && intervals[i][0] <= end)
    {
        end = max(end, intervals[i][1]);
        i++;
    }
    ans.push_back({start, end});
    while (i < n)
    {
        ans.push_back(intervals[i++]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> ans = insert(intervals, newInterval);
    printMatrix(ans);
}