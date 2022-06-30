#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

void print_bfs_adjacency_list(unordered_map<int, vector<int>> graph, int startNode)
{
    queue<int> q;
    unordered_map<int, bool> visited;
    q.push(startNode);
    int currNode;
    while (!q.empty())
    {
        currNode = q.front();
        q.pop();
        if (visited[currNode])
        {
            continue;
        }
        cout << currNode << " ";
        visited[currNode] = true;
        vector<int> neighbors = graph[currNode];
        for (auto neighbor : neighbors)
        {
            if (visited.find(neighbor) == visited.end() || visited[neighbor] != true)
            {
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    unordered_map<int, vector<int>> graph = {{0, {1, 2}}, {1, {3}}, {2, {5, 3}}};
    print_bfs_adjacency_list(graph, 0);
}