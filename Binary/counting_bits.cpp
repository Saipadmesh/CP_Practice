#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    int curr = 0;
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        ans.push_back(curr);
    }
}