#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

class Sort {
public:
    void quickSort(vector<int>& arr, int left, int right);
    void countingSort(vector<int>& arr);
    void printArray(const vector<int>& arr, int limit = 10);

private:
    int partition(vector<int>& arr, int left, int right);
    int randomizedPartition(vector<int>& arr, int left, int right);
};

// Quick Sort Implementation
void Sort::quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = randomizedPartition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int Sort::randomizedPartition(vector<int>& arr, int left, int right) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(left, right);
    
    int pivotIndex = dist(gen);
    swap(arr[pivotIndex], arr[right]);
    return partition(arr, left, right);
}

int Sort::partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void Sort::countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxValue = *max_element(arr.begin(), arr.end());
    int minValue = *min_element(arr.begin(), arr.end());
    int range = maxValue - minValue + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    for (int num : arr) count[num - minValue]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minValue] - 1] = arr[i];
        count[arr[i] - minValue]--;
    }
    arr = move(output);
}

void Sort::printArray(const vector<int>& arr, int limit) {
    for (int i = 0; i < min(limit, (int)arr.size()); i++) cout << arr[i] << " ";
    if (arr.size() > limit) cout << "... ";
    cout << endl;
}

void generateRandomArray(vector<int>& arr, int size) {
    arr.resize(size);
    generate_n(arr.begin(), size, []() { return rand() % 100 + 1; });
}

void testSortingAlgorithms(Sort& sorter, const vector<int>& sizes) {
    for (int size : sizes) {
        vector<int> arr;
        generateRandomArray(arr, size);

        cout << "\nArray Size: " << size << endl;

        vector<int> copy1 = arr, copy2 = arr;

        auto start = chrono::high_resolution_clock::now();
        sorter.quickSort(copy1, 0, copy1.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Quick Sort: " << duration << " microseconds" << endl;

        start = chrono::high_resolution_clock::now();
        sorter.countingSort(copy2);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Counting Sort: " << duration << " microseconds" << endl;
    }
}

// Task 3: Testing Best and Worst Case Complexity
void testBestWorstCases(Sort& sorter, const vector<int>& sizes) {
    for (int size : sizes) {
        vector<int> arr;
        generateRandomArray(arr, size);

        vector<int> ascending = arr;
        sort(ascending.begin(), ascending.end());

        vector<int> descending = arr;
        sort(descending.rbegin(), descending.rend());

        cout << "\nArray Size: " << size << endl;

        // Quick Sort Best/Worst Case
        auto start = chrono::high_resolution_clock::now();
        sorter.quickSort(ascending, 0, ascending.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Quick Sort (Ascending): " << duration << " microseconds" << endl;

        start = chrono::high_resolution_clock::now();
        sorter.quickSort(descending, 0, descending.size() - 1);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Quick Sort (Descending): " << duration << " microseconds" << endl;

        // Counting Sort Best/Worst Case
        start = chrono::high_resolution_clock::now();
        sorter.countingSort(ascending);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Counting Sort (Ascending): " << duration << " microseconds" << endl;

        start = chrono::high_resolution_clock::now();
        sorter.countingSort(descending);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "Counting Sort (Descending): " << duration << " microseconds" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Sort sorter;
    vector<int> sizes = { 100, 1000, 10000, 100000 };

    cout << "Task 1: Implement Quick Sort and Counting Sort\n";
    vector<int> exampleArr = { 64, 25, 12, 22, 11 };
    cout << "Original Array: ";
    sorter.printArray(exampleArr);

    // Quick Sort
    sorter.quickSort(exampleArr, 0, exampleArr.size() - 1);
    cout << "Array after Quick Sort: ";
    sorter.printArray(exampleArr);

    // Counting Sort
    exampleArr = { 64, 25, 12, 22, 11 };
    sorter.countingSort(exampleArr);
    cout << "Array after Counting Sort: ";
    sorter.printArray(exampleArr);

    cout << "\nTask 2: Average Case Complexity\n";
    testSortingAlgorithms(sorter, sizes);

    cout << "\nTask 3: Best and Worst Case Complexity\n";
    testBestWorstCases(sorter, sizes);

    return 0;
}
