#include <iostream>
#include <vector>

using namespace std;

class HashMap {
private:
    vector<int> table; // Hash table
    int size;          // Number of buckets in the table

    // Hash function to compute index
    int hash(int key) {
        return key % size;
    }

public:
    // Constructor to initialize the hash table
    HashMap(int s) {
        size = s;
        table.resize(size, -1); // Initialize all slots to -1 (indicating empty)
    }

    // Function to insert a key
    void insert(int key) {
        int index = hash(key);
        int prob = 0;

        // Linear probing to find an empty slot or a slot marked as removed (-1)
        while (table[index] != -1) {
            if (table[index] == key) { // Prevent duplicate insertion
                cout << "Key " << key << " already exists in the hash table." << endl;
                return;
            }
            index = (index + 1) % size;
            prob++;

            if (prob == size) { // Full table check
                cout << "Hash table is full. Cannot insert key: " << key << endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << " after " << prob + 1 << " probes." << endl;
    }

    // Function to search for a key
    bool search(int key) {
        int index = hash(key);

        // Linear probing to search for the key
        while (table[index] != -1) {
            if (table[index] == key) {
                return true; // Key found
            }
            index = (index + 1) % size;
        }

        return false; // Key not found
    }

    // Function to remove a key
    void remove(int key) {
        int index = hash(key);

        // Linear probing to find the key
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1; // Mark the slot as removed
                cout << "Removed key " << key << " from index " << index << "." << endl;
                return;
            }
            index = (index + 1) % size;
        }

        cout << "Key " << key << " not found in the hash table." << endl;
    }

    // Function to display the hash table
    void display() {
        cout << "Hash table:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
        }
    }
};

int main() {
    HashMap map(10); // Create a hash table with 10 slots

    // Insert integers
    map.insert(12);
    map.insert(22);
    map.insert(32);
    map.insert(42);
    map.insert(52);

    // Display the hash table
    map.display();

    // Remove a key
    map.remove(32);
    cout << "\nAfter removing 32:" << endl;
    map.display();

    // Insert a new key to reuse the removed slot
    map.insert(62);

    cout << "\nAfter inserting 62:" << endl;
    map.display();

    // Search for keys
    cout << "\nSearch for 22: " << (map.search(22) ? "Found" : "Not Found") << endl;
    cout << "Search for 100: " << (map.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}
