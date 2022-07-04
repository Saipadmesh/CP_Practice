#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

bool detectCycle(vector<vector<int>> &graph, int curr, vector<bool> &visited, vector<bool> &dfsVisited)
{
    // mark as visited in both arrays
    visited[curr] = true;
    dfsVisited[curr] = true;

    for (auto neighbor : graph[curr])
    {
        // If the neighbor is not visited, recursively call the function
        if (!visited[neighbor])
        {
            bool check = detectCycle(graph, neighbor, visited, dfsVisited);
            if (check)
            {
                return true;
            }
        }
        // If a neighbor is visited in the current dfs cycle and is visited again, then a cycle is present
        else if (visited[neighbor] && dfsVisited[neighbor])
        {
            return true;
        }
    }
    // Backtrack after the dfs call is done and clear the array
    dfsVisited[curr] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // We use an adjacency list stored as an array to represent the graph
    vector<vector<int>> adj(numCourses);

    for (auto pre : prerequisites)
    {
        int u = pre[0];
        int v = pre[1];
        adj[v].push_back(u);
    }

    // These arrays are used for cycle detection.
    // The first array checks if a node is visited, second array checks if the node is visited in the current DFS cycle i.e once the DFS call is done, node is marked as non visited
    vector<bool> visited(numCourses, 0);
    vector<bool> dfsVisited(numCourses, 0);
    // We need to detect cycle considering all nodes as starting nodes.
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            bool isCycle = detectCycle(adj, i, visited, dfsVisited);
            if (isCycle)
            {
                return false;
            }
        }
    }
    return true;
}