#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, bool> memo;

string passwordCracker(const vector<string> passwords, string loginAttempt)
{
    vector<string> finalPassword;

    helperFn(passwords, loginAttempt, finalPassword);
    if (finalPassword.size() == 0)
    {
        return "WRONG PASSWORD";
    }
    string ans = "";
    for (auto &itr : finalPassword)
    {
        ans += itr + " ";
    }
    return ans;
}

bool helperFn(const vector<string> passwords, string loginAttempt, vector<string> &finalPassword)
{

    if (loginAttempt.empty())
    {
        return true;
    }
    if (memo.find(loginAttempt) != memo.end())
    {
        return false;
    }
    int n = passwords.size();

    for (int i = 0; i < n; i++)
    {
        if (passwords[i].size() < loginAttempt.size() && loginAttempt.find(passwords[i], 0) == 0)
        {
            finalPassword.push_back(passwords[i]);
            memo[passwords[i]] = true;

            if (helperFn(passwords, loginAttempt.substr(passwords[i].size()), finalPassword))
            {
                return true;
            }
            finalPassword.pop_back();
        }
    }
    return false;
}
int main()
{
    cout << "Hello World" << endl;
}