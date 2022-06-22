#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> removeDuplicates(vector<int> &nums)
{
  int curr, element = INT_MIN;
  for (auto i = nums.begin(); i != nums.end(); i++)
  {
    curr = *i;
    if (element != curr)
    {
      element = curr;
    }
    else
    {
      nums.erase(i);
      i--;
    }
  }

  return nums;
}
// 2 line solution
vector<int> removeDuplicatesEasy(vector<int> &nums)
{
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  return nums;
}

vector<int> removeDuplicates_atmost_2(vector<int> &nums)
{
  int curr, element = INT_MIN;
  int count = 0;
  for (auto i = nums.begin(); i != nums.end(); i++)
  {
    curr = *i;
    if (element != curr)
    {
      element = curr;
      count = 0;
    }
    else
    {
      count++;
      if (count > 1)
      {
        nums.erase(i);
        i--;
      }
    }
  }

  return nums;
}

int main()
{
  vector<int> nums{1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 6};
  nums = removeDuplicates_atmost_2(nums);
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << ",";
  }
  cout << endl;
  return 0;
}
