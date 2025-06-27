#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class linkList {
public:
    void insertAtHead(Node*& head, Node*& tail, int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void insertAtTail(Node*& tail, int data) {
        Node* node = new Node(data);
        if (tail == nullptr) {
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void insertAtLocation(Node*& head, Node*& tail, int element, int data) {
        if (head == nullptr) {
            insertAtHead(head, tail, data);
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != element) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Element " << element << " not found, inserting at tail." << endl;
            insertAtTail(tail, data);
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
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
            tail->next = nullptr;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < loc; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void printNode(Node*& head, Node*& tail) {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << "Backward: ";
        temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    int getLength(Node* head) {
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
    linkList* L1 = new linkList();

    int a = 100;
    while (a >= 0) {
        L1->insertAtHead(head, tail, a);
        a -= 20;
    }

    int b = 10;
    for (int i = 2; i < 12; i += 2) {
        L1->insertAtLocation(head, tail, i * 10, b);
        b += 20;
    }

    int c = 130;
    for (int i = 0; i < 3; i++) {
        L1->insertAtTail(tail, c);
        c += 10;
    }

    L1->printNode(head, tail);
    cout << "Length: " << L1->getLength(head) << endl;

    L1->deleteNode(12, head, tail);
    cout << "After deleting: " << endl;
    L1->printNode(head, tail);

    delete L1;
    return 0;
}
