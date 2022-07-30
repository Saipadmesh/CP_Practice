#include <vector>
#include <iostream>

using namespace std;
// Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

int rob(vector<int> &nums)
{
    int n = nums.size();
    int maxAmount[n];
    maxAmount[0] = nums[0];
    if (n > 1)
    {
        maxAmount[1] = max(maxAmount[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            maxAmount[i] = max(maxAmount[i - 1], nums[i] + maxAmount[i - 2]);
        }
    }

    return maxAmount[n - 1];
}

int main()
{
    vector<int> nums = {2, 1};
    cout << rob(nums) << endl;
}