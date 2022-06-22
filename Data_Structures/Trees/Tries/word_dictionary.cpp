

#include <iostream>
#include <map>
#include <string>

using namespace std;

class WordDictionary
{
    // Implemented using hash table
protected:
    bool isEnd;
    map<char, WordDictionary *> children;

private:
    bool helper(string word, int i, WordDictionary *currNode)
    {
        // search is done in a recursive manner

        if (i == word.size())
        {
            // If end of the word is reached in the trie, return true
            if (currNode->isEnd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // If there is a . skip the element and continue searching the children of the current node
        if (word.at(i) == '.')
        {
            for (auto child : currNode->children)
            {
                if (helper(word, i + 1, child.second) == true)
                {
                    return true;
                }
            }
            return false;
        }
        // If there is a match in the current character and one of the child nodes, keep searching
        else if (currNode->children.find(word.at(i)) != currNode->children.end())
        {
            return helper(word, i + 1, currNode->children[word.at(i)]);
        }
        else
        {
            return false;
        }
    }

public:
    WordDictionary()
    {
        isEnd = false;
        children = {};
    }

    void addWord(string word)
    {
        if (word == "")
        {
            return;
        }
        WordDictionary *currNode = this;
        for (auto itr : word)
        {
            if (currNode->children.find(itr) == currNode->children.end())
            {
                currNode->children[itr] = new WordDictionary();
            }
            currNode = currNode->children[itr];
        }
        currNode->isEnd = true;
    }

    bool search(string word)
    {
        helper(word, 0, this);
    }
};

int main()
{
    WordDictionary *wordTrie = new WordDictionary();
    wordTrie->addWord("p");
    wordTrie->addWord("pr");
    wordTrie->addWord("pre");
}