#include <iostream>
#include <chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedListQueue {
    Node* front;
    Node* rear;
    
    public:
    LinkedListQueue() {
        front = rear = nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    while(1)
    {
        int n;

    cout<<"Enter Size of Queue: "<<endl;
    cin>>n;
    LinkedListQueue queue;

    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<n;i++)
    {
        queue.enqueue(i+1);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Time taken to enqueue (linked list): " 
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    for(int i=0;i<n;i++)
    {
        queue.dequeue();
    }
    end = chrono::high_resolution_clock::now();
    cout << "Time taken to dequeue (linked list): " 
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

         cout<<endl<<endl;
    }

    return 0;
}
