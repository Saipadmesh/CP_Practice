#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void print_array(bool arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}
// for sorting the priority queue from minimum to maximum
struct compare_pq {
  bool operator()(vector<int> &a, vector<int> &b) {
    int first = a[2];
    int second = b[2];
    return first > second;
  }
};

// For linked list
class Node {
public:
  int vertex, weight;
  Node *next;

public:
  Node(int v, int w) {
    vertex = v;
    weight = w;
    next = nullptr;
  }
};

void print_map(map<int, Node *> graph) {
  cout << "Graph is: " << endl;
  Node *start;
  for (auto it : graph) {
    cout << "(" << it.first << ":";
    start = it.second;
    while (start != nullptr) {
      cout << start->vertex << ",";
      start = start->next;
    }
    cout << ")" << endl;
  }
}

void print_pq(
    priority_queue<vector<int>, vector<vector<int>>, compare_pq> &pq) {
  queue<vector<int>> q;
  cout << "Priority queue: ";
  while (!pq.empty()) {
    cout << "(" << pq.top()[0] << "," << pq.top()[1] << ")"
         << ",";
    q.push(pq.top());
    pq.pop();
  }
  while (!q.empty()) {

    pq.push(q.front());
    q.pop();
  }
  cout << endl;
}

class Graph {
protected:
  map<int, Node *> graph;

public:
  void addEdge(int src, int dest, int weight) {
    if (graph.find(src) != graph.end()) {
      Node *start = graph.find(src)->second;
      while (start->next != nullptr) {
        start = start->next;
      }
      start->next = new Node(dest, weight);
    } else {
      Node *node = new Node(dest, weight);
      graph.insert(make_pair(src, node));
    }

    if (graph.find(dest) != graph.end()) {
      Node *start = graph.find(dest)->second;
      while (start->next != nullptr) {
        start = start->next;
      }
      start->next = new Node(src, weight);
    } else {
      Node *node = new Node(src, weight);
      graph.insert(make_pair(dest, node));
    }
  }

  void prim(int start_index) {
    priority_queue<vector<int>, vector<vector<int>>, compare_pq> pq;
    int vertices = graph.size();
    if (start_index >= vertices) {
      return;
    }
    pq.push(vector<int>{-1, start_index, 0});
    int keys[vertices];
    fill_n(keys, vertices, INT_MAX);
    keys[start_index] = 0;
    vector<vector<int>> mst;
    bool visited[vertices];
    fill_n(visited, vertices, false);
    make_mst(pq, mst, visited, keys);
    print_mst(mst);
  }

protected:
  // recursive function
  void
  make_mst(priority_queue<vector<int>, vector<vector<int>>, compare_pq> &pq,
           vector<vector<int>> &mst, bool visited[], int keys[]) {

    int vertices = graph.size();
    if (pq.empty()) {
      return;
    }
    int curr_index = pq.top()[1], prev_index = pq.top()[0],
        weight = pq.top()[2];
    if (visited[curr_index] == true) {
      return;
    }
    if (prev_index != -1) {
      mst.push_back(vector<int>{prev_index, curr_index, weight});
    }
    pq.pop();                   // remove the element with least weight
    visited[curr_index] = true; // mark as visited
    Node *curr_node = graph[curr_index];
    while (curr_node != nullptr) {
      int dest_index = curr_node->vertex;
      int weight = curr_node->weight;
      if (visited[dest_index] == false && keys[dest_index] > weight) {

        keys[dest_index] = weight;
        pq.push(vector<int>{curr_index, dest_index, weight});
      }
      curr_node = curr_node->next;
    }

    make_mst(pq, mst, visited, keys);
  }

  void print_mst(vector<vector<int>> mst) {
    cout << "The MST is:" << endl;
    for (auto it = mst.begin(); it < mst.end(); it++) {

      cout << it->at(0) << " - " << it->at(1) << ": " << it->at(2) << endl;
    }
  }
};

int main() {
  cout << "Enter number of vertices: ";
  int n;
  cin >> n;
  cout << "Enter number of edges: ";
  int e;
  cin >> e;

  Graph g;
  int i = 1;
  while (i <= e) {

    cout << "Enter Edge Number " << i << ": ";
    int src, dest, weight;
    cin >> src;
    cin >> dest;
    cin >> weight;
    g.addEdge(src, dest, weight);
    i++;
  }
  cout << "Enter starting index: ";
  int start_index;
  cin >> start_index;
  g.prim(start_index);
}