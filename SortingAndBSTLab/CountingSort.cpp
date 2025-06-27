#include <iostream>
using namespace std;

void countingsort(int arr[],int r,int n)
{
    int array[r]={0};
    for(int i =0;i<n;i++)
    {
        array[arr[i]]++;
    }

    int j=0;
    for(int i=0;i<r;i++)
    {
        while(array[i]>0)
        {
            arr[j]=i;
            j++;
            array[i]--;
        }
    }

}
int maxi(int arr[],int n)
{
    int max=arr[0];
    for (int i =1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}


int main()
{
    int arr[]={2,1,2,3,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    int max= maxi(arr,n);

    cout << "Before sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingsort(arr, max+1, n);

    cout << "After sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;



}