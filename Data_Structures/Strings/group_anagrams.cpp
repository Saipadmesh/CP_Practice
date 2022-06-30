#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// Given an array of strings strs, group the anagrams together.
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map1;
    // sort each string and use that as keys for the map, to group every string
    for (auto st : strs)
    {
        string s = st;
        sort(st.begin(), st.end());
        map1[st].push_back(s);
    }

    for (auto m : map1)
    {
        ans.push_back(m.second);
    }

    return ans;
}