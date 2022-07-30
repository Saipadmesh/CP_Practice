#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minSwaps(vector<string> arr, string toGroup)
{
    int char_count = 0; // count number of occurrences of the required item.
    for (auto item : arr)
    {
        if (item == toGroup)
        {
            char_count++;
        }
    }
    int window_size = char_count;
    int i = 0, j = 0;                  // start and end of the window
    int curr_count = 0, max_count = 0; // count number of req item in the window
    while (j < arr.size())
    {
        if (arr[j] == toGroup)
        {
            curr_count++;
        }
        if ((j - i + 1) == window_size)
        {
            max_count = max(max_count, curr_count);
            // the window moves after this step by 1, so if the starting value is required, reduce it from the count
            if (arr[i] == toGroup)
            {
                curr_count--;
            }
            i++;
        }
        j++;
    }
    return window_size - max_count;
}

int main()
{
    vector<string> arr = {"D", "H", "A", "D", "H"};
    string s = "H";
    cout << minSwaps(arr, s);
}