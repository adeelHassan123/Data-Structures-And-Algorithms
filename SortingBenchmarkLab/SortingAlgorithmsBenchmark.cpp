#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Sort {
public:
    void bubbleSort(vector<int>& arr);
    void selectionSort(vector<int>& arr);
    void insertionSort(vector<int>& arr);
    void mergeSort(vector<int>& arr, int left, int right);
    void merge(vector<int>& arr, int left, int mid, int right);

    void printArray(const vector<int>& arr);
};

// Bubble Sort
void Sort::bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void Sort::selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void Sort::insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void Sort::merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void Sort::mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void Sort::printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

void generateRandomArray(vector<int>& arr, int size) {
    arr.resize(size);
    for (int& num : arr) num = rand() % 100 + 1; // Random numbers between 1 and 100
}

void testSortingAlgorithms(Sort& sorter, const vector<int>& sizes) {
    for (int size : sizes) {
        vector<int> arr;
        generateRandomArray(arr, size);

        cout << "\nArray Size: " << size << endl;

        vector<int> copy1 = arr, copy2 = arr, copy3 = arr, copy4 = arr;

        // Bubble Sort
        clock_t start = clock();
        sorter.bubbleSort(copy1);
        clock_t end = clock();
        cout << "Bubble Sort: " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        // Selection Sort
        start = clock();
        sorter.selectionSort(copy2);
        end = clock();
        cout << "Selection Sort: " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        // Insertion Sort
        start = clock();
        sorter.insertionSort(copy3);
        end = clock();
        cout << "Insertion Sort: " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        // Merge Sort
        start = clock();
        sorter.mergeSort(copy4, 0, size - 1);
        end = clock();
        cout << "Merge Sort: " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;
    }
}


void testBestWorstCases(Sort& sorter, const vector<int>& sizes) {
    for (int size : sizes) {
        vector<int> arr;
        generateRandomArray(arr, size);

        vector<int> ascending = arr;
        sort(ascending.begin(), ascending.end());

        vector<int> descending = arr;
        sort(descending.rbegin(), descending.rend());

        cout << "\nArray Size: " << size << endl;

        // Bubble Sort Best/Worst Case
        clock_t start = clock();
        sorter.bubbleSort(ascending);
        clock_t end = clock();
        cout << "Bubble Sort (Ascending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        start = clock();
        sorter.bubbleSort(descending);
        end = clock();
        cout << "Bubble Sort (Descending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        // Selection Sort Best/Worst Case
        start = clock();
        sorter.selectionSort(ascending);
        end = clock();
        cout << "Selection Sort (Ascending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        start = clock();
        sorter.selectionSort(descending);
        end = clock();
        cout << "Selection Sort (Descending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        // Insertion Sort Best/Worst Case
        start = clock();
        sorter.insertionSort(ascending);
        end = clock();
        cout << "Insertion Sort (Ascending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        start = clock();
        sorter.insertionSort(descending);
        end = clock();
        cout << "Insertion Sort (Descending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        // Merge Sort Best/Worst Case
        start = clock();
        sorter.mergeSort(ascending, 0, ascending.size() - 1);
        end = clock();
        cout << "Merge Sort (Ascending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;

        start = clock();
        sorter.mergeSort(descending, 0, descending.size() - 1);
        end = clock();
        cout << "Merge Sort (Descending): " << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;
    }
}



int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random numbers

    Sort sorter;
    vector<int> arr1 = { 64, 34, 25, 12, 22, 11, 90 };
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;
    vector<int> arr4 = arr1;

    cout << "Task 1\n\n";

    cout << "Original Array: ";
    sorter.printArray(arr1);

    // Bubble Sort
    sorter.bubbleSort(arr1);
    cout << "Bubble Sorted Array: ";
    sorter.printArray(arr1);

    // Selection Sort
    sorter.selectionSort(arr2);
    cout << "Selection Sorted Array: ";
    sorter.printArray(arr2);

    // Insertion Sort
    sorter.insertionSort(arr3);
    cout << "Insertion Sorted Array: ";
    sorter.printArray(arr3);

    // Merge Sort
    sorter.mergeSort(arr4, 0, arr4.size() - 1);
    cout << "Merge Sorted Array: ";
    sorter.printArray(arr4);

    vector<int> sizes = { 100, 1000, 10000 };

    cout << "\nTask 2: Average Case Complexity\n";
    testSortingAlgorithms(sorter, sizes);

    cout << "\nTask 3: Best and Worst Case Complexity\n";
    testBestWorstCases(sorter, sizes);

    return 0;
}
