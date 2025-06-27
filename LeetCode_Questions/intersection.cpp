#include <iostream>
using namespace std;

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        bool isDuplicate = false;

        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) continue;

        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";  
                break;
            }
        }
    }
}

int main() {
    int arr1[] = {4, 9, 5};        
    int arr2[] = {9, 4, 9, 8, 4};  

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Intersection of the two arrays: ";
    findIntersection(arr1, size1, arr2, size2);

    return 0;
}
