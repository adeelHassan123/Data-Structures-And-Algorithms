#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high, int threshold, int strategy, int& comparisons) {
    if (high - low <= threshold) {
        insertionSort(arr, low, high, comparisons);
        return;
    }

    if (low < high) {
        int pivotIndex = partition(arr, low, high, strategy, comparisons);
        quickSort(arr, low, pivotIndex - 1, threshold, strategy, comparisons);
        quickSort(arr, pivotIndex + 1, high, threshold, strategy, comparisons);
    }
}
// Function to perform Insertion Sort
void insertionSort(vector<int>& arr, int low, int high, int& comparisons) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
}

// Function to choose pivot using different strategies
int choosePivot(const vector<int>& arr, int low, int high, int strategy) {
    switch (strategy) {
        case 1: // First element as pivot
            return low;
        case 2: // Last element as pivot
            return high;
        case 3: { // Median-of-three strategy
            int mid = low + (high - low) / 2;
            vector<int> candidates = {arr[low], arr[mid], arr[high]};
            sort(candidates.begin(), candidates.end());
            if (candidates[1] == arr[low]) return low;
            else if (candidates[1] == arr[mid]) return mid;
            else return high;
        }
        default: // Default to first element
            return low;
    }
}

// Partition function
int partition(vector<int>& arr, int low, int high, int strategy, int& comparisons) {
    int pivotIndex = choosePivot(arr, low, high, strategy);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); // Move pivot to end
    int storeIndex = low;

    for (int i = low; i < high; i++) {
        comparisons++;
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[high]); // Move pivot to its final place
    return storeIndex;
}

int main() {
    while (true) {
        cout << "\n=============================================\n";
        int n;
        cout << "Enter the number of elements in the array (or -1 to exit): ";
        cin >> n;

        if (n == -1) break; // Exit option
        if (n <= 0) {
            cout << "Array size must be greater than zero.\n";
            continue;
        }

        vector<int> arr(n);

        if (n <= 10) {
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
        } else {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_int_distribution<int> distribution(1, 100);
            for (int i = 0; i < n; i++) {
                arr[i] = distribution(generator);
            }
        }

        cout << "=============================================\n";

        int strategy;
        cout << "Choose pivot strategy:\n1. First element\n2. Last element\n3. Median-of-three\n";
        cin >> strategy;

        if (strategy < 1 || strategy > 3) {
            cout << "Invalid strategy. Defaulting to first element.\n";
            strategy = 1;
        }

        cout << "=============================================\n";

        int threshold;
        cout << "Enter threshold for Insertion Sort (default is 5): ";
        cin >> threshold;

        if (threshold < 1) {
            cout << "Threshold must be at least 1. Defaulting to 5.\n";
            threshold = 5;
        }

        cout << "=============================================\n";

        int comparisons = 0;
        quickSort(arr, 0, n - 1, threshold, strategy, comparisons);

        cout << "Sorted array: ";
        for (int num : arr) {
            cout << num << " ";
        }

        cout << "\nTotal comparisons made: " << comparisons << endl;

        char choice;
        cout << "Do you want to sort another array? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;
    }

    cout << "Exiting program.\n";
    return 0;
}
