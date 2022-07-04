#include <set>
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

Node *cloneGraph(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    queue<Node *> main_q;
    unordered_map<Node *, Node *> map;
    set<int> visited;
    main_q.push(node);
    Node *head = nullptr;
    Node *temp;

    while (!main_q.empty())
    {
        Node *curr = main_q.front();
        main_q.pop();
        if (visited.find(curr->val) != visited.end())
        {
            continue;
        }
        visited.insert(curr->val);
        if (head == nullptr)
        {
            head = new Node(curr->val);
            map[curr] = head;
        }

        temp = map[curr];
        for (auto neighbor : curr->neighbors)
        {
            if (map.find(neighbor) == map.end())
            {
                map[neighbor] = new Node(neighbor->val);
            }
            temp->neighbors.push_back(map[neighbor]);
            main_q.push(neighbor);
        }
    }
    return head;
}