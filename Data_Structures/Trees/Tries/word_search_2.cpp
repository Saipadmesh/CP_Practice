// A trie (pronounced as "try") or prefix tree is a tree data structure used to
// efficiently store and retrieve keys in a dataset of strings. There are
// various applications of this data structure, such as autocomplete and
// spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie
// (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously
// inserted string word that has the prefix prefix, and false otherwise.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
    // Implemented using hash table

public:
    bool isEnd;
    map<char, Trie> children;
    string word;
    Trie()
    {
        isEnd = false;
        children = {};
        word = "";
    }

    void insert(string word)
    {
        if (word == "")
        {
            return;
        }
        Trie *currNode = this;
        for (auto itr : word)
        {
            string newWord = currNode->word + itr;
            // cout << "new word: " << newWord << endl;
            if (currNode->children.find(itr) == currNode->children.end())
            {
                currNode->children[itr] = Trie();
                currNode->children[itr].word = newWord;
            }
            // cout << currNode->word << "\n";
            currNode = &currNode->children[itr];
        }
        currNode->isEnd = true;
    }

    bool search(string word)
    {
        if (word == "")
        {
            return false;
        }
        Trie *currNode = this;
        for (auto &itr : word)
        {

            if (currNode->children.find(itr) == currNode->children.end())
            {
                return false;
            }
            currNode = &currNode->children[itr];
        }
        if (currNode->isEnd == true)
        {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        if (prefix == "")
        {
            return false;
        }
        Trie *currNode = this;
        for (int i = 0; i < prefix.size(); i++)
        {

            if (currNode->children.find(prefix[i]) == currNode->children.end())
            {
                return false;
            }

            currNode = &currNode->children[prefix[i]];
        }
        return true;
    }

    void printTrie() { printTrieRecursive(this); }

private:
    void printTrieRecursive(Trie *root)
    {
        cout << "Map keys: ";
        printMapKeys(this);
        for (auto &node : root->children)
        {
            printTrieRecursive(&node.second);
        }
    }
    void printMapKeys(Trie *currNode)
    {
        for (auto &itr : currNode->children)
        {
            cout << itr.first << " ";
        }
        cout << endl;
    }
};

void search_Trie(vector<vector<char>> board, int i, int j, Trie *root, vector<string> &ans)
{
    char letter = board[i][j];
    cout << "letter: " << letter << "\n";
    if (letter == '.')
    {
        // cout << "visited " << letter << "\n";
        return;
    }
    if (root->children.find(letter) == root->children.end())
    {
        // cout << "not found: " << letter << "\n";
        return;
    }
    // root->printTrie();

    Trie *child = &root->children[letter];
    // child->printTrie();

    if (child->isEnd && find(ans.begin(), ans.end(), child->word) == ans.end())
    {
        ans.push_back(child->word);
        return;
    }
    board[i][j] = '.';

    // cout << "current word: " << child->word << "\n";
    if (i > 0)
    {
        search_Trie(board, i - 1, j, child, ans);
    }
    if (i < board.size() - 1)
    {
        search_Trie(board, i + 1, j, child, ans);
    }
    if (j > 0)
    {
        search_Trie(board, i, j - 1, child, ans);
    }
    if (j < board[0].size() - 1)
    {
        search_Trie(board, i, j + 1, child, ans);
    }
    board[i][j] = letter;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    Trie *root = new Trie();
    vector<string> ans;
    int m = board.size();
    int n = board[0].size();

    for (auto word : words)
    {
        root->insert(word);
    }
    // cout << (root->children['a'].children.find('b') == root->children['a'].children.end()) << endl;
    // cout << "Trie: \n";
    // cout << "\n";
    string word = "";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            search_Trie(board, i, j, root, ans);
        }
    }

    return ans;
}

int main()
{
    vector<vector<char>> map = {{'o', 'a', 'b', 'n'}, {'o', 't', 'a', 'e'}, {'a', 'h', 'k', 'r'}, {'a', 'f', 'l', 'v'}};
    vector<string> words = {"oa", "oaa"};
    vector<string> ans = findWords(map, words);
    cout << "Answer: " << endl;
    for (auto word : ans)
    {
        cout << word << "\n";
    }
}