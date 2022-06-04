#include <vector>
#include <iostream>

using namespace std;

vector<int> rotate_array(int d, vector<int> &arr)
{
    int n = arr.size();
    int d1 = d % n;
    if (d1 == 0)
    {
        return arr;
    }
    vector<int> temp;
    for (int i = d1; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = 0; i < d1; i++)
    {
        temp.push_back(arr[i]);
    }
    return temp;
}