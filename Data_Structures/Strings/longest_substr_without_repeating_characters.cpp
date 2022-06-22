#include <unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> um;
    int slow = 0, fast = 0, maxSize = 0;
    while (fast < s.size())
    {
        um[s[fast]]++;
        while (um[s[fast]] > 1)
        {
            um[s[slow]]--;
            slow++;
        }

        maxSize = max(maxSize, fast - slow + 1);
        fast++;
    }
    return maxSize;
}