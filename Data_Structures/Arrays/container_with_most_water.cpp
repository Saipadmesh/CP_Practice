#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int> &height)
{
    int start = 0, end = height.size() - 1;
    int currMax = 0;
    while (start != end)
    {
        int minL = min(height[start], height[end]);
        int area = (end - start) * minL;
        if (currMax < area)
        {
            currMax = area;
        }

        if (minL == height[start])
        {
            start++;
        }
        else if (minL == height[end])
        {
            end--;
        }
    }
    return currMax;
}

// 1,8,6,2,5,4,8,3,7
int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(heights) << endl;
}