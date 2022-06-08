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
vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());
    for (auto interval : intervals)
    {
        if (ans.size() == 0 || ans.back()[1] < interval[0])
        {
            ans.push_back(interval);
        }
        else
        {
            ans.back()[1] = max(interval[1], ans.back()[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}};
    vector<vector<int>> ans = merge(intervals);
    printMatrix(ans);
}