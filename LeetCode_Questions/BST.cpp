#include <iostream>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Class definition for the Binary Search Tree
class BSTree {
public:
    Node* root;

    // Constructor to initialize an empty tree
    BSTree() {
        root = nullptr;
    }

    // Function to insert a new value into the BST
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to search for a value in the BST
    bool search(int value) {
        return searchRec(root, value);
    }

    // Function to delete a value from the BST
    void deleteValue(int value) {
        root = deleteRec(root, value);
    }

    // Function to validate if the tree is a BST
    bool isBST() {
        return isBSTRec(root);
    }

    // Function to perform in-order traversal
    void inOrderTraversal() {
        inOrderRec(root);
        cout << endl;
    }

private:
    // Helper function for recursive insertion
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    // Helper function for recursive search
    bool searchRec(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }

    // Helper function for recursive deletion
    Node* deleteRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteRec(node->right, temp->data);
        }

        return node;
    }

    // Helper function to find the node with minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;

        // Loop to find the leftmost leaf
        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    // Helper function to validate if the tree is a BST
    bool isBSTRec(Node* node) {
        return isBSTUtil(node, INT_MIN, INT_MAX);
    }
    bool isBSTUtil(Node* node, int min, int max) {

        cout<<"Minimum: "<<min<<" Maximum: "<<max<<endl;
        if (node == nullptr) {
            return true;
        }

        if (node->data < min || node->data > max) {
            return false;
        }

        return isBSTUtil(node->left, min, node->data ) && isBSTUtil(node->right, node->data , max);
    }

    // Helper function for recursive in-order traversal
    void inOrderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderRec(node->left);
        cout << node->data << " ";
        inOrderRec(node->right);
    }
};

int main() {
    BSTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform in-order traversal
    cout << "In-order traversal of the BST: ";
    bst.inOrderTraversal();

    // Search for values in the BST
    int searchValue = 40;
    if (bst.search(searchValue)) {
        cout << searchValue << " is found in the BST." << endl;
    } else {
        cout << searchValue << " is not found in the BST." << endl;
    }

    searchValue = 90;
    if (bst.search(searchValue)) {
        cout << searchValue << " is found in the BST." << endl;
    } else {
        cout << searchValue << " is not found in the BST." << endl;
    }

    // Delete a node from the BST
    cout << "Deleting 20 from the BST." << endl;
    bst.deleteValue(20);
    cout << "In-order traversal after deletion: ";
    bst.inOrderTraversal();

    // Validate if the tree is a BST
    if (bst.isBST()) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
