#include <vector>
#include <string>
#include <iostream>
using namespace std;
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    bool dp[n + 1] = {false};
    // memset(dp, false, sizeof(dp));
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        // string curr = s.substr(i,endIndex-i);
        // cout<<curr<<"\n";
        for (auto word : wordDict)
        {
            if (i + word.size() <= n && s.substr(i, word.size()) == word)
            {
                dp[i] = dp[i + word.size()];
            }
            if (dp[i])
            {
                break;
            }
        }
    }
    // for(auto x:dp){
    //     cout<<x<<" ";
    // }

    return dp[0];
}

int main()
{
    cout << "hello";
}