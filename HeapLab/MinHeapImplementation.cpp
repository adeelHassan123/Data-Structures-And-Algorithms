#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        if (index == 1) return; 
        int parent = index / 2;
        if (heap[index] < heap[parent]) {
            std::swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index, right = 2 * index + 1, smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {
        heap.push_back(-1); 
    }

    bool isEmpty() const {
        return heap.size() == 1;
    }

    int size() const {
        return heap.size() - 1; 
    }

    int height() const {
        if (isEmpty()) return 0;
        return std::ceil(std::log2(size() + 1)) - 1;
    }

    int Top() const {
        if (isEmpty()) throw std::runtime_error("Heap is empty");
        return heap[1];
    }

    void Pop() {
        if (isEmpty()) throw std::runtime_error("Heap is empty");
        heap[1] = heap.back();
        heap.pop_back();  
        heapifyDown(1);    
    }

    void Push(int value) {
        heap.push_back(value); 
        heapifyUp(heap.size() - 1); 
    }

    void buildHeap(const std::vector<int>& array) {
        heap = { -1 }; 
        for (int value : array) {
            Push(value); 
        }
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        for (size_t i = 1; i < heap.size(); ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap heap;
    heap.Push(11);
    heap.Push(21);
    heap.Push(6);
    heap.Push(16);

    std::cout << "Elements of the Heap : ";
    heap.print();

    std::cout << "Top Element: " << heap.Top() << std::endl;
    std::cout << "Size of Heap: " << heap.size() << std::endl;
    std::cout << "Height of Heap: " << heap.height() << std::endl;

    heap.Pop();
    std::cout << "Heap after Pop: ";
    heap.print();

    std::vector<int> array = { 8, 13, 2, 4, 9, 11 };
    heap.buildHeap(array);
    std::cout << "Heap after buildHeap: ";
    heap.print();

    return 0;
}
