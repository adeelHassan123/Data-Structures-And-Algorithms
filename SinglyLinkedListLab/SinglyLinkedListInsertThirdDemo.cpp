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

    void insertAtThirdPosition(int value) {
        if (head == nullptr || head->next == nullptr) {
            cout << "List is too short to insert at the 3rd position." << endl;
            return;
        }

        Node* newNode = new Node(value);  

        Node* temp = head;
        for (int i = 1; i < 2 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList() const {
        Node* temp = head;
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
    
    list.insertAtThirdPosition(25);

    cout << "After inserting at 3rd position: ";
    list.printList();

    return 0;
}
