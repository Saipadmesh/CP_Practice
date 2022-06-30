#include <unordered_map>
using namespace std;
// Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s)
{
    // use the map to get the counts of unique elements
    unordered_map<char, int> um;
    // slow and fast represent the sliding window
    int slow = 0, fast = 0, maxSize = 0;
    while (fast < s.size())
    {
        // increase count
        um[s[fast]]++;
        // If the count is greater than 1, remove elements from the left
        while (um[s[fast]] > 1)
        {
            um[s[slow]]--;
            slow++;
        }
        // update the maxSize of the window if necessary
        maxSize = max(maxSize, fast - slow + 1);
        fast++;
    }
    return maxSize;
}