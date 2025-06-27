#include <iostream>
#include <chrono>
using namespace std;

class Array {
private:
    int* arr;
    int capacity;
    int size;

public:
    Array(int cap)
    {
        this->capacity=cap;
        this->size=0;
        this->arr=new int[capacity];
    }

    ~Array() {
        delete[] arr;
    }

    void insertAtEnd(int value) {
        if (size < capacity) {
            arr[size++] = value;
        } else {
            cout << "Array is full\n";
        }
    }

    void insertAtBeginning(int value) {
        if (size < capacity) {
            for (int i = size; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            size++;
        } else {
            cout << "Array is full\n";
        }
    }

    void deleteAtEnd() {
        if (size > 0) {
            size--;
        } else {
            cout << "Array is empty\n";
        }
    }

    void deleteAtBeginning() {
        if (size > 0) {
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else {
            cout << "Array is empty\n";
        }
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
   int n;
    cout << "Enter Size of Array: " << endl;
    cin >> n;

    Array arr(n);
    for(int i=0;i<n;i++)
    {
        arr.insertAtEnd(n+1);
    }

    auto total_start = chrono::high_resolution_clock::now();

    auto start = chrono::high_resolution_clock::now();
    
    auto end = chrono::high_resolution_clock::now();
    cout << "Insertion at end: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    arr.insertAtBeginning(1);
    end = chrono::high_resolution_clock::now();
    cout << "Insertion at beginning: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    arr.insertAtEnd(10);
    arr.display();

    start = chrono::high_resolution_clock::now();
    int pos = arr.search(10);
    end = chrono::high_resolution_clock::now();
    cout << "Search for 10: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    arr.deleteAtEnd();
    end = chrono::high_resolution_clock::now();
    cout << "Deletion at end: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    arr.deleteAtBeginning();
    end = chrono::high_resolution_clock::now();
    cout << "Deletion at beginning: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    arr.display();

    auto total_end = chrono::high_resolution_clock::now();
    cout << "Total time for all operations: " << chrono::duration_cast<chrono::nanoseconds>(total_end - total_start).count() << " ns" << endl;

    return 0;
}
