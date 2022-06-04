#include <iostream>
using namespace std;

int climb_stairs(int n)
{
    int DP[n];
    DP[0] = 1;
    if (n > 1)
    {
        DP[1] = 2;
        for (int i = 2; i < n; i++)
        {
            DP[i] = DP[i - 1] + DP[i - 2];
        }
    }
    return DP[n - 1];
}