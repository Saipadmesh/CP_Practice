#include <iostream>
#include <vector>
using namespace std;
int longestCommonSubsequence(string text1, string text2)
{
    // Fill first row and column with 0s. If characters at some indices i-1 and j-1 match, DP[i][j]=1+DP[i-1][j-1], otherwise it is the max value between DP[i-1][j] and DP[i][j-1]

    int m = text1.size();
    int n = text2.size();
    if (m == 0 || n == 0)
    {
        return 0;
    }
    int DP[m + 1][n + 1];
    DP[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        DP[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        DP[0][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1.at(i - 1) == text2.at(j - 1))
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    return DP[m][n];
}

int main()
{
    cout << longestCommonSubsequence("abcdefgh", "acg") << endl;
}