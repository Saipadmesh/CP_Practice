#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
    // DFS and mark nodes as visited
    int m = grid.size();
    int n = grid[0].size();
    bool inBounds_i = (i >= 0 && i < m);
    bool inBounds_j = (j >= 0 && j < n);
    if (!inBounds_i || !inBounds_j || grid[i][j] == '0')
    {
        return;
    }

    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    // if a piece of land is encountered, dfs to find the pieces attached, and increase the count by 1
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                // cout<<"DFS called at "<<i<<","<<j<<endl;
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}