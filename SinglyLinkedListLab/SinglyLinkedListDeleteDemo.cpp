#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " deleted from the head." << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Node with value " << value << " deleted." << endl;
    }

    void printList() const {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    cout << "Original Linked List: ";
    list.printList();

    int valueToDelete;
    cout << "Enter the value to delete: ";
    cin >> valueToDelete;

    list.deleteNode(valueToDelete);

    cout << "Linked List after deletion: ";
    list.printList();

    return 0;
}
