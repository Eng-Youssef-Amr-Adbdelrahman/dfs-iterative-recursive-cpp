#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph {
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int n) {
        adjList.resize(n);

        for (const auto &edge : edges) {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

void iterativeDFS(Graph const &graph, int start, vector<bool> &visited) {
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (visited[vertex])
            continue;

        visited[vertex] = true;
        cout << vertex << " ";

        for (auto it = graph.adjList[vertex].rbegin(); it != graph.adjList[vertex].rend(); ++it) {
            if (!visited[*it]) {
                s.push(*it);
            }
        }
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {3, 5},
        {4, 6}, {4, 7}, {6, 8}, {7, 9}, {8, 10}, {9, 10}
    };

    int n = 11;

    Graph graph(edges, n);

    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            iterativeDFS(graph, i, visited);
        }
    }

    return 0;
}
