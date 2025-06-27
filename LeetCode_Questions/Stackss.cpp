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

class Stack {
    public:
    // Push operation: Add an item to the top of the stack
    void push(int data,Node* &head,Node* &tail) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head =tail= newNode;  // If stack is empty, new node is the head
        } else {
            newNode->prev =tail;
            tail->next = newNode;
            tail=newNode;
        }
        cout << "Pushed " << data << " onto stack." << endl;
    }

    
    // Pop operation: Remove the top item from the stack
void pop(Node* &head, Node* &tail) {
    if (head == nullptr) {
        cout << "Stack underflow: No elements to pop." << endl;
        return;
    }
    
    Node* temp = tail;
    if (head == tail) { // Only one element in the stack
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    
    cout << "Popped " << temp->data << " from stack." << endl;
    delete temp;
}


    // Peek operation: Get the top item of the stack
    int peek(Node* &tail) const {
        if (tail == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;  // Return -1 to indicate the stack is empty
        }
        return tail->data;
    }

    // Check if stack is empty
    bool isEmpty(Node* &head) const {
        return head == nullptr;
    }

    // Display the stack contents
    void display(Node* &head) const {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Stack contents: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    Stack stack;
    Node* head=nullptr;
    Node* tail=nullptr;

    stack.push(10,head,tail);
    stack.push(20,head,tail);
    stack.push(30,head,tail);

    cout << "Top element is: " << stack.peek(tail) << endl;

    stack.display(head);

    stack.pop(head,tail);
    stack.pop(head,tail);

    cout << "Top element after two pops: " << stack.peek(tail) << endl;

    stack.display(head);

    stack.pop(head,tail);
    stack.pop(head,tail);  // Trying to pop from an empty stack

    return 0;
}
