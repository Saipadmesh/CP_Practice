#include <unordered_map>
#include <climits>
using namespace std;
string minWindow(string s, string t)
{
    // edge case
    if (t.size() == 0)
    {
        return "";
    }
    // char_counts for checking unique char counts in string t, and window_count for the sliding window
    unordered_map<char, int> char_counts, window_count;
    for (auto l : t)
    {
        // fill char_counts
        char_counts[l]++;
    }
    // These two variables used to check if a proper window with all required characters is achieved.
    int need = char_counts.size(), have = 0;
    // Used to get the minimum window
    int minSize = INT_MAX, min_l = -1;
    int window_start = 0;
    for (int window_end = 0; window_end < s.size(); window_end++)
    {
        char c = s[window_end];
        // Update count
        window_count[c]++;
        // If the values match, we have required elements to increase unique count by 1.
        if (char_counts.find(c) != char_counts.end() && window_count[c] == char_counts[c])
        {
            have++;
        }
        // If have == need, we need to find a new window by popping elements from the left
        while (have == need)
        {
            // Update the min window size
            int windowSize = window_end - window_start + 1;
            if (minSize > windowSize)
            {
                minSize = windowSize;
                min_l = window_start;
            }

            // Remove character from left
            char c1 = s[window_start];
            // Reduce the value in window_count because we are not considering it
            window_count[c1]--;
            // If the value is less in window than in char_counts, we dont have the number of unique characters needed, so we reduce
            if (char_counts.find(c1) != char_counts.end() && window_count[c1] < char_counts[c1])
            {
                have--;
            }
            // Move the left pointer
            window_start++;
        }
    }
    return (minSize == INT_MAX) ? "" : s.substr(min_l, minSize);
}