#include <string>
using namespace std;
// Given a string s, return true if it is a palindrome, or false otherwise.
bool isPalindrome(string s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {

        if (isalnum(s[start]) && isalnum(s[end]))
        {
            if (tolower(s[start]) == tolower(s[end]))
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }

        if (!isalnum(s[start]))
        {
            start++;
        }
        if (!isalnum(s[end]))
        {
            end--;
        }
    }
    return true;
}