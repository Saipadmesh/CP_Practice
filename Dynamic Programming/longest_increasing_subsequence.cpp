#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

void print_dp(int n, int **DP)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << DP[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_vector(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// Initially length of the longest subsequence at every index is 1. Then, for every element, check the elements before it, and if they are lesser, compare the DP value of the lower index + 1 and the DP value at current index and update the max value.
int lengthOfLIS(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
    {
        return 1;
    }
    vector<int> DP(n, 1);
    int ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        ans = max(DP[i], ans);
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    cout << lengthOfLIS(nums) << "\n";
}