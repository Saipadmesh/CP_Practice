#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> dp(n - 1, 0);
    if (n == 1)
    {
        return true;
    }
    dp[n - 2] = (nums[n - 2] < 1) ? 0 : 1;
    // cout << dp[n - 2] << endl;
    for (int i = n - 3; i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            dp[i] = 0;
        }
        else
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if ((i + j == n - 1) || dp[i + j])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    return dp[0];
}