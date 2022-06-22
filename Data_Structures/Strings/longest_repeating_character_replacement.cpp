#include <unordered_map>
using namespace std;

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

int characterReplacement(string s, int k)
{
    unordered_map<char, int> map1;
    // maxCount is the count of the character with highest frequency. maxSize is the size of the maximum window.
    int slow = 0, fast = 0, maxCount = 0, maxSize = 0;
    while (fast < s.size())
    {
        int curr_char_count = ++map1[s[fast]];
        // Update maxCount
        maxCount = max(curr_char_count, maxCount);
        // fast-slow-maxCount+1 returns the number of characters that needs to be changed.
        while (fast - slow - maxCount + 1 > k)
        {
            // move the window to the left
            map1[s[slow]]--;
            slow++;
        }
        maxSize = max(maxSize, fast - slow + 1);
        fast++;
    }
    return maxSize;
}