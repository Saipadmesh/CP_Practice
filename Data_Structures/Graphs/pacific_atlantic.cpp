#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<bool>> po(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> ao = po;
    vector<vector<int>> ans;

    for (int i = 0; i < heights[0].size(); ++i)
    {
        dfs(heights, po, 0, i);
        dfs(heights, ao, heights.size() - 1, i);
    }
    for (int i = 0; i < heights.size(); ++i)
    {
        dfs(heights, po, i, 0);
        dfs(heights, ao, i, heights[0].size() - 1);
    }

    for (int i = 0; i < heights.size(); ++i)
    {
        for (int j = 0; j < heights[0].size(); ++j)
        {
            if (po[i][j] && ao[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}

void dfs(vector<vector<int>> &heights, vector<vector<bool>> &set, int r, int c)
{
    set[r][c] = true;

    int height = heights[r][c];
    if (r > 0 && heights[r - 1][c] >= height && !set[r - 1][c])
        dfs(heights, set, r - 1, c);
    if (c > 0 && heights[r][c - 1] >= height && !set[r][c - 1])
        dfs(heights, set, r, c - 1);
    if (r < heights.size() - 1 && heights[r + 1][c] >= height && !set[r + 1][c])
        dfs(heights, set, r + 1, c);
    if (c < heights[0].size() - 1 && heights[r][c + 1] >= height && !set[r][c + 1])
        dfs(heights, set, r, c + 1);
}