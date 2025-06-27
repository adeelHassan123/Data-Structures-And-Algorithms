#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& arr, size_t size) {
    int count=0;
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1-i; j++) {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
                count++;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
    cout<<"count= "<<count<<endl;
}

int main() {
    vector<int> arr = {11,12,9, 3,1};
    size_t size = arr.size();

    BubbleSort(arr, size);

    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
