#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void print_dfs_adjacency_list(unordered_map<int, vector<int>> graph, int startNode)
{
    stack<int> s;
    unordered_map<int, bool> visited;
    s.push(startNode);
    int currNode;
    while (!s.empty())
    {
        currNode = s.top();
        cout << currNode << " ";
        s.pop();
        visited[currNode] = true;
        vector<int> neighbors = graph[currNode];
        for (auto neighbor : neighbors)
        {
            if (visited.find(neighbor) == visited.end())
            {
                s.push(neighbor);
            }
        }
    }
}

int main()
{
    unordered_map<int, vector<int>> graph = {{0, {1, 2}}, {1, {3}}, {2, {5, 3}}};
    print_dfs_adjacency_list(graph, 0);
}