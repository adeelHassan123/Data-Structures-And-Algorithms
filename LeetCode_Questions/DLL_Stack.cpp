#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class linkList {
public:
    void insertAthead(Node*& head, Node*& tail, int data) {
        Node* node = new Node(data);
        if (head == nullptr) {  
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void insertAtLocation(Node* &head, Node* &tail, int location, int data) {
        if (location == 1 || head == nullptr) {
            insertAthead(head, tail, data);
            return;
        }
        Node* new_node = new Node(data);
        Node* temp = head;

        for (int i = 1; i < location - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = new_node;
        } else {
            tail = new_node;  
        }
        new_node->prev = temp;
        temp->next = new_node;
    }

    void insertAtTail(Node*& tail, int data) {
        Node* node = new Node(data);
        if (tail == nullptr) {  
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void deleteNode(int loc, Node*& head, Node*& tail) {
    if (head == nullptr) return; 

    int len = getLength(head);  

    if (loc < 1 || loc > len) {
        cout << "Invalid location!" << endl;
        return;  
    }

    if (loc == 1) {
        Node* temp = head;
        if (head == tail) {  
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    if (loc == len) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < loc; i++) {
        temp = temp->next;
    }

    if (temp->next != nullptr) temp->next->prev = temp->prev;
    if (temp->prev != nullptr) temp->prev->next = temp->next;

    delete temp;
}


    void printNode(Node*& head, Node*& tail) {
        Node* temp = head;
        cout << endl << "Link List Print using head: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        temp = tail;
        cout << endl << "Reverse Link List Print using tail: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }

    int getLength(Node*& head) {
        int len = 0;
        Node* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    linkList* L1 = new linkList;

    int a = 100;
    while (a >= 0) {
        L1->insertAthead(head, tail, a);
        a -= 20;
    }

    int b = 10;
    for (int i = 2; i < 12; i += 2) {
        L1->insertAtLocation(head, tail, i, b);
        b += 20;
    }

    int c = 130;
    for (int i = 0; i < 3; i++) {
        L1->insertAtTail(tail, c);
        c += 10;
    }

    L1->printNode(head, tail);
    cout << endl << "Length: " << L1->getLength(head) << endl;

    

    L1->deleteNode(12, head, tail);
    cout << endl << "After deleting: " << endl;

    L1->printNode(head, tail);

    return 0;
}
