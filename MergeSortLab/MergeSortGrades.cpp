#include <iostream>
#include <vector>
using namespace std;

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    vector<int> L(n1), R(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Copy the remaining elements of L[] and R[]
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Helper function to print a vector
void printVector(const vector<int>& arr) {
    for (int grade : arr) {
        cout << grade << " ";
    }
    cout << endl;
}

int main() {
    // List of grades for courses
    vector<vector<int>> courseGrades = {
        {78, 85, 65, 90, 88, 76, 72, 84, 93, 67}, // OOP
        {70, 95, 60, 80, 85, 73, 68, 92, 81, 77}, // DSA
        {82, 76, 91, 68, 73, 86, 89, 95, 79, 74}  // DBMS
    };

    vector<int> mergedGrades;

    // Sort each course grades and merge them into a single list
    for (auto& grades : courseGrades) {
        mergeSort(grades, 0, grades.size() - 1);
        mergedGrades.insert(mergedGrades.end(), grades.begin(), grades.end());
    }

    // Sort the merged list
    mergeSort(mergedGrades, 0, mergedGrades.size() - 1);

    // Print the sorted grades
    cout << "Merged and Sorted Grades: ";
    printVector(mergedGrades);

    return 0;
}
