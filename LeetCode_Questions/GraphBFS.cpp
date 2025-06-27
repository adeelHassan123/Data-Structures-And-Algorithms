#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjlist;

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool directed) {
        adjlist[u].push_back(v);
        if (!directed) {
            adjlist[v].push_back(u);
        }
    }

    // Function for BFS traversal
    vector<int> bfsTraversal(int startNode) {
        unordered_map<int, bool> visited; // Map to track visited nodes
        queue<int> q;                    // Queue for BFS
        vector<int> result;              // To store the BFS traversal result

        // Start BFS from the startNode
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            // Traverse all neighbors of the current node
            for (int neighbor : adjlist[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return result;
    }

    // Function to display the adjacency list
    void displayGraph() {
        for (auto &node : adjlist) {
            cout << node.first << " -> ";
            for (int neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    cout << "Enter the number of edges and (0 for undirected & 1 for directed): ";
    int edges;
    bool directed;
    cin >> edges >> directed;

    cout << "Enter the edges (start end):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, directed);
    }

    cout << "Adjacency List:" << endl;
    g.displayGraph();

    cout << "Enter the starting node for BFS traversal: ";
    int startNode;
    cin >> startNode;

    vector<int> bfsResult = g.bfsTraversal(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
