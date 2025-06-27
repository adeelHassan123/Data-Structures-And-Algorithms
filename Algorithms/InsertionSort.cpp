#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& arr, int k)
{
    arr.push_back(k);
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int count = i - 1;

        while (count >= 0 && arr[count] > temp) {
            arr[count + 1] = arr[count];
            count--;
        }
        arr[count + 1] = temp;
    }
}

int main()
{
    
    vector<int> arr = {10, 3, 19, 12}; 
    // InsertionSort(arr, k);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
