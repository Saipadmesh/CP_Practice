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

using namespace std;

// The class of a Trie node contains a hash table <char, Trie> which contains
// the children of the node, and a bool to check if it is the end. For
// insertion, and search, use a Trie node pointer to traverse through children
class Trie {
  // Implemented using hash table
protected:
  bool isEnd;
  map<char, Trie> children;

public:
  Trie() {
    isEnd = false;
    children = {};
  }

  void insert(string word) {
    if (word == "") {
      return;
    }
    Trie *currNode = this;
    for (auto &itr : word) {
      if (currNode->children.find(itr) == currNode->children.end()) {
        currNode->children[itr] = Trie();
      }
      currNode = &currNode->children[itr];
    }
    currNode->isEnd = true;
  }

  bool search(string word) {
    if (word == "") {
      return false;
    }
    Trie *currNode = this;
    for (auto &itr : word) {

      if (currNode->children.find(itr) == currNode->children.end()) {
        return false;
      }
      currNode = &currNode->children[itr];
    }
    if (currNode->isEnd == true) {
      return true;
    }
    return false;
  }

  bool startsWith(string prefix) {
    if (prefix == "") {
      return false;
    }
    Trie *currNode = this;
    for (int i = 0; i < prefix.size(); i++) {

      if (currNode->children.find(prefix[i]) == currNode->children.end()) {
        return false;
      }

      currNode = &currNode->children[prefix[i]];
    }
    return true;
  }

  void printTrie() { printTrieRecursive(this); }

private:
  void printTrieRecursive(Trie *root) {
    for (auto &node : root->children) {
      cout << node.first << endl;
      printTrieRecursive(&node.second);
    }
  }
  void printMapKeys(Trie *currNode) {
    for (auto &itr : currNode->children) {
      cout << itr.first << " ";
    }
    cout << endl;
  }
};

int main() {
  Trie *wordTrie = new Trie();
  wordTrie->insert("p");
  wordTrie->insert("pr");
  wordTrie->insert("pre");
  // wordTrie->printTrie();
  cout << wordTrie->startsWith("pre") << endl;
}