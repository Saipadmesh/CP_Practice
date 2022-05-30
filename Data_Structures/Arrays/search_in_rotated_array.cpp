#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Modify binary search. Selection of the next half is dependent on whether target is greater than nums[mid] or not, and whether nums[mid] is greater than nums[0] or not

int recursive_search(vector<int>, int, int, int);

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int currMin = INT_MAX;
    int left = 0, right = n - 1;
    return recursive_search(nums, target, left, right);
}
int recursive_search(vector<int> nums, int target, int start, int end)
{
    int mid = floor((start + end) / 2);

    if (nums[mid] == target)
    {
        return mid;
    }
    if (start >= end)
    {
        return -1;
    }
    if (target > nums[mid])
    {
        if (nums[mid] >= nums[0])
        {
            return recursive_search(nums, target, mid + 1, end);
        }
        else
        {
            if (target >= nums[0])
            {
                return recursive_search(nums, target, start, mid);
            }
            else
            {
                return recursive_search(nums, target, mid + 1, end);
            }
        }
    }
    if (target < nums[mid])
    {
        if (nums[mid] >= nums[0])
        {
            if (target >= nums[0])
            {
                return recursive_search(nums, target, start, mid);
            }
            else
            {
                return recursive_search(nums, target, mid + 1, end);
            }
        }
        else
        {
            return recursive_search(nums, target, start, mid);
        }
    }
}

void printRotations(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int n1 = n;
        cout << "{";
        while (n1--)
        {
            if (j == n)
            {
                j = 0;
            }
            cout << nums[j] << ",";
            j++;
        }
        cout << "}" << endl;
    }
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums = {7, 1, 2, 3, 4, 5, 6};
    // { 3, 4, 5, 6, 7, 1, 2}
    // {2, 3, 4, 5, 6, 7, 1}

    // {1,2,3,4,5}
    // {5,1,2,3,4}
    // {4,5,1,2,3}
    // {3,4,5,1,2}
    // {2,3,4,5,1}

    int target = 0;
    int ans = search(nums, target);
    cout << ans << endl;

    // printRotations(nums);
}