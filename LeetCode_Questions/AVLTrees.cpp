#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure of a node in the AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Class definition for the AVL Tree
class AVLTree {
public:
    Node* root;

    // Constructor to initialize an empty tree
    AVLTree() {
        root = nullptr;
    }

    // Function to insert a new value into the AVL Tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to validate and print the balancing factor of each node
    void validateAndPrintBalanceFactors() {
        validateAndPrintRec(root);
    }

private:
    // Get the height of the tree
    int height(Node* node) {
        return node == nullptr ? 0 : node->height;
    }

    // Calculate the balance factor of a node
    int getBalanceFactor(Node* node) {
        return node == nullptr ? 0 : height(node->left) - height(node->right);
    }

    // Helper function for recursive insertion with balancing
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        } else {
            return node; // Duplicates are not allowed
        }

        // Update the height of the current node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor to check if the node is unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // Return the unchanged node pointer
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x; // Return new root
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y; // Return new root
    }

    // Helper function to validate and print the balancing factors
    void validateAndPrintRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        validateAndPrintRec(node->left);

        int balanceFactor = getBalanceFactor(node);
        cout << "Node: " << node->data << " | Balance Factor: " << balanceFactor << endl;

        validateAndPrintRec(node->right);
    }
};

int main() {
    AVLTree avl;

    // Insert values into the AVL Tree
    avl.insert(60);
    avl.insert(30);
    avl.insert(20);
    avl.insert(26);
    avl.insert(28);
    avl.insert(25);
    avl.insert(68);
    avl.insert(67);
    avl.insert(69);
    avl.insert(78);
    avl.insert(76);
    avl.insert(74);
    avl.insert(71);
    avl.insert(70);

    // Validate and print balancing factors
    cout << "Balancing factors of nodes in the AVL Tree:" << endl;
    avl.validateAndPrintBalanceFactors();

    return 0;
}
