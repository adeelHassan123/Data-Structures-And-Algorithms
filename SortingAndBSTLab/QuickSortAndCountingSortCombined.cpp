// #include <iostream>
// using namespace std;

// int partition(int l, int h, int arr[]) {
//     int pivot = arr[l];
//     int i = l;
//     int j = h;

//     while (i < j) {
//         do { i++; } while (arr[i] <= pivot && i <= h);
//         do { j--; } while (arr[j] > pivot && j >= l);
//         if (i < j) swap(arr[i], arr[j]);
//     }
//     swap(arr[l], arr[j]);
//     return j; 
// }

// void quicksort(int arr[], int l, int h) {
//     if (l < h) {
//         int j = partition(l, h, arr);
//         quicksort(arr, l, j - 1);  
//         quicksort(arr, j + 1, h);  
//     }
// }

// void countingsort(int arr[],int r,int n)
// {
//     int array[r]={0};
//     for(int i =0;i<n;i++)
//     {
//         array[arr[i]]++;
//     }

//     int j=0;
//     for(int i=0;i<r;i++)
//     {
//         while(array[i]>0)
//         {
//             arr[j]=i;
//             j++;
//             array[i]--;
//         }
//     }

// }
// int maxi(int arr[],int n)
// {
//     int max=arr[0];
//     for (int i =1;i<n;i++)
//     {
//         if(arr[i]>max)
//         {
//             max=arr[i];
//         }
//     }
//     return max;
// }

// void printArray(int arr[], int limit) {
//     for (int i = 0; i < min(limit, (int)arr.size()); i++) cout << arr[i] << " ";
//     if (arr.size() > limit) cout << "... ";
//     cout << endl;
// }

// void generateRandomArray(vector<int>& arr, int size) {
//     arr.resize(size);
//     generate_n(arr.begin(), size, []() { return rand() % 100 + 1; });
// }

// void testSortingAlgorithms(Sort& sorter, const vector<int>& sizes) {
//     for (int size : sizes) {
//         vector<int> arr;
//         generateRandomArray(arr, size);

//         cout << "\nArray Size: " << size << endl;

//         vector<int> copy1 = arr, copy2 = arr;

//         auto start = chrono::high_resolution_clock::now();
//         sorter.quickSort(copy1, 0, copy1.size() - 1);
//         auto end = chrono::high_resolution_clock::now();
//         auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
//         cout << "Quick Sort: " << duration << " microseconds" << endl;

//         start = chrono::high_resolution_clock::now();
//         sorter.countingSort(copy2);
//         end = chrono::high_resolution_clock::now();
//         duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
//         cout << "Counting Sort: " << duration << " microseconds" << endl;
//     }
// }


// int main()
// {
//     int arr[]={2,1,2,3,1,4};
//     int n = sizeof(arr) / sizeof(arr[0]);

    
//     int max= maxi(arr,n);

//     cout << "Before sort:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     countingsort(arr, max+1, n);

//     cout << "After sort:" << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;



// }