#include <iostream>
#include <vector>
using namespace std;
// Find minimum number of swaps to sort binary array. You can only swap adjacent elements

// Number of swaps = number of 0s to the right side of a 1.

int minSwaps(vector<int> arr)
{
    int count = 0, num_unplaced_zeros = 0;
    int n = arr.size();
    // Start from reverse
    for (int i = n - 1; i >= 0; i--)
    {
        // for every 1, count the number of zeros to its right
        if (arr[i] == 0)
        {
            num_unplaced_zeros++;
        }
        else
        {
            count += num_unplaced_zeros;
        }
    }
    return count;
}
