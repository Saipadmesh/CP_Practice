#include <iostream>
#include <string>
using namespace std;

void print_dp(int n, int **DP)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << DP[i][j] << " ";
        }
        cout << "\n";
    }
}

string lps(string s)
{
    int n = s.length();
    int maxLength = 1, start = 0;
    int **DP = new int *[n];
    for (int i = 0; i < n; i++)
    {
        DP[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        DP[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s.at(i) == s.at(i + 1))
        {
            DP[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; k++)
    {

        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;

            // cout << strcmp(s.at(i), s.at(j));
            // cout << s.at(i) << " " << s.at(j) << "\n";
            // cout << (s.at(i) == s.at(j)) << endl;
            // cout << i << " " << j << "\n";
            // cout << DP[i + 1][j] << " " << DP[i][j - 1] << "\n\n";
            if (s.at(i) == s.at(j) && DP[i + 1][j - 1])
            {
                DP[i][j] = 1;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    // print_dp(n, DP);
    return s.substr(start, maxLength);
}

int main()
{
    string s = "aacabdkacaa";
    cout << lps(s) << "\n";
}