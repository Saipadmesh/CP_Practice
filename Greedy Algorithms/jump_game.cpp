#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return true;
    }
    int end = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + nums[i] >= end)
        {
            end = i;
        }
    }
    return (end == 0);
}