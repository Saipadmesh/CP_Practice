#include <unordered_map>
using namespace std;
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
bool isAnagram(string s, string t)
{
    // Use a map to get counts
    unordered_map<char, int> map1;
    for (auto letter : s)
    {
        map1[letter]++;
    }
    // check if count is same in the other string
    for (auto letter : t)
    {
        if (map1.find(letter) == map1.end() || map1[letter] == 0)
        {
            return false;
        }
        map1[letter]--;
    }
    for (auto m : map1)
    {
        if (m.second != 0)
        {
            return false;
        }
    }
    return true;
}