#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

// Node class represents each node in the tree
class Node {
public:
    int data;
    Node* left, *right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BinarySearchTree class
class BinarySearchTree {
private:
    Node* root;

    // Helper method for recursive insertion
    Node* insertRec(Node* root, int data) {
        // Base case: if the tree is empty, create a new node
        if (root == nullptr) {
            return new Node(data);
        }

        // Otherwise, recur down the tree
        if (data < root->data) {
            root->left = insertRec(root->left, data); // Insert in left subtree
        }
        else if (data > root->data) {
            root->right = insertRec(root->right, data); // Insert in right subtree
        }

        // Return the (unchanged) node pointer
        return root;
    }

    // Helper methods for traversals
    void inOrderRec(Node* root) {
        if (root != nullptr) {
            inOrderRec(root->left); // Traverse left subtree
            cout << root->data << " "; // Visit node
            inOrderRec(root->right); // Traverse right subtree
        }
    }

    void preOrderRec(Node* root) {
        if (root != nullptr) {
            cout << root->data << " "; // Visit node
            preOrderRec(root->left); // Traverse left subtree
            preOrderRec(root->right); // Traverse right subtree
        }
    }

    void postOrderRec(Node* root) {
        if (root != nullptr) {
            postOrderRec(root->left); // Traverse left subtree
            postOrderRec(root->right); // Traverse right subtree
            cout << root->data << " "; // Visit node
        }
    }

    // Helper method to find the minimum value node in a subtree
    Node* minValueNode(Node* root) {
        Node* current = root;
        // Loop to find the leftmost leaf (minimum value node)
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper method for recursive deletion
    Node* deleteRec(Node* root, int data) {
        // Base case: if the tree is empty
        if (root == nullptr) {
            return root;
        }

        // Recur down the tree
        if (data < root->data) {
            root->left = deleteRec(root->left, data); // Go left
        }
        else if (data > root->data) {
            root->right = deleteRec(root->right, data); // Go right
        }
        else {
            // Node to be deleted is found

            // Case 1: Node has no children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: Node has only one child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has two children
            // Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteRec(root->right, temp->data);
        }

        return root;
    }

public:
    // Constructor to initialize the tree
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a new value into the tree
    void insert(int data) {
        root = insertRec(root, data);
    }

    // In-Order Traversal: Left, Root, Right
    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }

    // Pre-Order Traversal: Root, Left, Right
    void preOrder() {
        preOrderRec(root);
        cout << endl;
    }

    // Post-Order Traversal: Left, Right, Root
    void postOrder() {
        postOrderRec(root);
        cout << endl;
    }

    // Delete an item from the tree
    void deleteItem(int data) {
        root = deleteRec(root, data);
    }

    // Generate a BST from a given size using random values
    void generateTreeFromRandomValues(int size) {
        set<int> uniqueValues; // To store unique random values
        
        srand(time(0)); // Seed random number generator with the current time
        
        // Generate size unique random values and insert them into the tree
        while (uniqueValues.size() < size) {
            int randomValue = rand() % 1000 + 1; // Generate random number between 1 and 1000
            uniqueValues.insert(randomValue); // Insert into the set (set automatically handles duplicates)
        }

        // Insert all unique random values into the tree
        for (int value : uniqueValues) {
            insert(value);
        }
        
        cout << "Tree generated with " << size << " random values.\n";
    }

    // Menu method to handle user input
    void menu() {
        int choice, value, size;
        while (true) {
            cout << "\nSelect an option:\n";
            cout << "1. Insert new data\n";
            cout << "2. In-Order Traversal\n";
            cout << "3. Pre-Order Traversal\n";
            cout << "4. Post-Order Traversal\n";
            cout << "5. Delete an item\n";
            cout << "6. Generate tree from random values\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the value to insert: ";
                    cin >> value;
                    insert(value);
                    break;

                case 2:
                    cout << "In-Order Traversal: ";
                    inOrder();
                    break;

                case 3:
                    cout << "Pre-Order Traversal: ";
                    preOrder();
                    break;

                case 4:
                    cout << "Post-Order Traversal: ";
                    postOrder();
                    break;

                case 5:
                    cout << "Enter the value to delete: ";
                    cin >> value;
                    deleteItem(value);
                    break;

                case 6:
                    cout << "Enter the size of the tree: ";
                    cin >> size;
                    generateTreeFromRandomValues(size);
                    break;

                case 7:
                    cout << "Exiting...\n";
                    return; // Exit the program

                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

// Main function to drive the program
int main() {
    BinarySearchTree bst;
    bst.menu(); // Start the menu-driven interface
    return 0;
}