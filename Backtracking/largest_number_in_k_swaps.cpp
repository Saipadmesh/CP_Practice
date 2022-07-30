#include <string>
using namespace std;
bool isCandidate(string str, int i, char maxChar)
{
    return (str[i] == maxChar);
}

bool isValidState(int i, int n, int k)
{
    // if you reach end of string or if k is 0, a valid state has been reached
    return (i == n || k == 0);
}

void swapPlaces(string &str, int i, int j)
{
    // swap characters
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void search(string &str, int n, string &solution, int k, int curr)
{
    // is valid state
    solution = max(solution, str);
    if (isValidState(curr, n, k))
    {
        return;
    }
    // instead of checking all possible combinations, find the max value, and call the recursive function for every time it repeats
    char maxChar = str[curr];
    for (int i = curr + 1; i < n; i++)
    {
        maxChar = max(maxChar, str[i]);
    }
    if (maxChar > str[curr])
    {
        // if the max is not at the index, try the swap every time max occurs
        for (int i = curr + 1; i < n; i++)
        {
            if (isCandidate(str, i, maxChar))
            {
                swapPlaces(str, i, curr);
                search(str, n, solution, k - 1, curr + 1);
                swapPlaces(str, i, curr);
            }
        }
    }
    else
    {
        // if the max is already present in the index, no need to waste a swap, move on to the next index
        search(str, n, solution, k, curr + 1);
    }
}
string findMaximumNum(string str, int k)
{
    // requires backtracking
    string solution = "";
    search(str, str.size(), solution, k, 0);
    return solution;
}