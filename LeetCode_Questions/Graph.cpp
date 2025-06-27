#include <iostream>
using namespace std;

// Node class to represent each element in the list
class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) {
        value = val;
        next = nullptr;
    }
};

// Custom implementation of a singly linked list
class List {
private:
    ListNode* head;
public:
    List() {
        head = nullptr;
    }
    // Add a node to the end of the list
    void push_back(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // Display the list elements
    void display() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
    // Get the head of the list
    ListNode* getHead() {
        return head;
    }
};

// Map node to represent key-value pairs
class MapNode {
public:
    int key;
    List value;

    MapNode* next;

    MapNode(int k) {
        key = k;
        next = nullptr;
    }
};

// Custom implementation of a map (unordered)
class Map {
private:
    MapNode* head;

public:
    Map() {
        head = nullptr;
    }

    // Insert or update a key-value pair
    void insert(int key, int value) {
        MapNode* temp = head;
        while (temp) {
            if (temp->key == key) {
                temp->value.push_back(value);
                return;
            }
            temp = temp->next;
        }

        MapNode* newNode = new MapNode(key);
        newNode->value.push_back(value);
        newNode->next = head;
        head = newNode;
    }

    // Get the value for a specific key
    List* get(int key) {
        MapNode* temp = head;
        while (temp) {
            if (temp->key == key) {
                return &(temp->value);
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Display the map contents
    void display() {
        MapNode* temp = head;
        while (temp) {
            cout << temp->key << " -> ";
            temp->value.display();
            cout << endl;
            temp = temp->next;
        }
    }

    // Check if a key exists
    bool containsKey(int key) {
        MapNode* temp = head;
        while (temp) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

// Graph class using custom Map and List implementations
class Graph {
public:
    Map adjlist;

    void addEdge(int n, int e, bool direct) {
        adjlist.insert(n, e);
        if (!direct) {
            adjlist.insert(e, n);
        }
    }

    void printGraph() {
        cout << "Node -> Edges" << endl;
        adjlist.display();
    }
};

int main() {
    cout << "Graph implementation using adjacency list" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Enter the number of edges and (0 for undirected & 1 for directed): ";
    int n;
    bool d;
    cin >> n >> d;
    Graph g;

    cout << "Enter the edges (start end):" << endl;
    for (size_t i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        g.addEdge(n1, n2, d);
    }

    g.printGraph();

    return 0;
}
