#include <iostream>
#include <chrono>  
using namespace std;

int unique(int a[], int size)
{
    int value;   
    for(int i=0; i<size; i++)
    {
        int count = 0;
        for(int j=0; j<size; j++)
        {
            if(a[i] == a[j])
                count++;   
        }
        if(count == 1)
        {   
            value = a[i];
            break;
        }
    }
    return value;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int a[] = {8, 9, 7, 8, 7, 9, 14, 1, 3, 5, 3, 5, 1};
    int size = sizeof(a)/sizeof(a[0]); 

   

    int x = unique(a, size);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;

    cout << "Unique value is: " << x << endl;
    cout << "Time taken by function: " << duration.count() << " seconds" << endl;

    return 0;
}
