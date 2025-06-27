#include <iostream>
#include <vector>
using namespace std;

size_t findMinIndex(vector<int>& arr, size_t start, size_t size) {
    size_t index = start;
    for (size_t i = start + 1; i < size; i++) {
        if (arr[i] < arr[index]) {
            index = i;
        }
    }
    return index;
}

void SelectionSort(vector<int>& arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t mini_index = findMinIndex(arr, i, size);

        int temp = arr[i];
        arr[i] = arr[mini_index];
        arr[mini_index] = temp;
    }
}

int main() {
    vector<int> arr = {11, 5, 3};
    size_t size = arr.size();

    SelectionSort(arr, size);

    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
