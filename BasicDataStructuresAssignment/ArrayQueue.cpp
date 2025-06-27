#include <iostream>
#include <chrono>
using namespace std;

class ArrayQueue {
    int* arr;
    int front, rear, capacity;

public:
    ArrayQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int data) {
        if (rear == capacity - 1) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = data;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front++;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~ArrayQueue() {
        delete[] arr;
    }
};

int main() {

    while(1)
    {
    int size, data;
    cout << "Enter the size of the queue: ";
    cin >> size;

    ArrayQueue queue(size);

    for(int i=0;i<size-4;i++)
    {
        queue.enqueue(i+1);
    }

    auto start = chrono::high_resolution_clock::now();
    queue.enqueue(10);
    auto end = chrono::high_resolution_clock::now();
    cout << "Time taken to enqueue (array): " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    queue.dequeue();
    end = chrono::high_resolution_clock::now();
    cout << "Time taken to dequeue (array): " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    cout<<endl<<endl;
    }

    return 0;
}
