#include <bits/stdc++.h>
using namespace std;
class Trie
{
public:
    bool isEnd;
    Trie *children[26];
    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }

    void insert(string word)
    {
        if (word == "")
        {
            return;
        }
        Trie *curr = this;
        for (auto itr : word)
        {
            int k = itr - 'a';
            if (!curr->children[k])
            {
                curr->children[k] = new Trie();
            }
            curr = curr->children[k];
        }
        curr->isEnd = true;
    }
};

bool isInList(vector<string> ansList, string ans)
{
    for (auto word : ansList)
    {
        if (word == ans)
        {
            return true;
        }
    }
    return false;
}

bool inBounds(int x, int y, int m, int n)
{
    return (x >= 0 && y >= 0 && x < m && y < n);
}
void dfs(vector<vector<char>> &matrix, int i, int j, Trie *curr, vector<string> &ansList, string ans, char curCh, vector<vector<bool>> &visited)
{

    // cout<<ans<<"\n";
    // curr->printTrie();
    int index = curCh - 'a';
    curr = curr->children[index];
    // for(auto child:curr->children){
    //     cout<<child.first<<"\n";
    // }

    if (curr->isEnd && !isInList(ansList, ans))
    {
        ansList.push_back(ans);
        curr->isEnd = false;
    }
    int m = matrix.size(), n = matrix[0].size();

    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};

    for (int k = 0; k < 4; k++)
    {
        // cout<<inBounds(i+x[k],j+y[k],m,n)<<" ";
        // cout<< visited[i+x[k]][j+y[k]]<<" "<<i+x[k]<<" "<<j+y[k]<<"\n";
        if (inBounds(i + x[k], j + y[k], m, n) && !visited[i + x[k]][j + y[k]])
        {
            curCh = matrix[i + x[k]][j + y[k]];

            index = curCh - 'a';

            if (curr->children[index])
            {
                ans += curCh;
                // cout<<ans<<"\n";
                visited[i + x[k]][j + y[k]] = 1;
                dfs(matrix, i + x[k], j + y[k], curr, ansList, ans, curCh, visited);
                ans.pop_back();
                visited[i + x[k]][j + y[k]] = 0;
            }
        }
    }
    // cout<<"\n";
}
vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    Trie *dictionary = new Trie();
    for (auto word : words)
    {
        dictionary->insert(word);
    }
    // dictionary->printTrie();
    vector<string> ansList;
    string ans;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dictionary->children[board[i][j] - 'a'])
            {
                ans = board[i][j];
                char curCh = board[i][j];
                vector<vector<bool>> visited(m, vector<bool>(n, 0));
                visited[i][j] = 1;
                dfs(board, i, j, dictionary, ansList, ans, curCh, visited);
            }
        }
    }
    return ansList;
}