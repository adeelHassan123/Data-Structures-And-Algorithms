#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class CircularLinkList {
public:
    void insertAthead(int data, Node* &head) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = newnode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            newnode->prev = tail;
            tail->next = newnode;
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtLoction(int data, int loc, Node* &head) {
        if (loc == 1) {  // Comparison corrected here
            insertAthead(data, head);
            return;
        }
        Node* newnode = new Node(data);
        Node* temp = head;
        
        for (int i = 1; i < loc - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }

    void insertatTail(int data, Node* &tail) {
        Node* newnode = new Node(data);
        if (tail == nullptr) {
            tail = newnode;
            tail->next = tail;
            tail->prev = tail;
        } else {
            Node* head = tail->next;
            newnode->next = head;
            newnode->prev = tail;
            tail->next = newnode;
            head->prev = newnode;
            tail = newnode;
        }
    }

    void deleteHead(Node* &head) {
        if (head == nullptr) return;

        Node* temp = head;
        if (head->next == head) {  // Only one node in the list
            head = nullptr;
        } else {
            Node* tail = head->prev;
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
    }

    void deleteAtLoction(int loc, Node* &head) {
        if (loc == 1) {  // Comparison corrected here
            deleteHead(head);
            return;
        }
        Node* temp = head;

        for (int i = 1; i < loc && temp->next != head; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void deleteTail(Node* &tail) {
        if (tail == nullptr) return;

        Node* temp = tail;
        if (tail->next == tail) {  // Only one node in the list
            tail = nullptr;
        } else {
            Node* head = tail->next;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
    }

    void printLinkList(Node* &head) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "===================================" << endl;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl << "===================================" << endl;
    }
};

int main() {
    CircularLinkList* C1 = new CircularLinkList;
    Node* head = nullptr;
    Node* tail = nullptr;

    // Inserting nodes at the head
    C1->insertAthead(5, head);
    C1->insertAthead(4, head);
    C1->insertAthead(3, head);
    cout << "After inserting at head:" << endl;
    C1->printLinkList(head);

    // Inserting at a specific location
    C1->insertAtLoction(6, 2, head);  // Insert 6 at position 2
    cout << "After inserting 6 at position 2:" << endl;
    C1->printLinkList(head);

    // Inserting at the tail
    tail = head->prev;  // Manually setting tail for demonstration
    C1->insertatTail(7, tail);
    cout << "After inserting at tail:" << endl;
    C1->printLinkList(head);

    // Deleting the head
    C1->deleteHead(head);
    cout << "After deleting head:" << endl;
    C1->printLinkList(head);

    // Deleting at a specific location
    C1->deleteAtLoction(2, head);  // Delete node at position 2
    cout << "After deleting node at position 2:" << endl;
    C1->printLinkList(head);

    // Deleting the tail
    tail = head->prev;  // Refresh the tail pointer
    C1->deleteTail(tail);
    cout << "After deleting tail:" << endl;
    C1->printLinkList(head);

    // Clean up
    delete C1;
    return 0;
}
