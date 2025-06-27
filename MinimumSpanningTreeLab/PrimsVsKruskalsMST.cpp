#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono> // For time measurement

using namespace std;

// Custom Queue Implementation
class Queue {
private:
    vector<pair<int, int>> data; // Stores {vertex, key} pairs

public:
    void push(int vertex, int key) {
        data.push_back({vertex, key});
    }

    pair<int, int> pop() {
        int minIndex = 0;
        for (int i = 1; i < data.size(); i++) {
            if (data[i].second < data[minIndex].second) {
                minIndex = i;
            }
        }
        pair<int, int> minElement = data[minIndex];
        data.erase(data.begin() + minIndex);
        return minElement;
    }

    bool empty() const {
        return data.empty();
    }

    void updateKey(int vertex, int newKey) {
        for (auto& element : data) {
            if (element.first == vertex) {
                element.second = newKey;
                return;
            }
        }
    }

    bool contains(int vertex) const {
        for (const auto& element : data) {
            if (element.first == vertex) return true;
        }
        return false;
    }
};

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Function to perform Prim's Algorithm with a custom queue
long long primMST(int n, vector<vector<pair<int, int>>>& adjList) {
    auto startTime = chrono::high_resolution_clock::now();

    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    Queue queue;

    key[0] = 0;
    queue.push(0, 0);

    int totalCost = 0;

    while (!queue.empty()) {
        auto [u, uKey] = queue.pop();

        if (inMST[u]) continue; // Skip if already included in MST
        inMST[u] = true;
        totalCost += uKey;

        for (auto [v, weight] : adjList[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;

                if (queue.contains(v)) {
                    queue.updateKey(v, weight);
                } else {
                    queue.push(v, weight);
                }
            }
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    cout << "Prim's Algorithm MST:\n";
    cout << "Edge\tWeight\n";
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
    }
    cout << "Total cost: " << totalCost << "\n";
    cout << "Time complexity: O(V^2)\n";
    cout << "Execution time: " << duration << " microseconds\n\n";

    return duration;
}

// Function to find the root of a set in Union-Find
int findParent(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent);
}

// Function to perform Union of two sets in Union-Find
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

// Function to perform Kruskal's Algorithm
long long kruskalMST(int n, vector<Edge>& edges) {
    auto startTime = chrono::high_resolution_clock::now();

    sort(edges.begin(), edges.end());

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int totalCost = 0;
    vector<Edge> mst;

    for (const auto& edge : edges) {
        int u = findParent(edge.u, parent);
        int v = findParent(edge.v, parent);

        if (u != v) {
            mst.push_back(edge);
            totalCost += edge.weight;
            unionSets(u, v, parent, rank);
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    cout << "Kruskal's Algorithm MST:\n";
    cout << "Edge\tWeight\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << "\t" << edge.weight << "\n";
    }
    cout << "Total cost: " << totalCost << "\n";
    cout << "Time complexity: O(E log E)\n";
    cout << "Execution time: " << duration << " microseconds\n\n";

    return duration;
}

// Main function
int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n);
    vector<Edge> edges;

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
        edges.push_back({u, v, weight});
    }

    cout << "\n";
    long long primTime = primMST(n, adjList);
    long long kruskalTime = kruskalMST(n, edges);

    // Print the time complexity table
    cout << "Time Complexity Comparison:\n";
    cout << "---------------------------------------------------\n";
    cout << "| Algorithm         | Time Complexity | Execution Time (µs) |\n";
    cout << "---------------------------------------------------\n";
    cout << "| Prim's Algorithm  | O(V^2)          | " << primTime << " µs       |\n";
    cout << "| Kruskal's Algorithm | O(E log E)     | " << kruskalTime << " µs       |\n";
    cout << "---------------------------------------------------\n";

    return 0;
}
