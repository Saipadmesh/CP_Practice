#include <iostream>
#include <string>
using namespace std;
// Given a string s, return the longest palindromic substring in s.
string longestPalindrome(string s)
{
    int n = s.length();
    int maxLength = 1, start = 0;
    // DP[i][j] represents whether substring from i to j is a palindrome or not
    int DP[n][n];
    // Substring of length 1 is always a palindrome
    for (int i = 0; i < n; i++)
    {
        DP[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        // If 2 characters are same, it is also a palindrome
        if (s.at(i) == s.at(i + 1))
        {
            DP[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }
    // k represents the length of the palindromic substring we are currently considering
    for (int k = 3; k <= n; k++)
    {
        // i represents the starting index
        for (int i = 0; i < n - k + 1; i++)
        {
            // get the second index using k and i
            int j = i + k - 1;
            // If element at start and end are same, and the substring in between is a palindrome, then the whole substring is also palindrome
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
    return s.substr(start, maxLength);
}

int main()
{
    string s = "aabdba";
    cout << longestPalindrome(s) << "\n";
}