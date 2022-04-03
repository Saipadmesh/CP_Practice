#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s)
{
    string ans = "";
    for (auto &character : s)
    {
        if (ans == "" || character != *ans.rbegin())
        {
            ans.push_back(character);
            continue;
        }
        ans.pop_back();
    }
    return (ans == "") ? "Empty String" : ans;
}

int main()
{

    string s;
    getline(cin, s);
    string result = superReducedString(s);
    cout << result << "\n";
    return 0;
}
