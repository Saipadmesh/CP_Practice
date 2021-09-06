#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
  int src;
  int dest;
  int weight;

  Edge(int src, int dest, int weight) {
    this->src = src;
    this->dest = dest;
    this->weight = weight;
  }
};

class Graph {
private:
  vector<Edge *> edgeList;
  int vertices, edges;

public:
  Graph(int v, int e) {
    this->vertices = v;
    this->edges = e;
  }
  void addEdge(int src, int dest, int weight) {
    edgeList.push_back(new Edge(src, dest, weight));
  }

  void printEdges() {
    for (auto edge : this->edgeList) {
      cout << edge->src << "--" << edge->dest << " : " << edge->weight << endl;
    }
  }

  int findParent(int vertex, int *parents) {
    if (parents[vertex] == vertex)
      return vertex;
    return findParent(parents[vertex], parents);
  }

  void kruskalMST() {
    // Sorting the edgeList
    sort(edgeList.begin(), edgeList.end(),
         [](const Edge *lhs, const Edge *rhs) {
           return lhs->weight < rhs->weight;
         });

    // Set up the parents array
    int *parents = new int[this->vertices + 1];
    for (int i = 0; i <= this->vertices; i++) {
      parents[i] = i;
    }

    // Adding edges to the MST
    vector<Edge *> MST;
    int i = 0;
    while (MST.size() != (this->vertices - 1)) {
      Edge *currEdge = edgeList[i];

      int srcParent = findParent(currEdge->src, parents);
      int destParent = findParent(currEdge->dest, parents);

      if (srcParent != destParent) {
        parents[destParent] = srcParent;
        MST.push_back(currEdge);
      }

      i++;
    }

    cout << "The MST is: " << endl;
    for (auto edge : MST) {
      cout << edge->src << "--" << edge->dest << " : " << edge->weight << endl;
    }
  }
};

int main() {
  ifstream file;
  file.open("graph_input.txt");
  int E, V;
  cout << "Enter the number of Vertices: ";
  file >> V;
  cout << "Enter the number of Edges: ";
  file >> E;

  Graph *graph = new Graph(V, E);

  int src, dest, wt;
  for (int i = 0; i < E; i++) {
    cout << "Enter edge number " << i + 1 << ": ";
    file >> src >> dest >> wt;
    graph->addEdge(src, dest, wt);
  }

  cout << "The edges are: " << endl;
  graph->printEdges();
  graph->kruskalMST();

  return 0;
}