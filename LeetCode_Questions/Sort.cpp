#include<iostream>
using namespace std;

void Sort(int a[], int a_size)
{
    int count=0;
    for (int i = 0; i < a_size; i++) {
        /*for (int j = 0; j < a_size; j++) { 
            if(a[j]==0)
            {
                sorted[count]=0;
                count++;
            }
        }
        for (int j = 0; j < a_size; j++) { 
            if(a[j]==1)
            {
                sorted[count]=1;
                count++;
            }
        }*/

       for (int j = 0; j < a_size-1; j++) { 
            if(a[j]!=a[j+1] && a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
       }

    }
}

int main() {
    int y[6];

    cout << "Enter 6 array numbers:" << endl;
    for (int i = 0; i < 6; i++) {
        cin >> y[i];
    }

    int y_size = sizeof(y) / sizeof(y[0]);
    
    Sort(y, y_size);
    for (int j = 0; j < y_size; j++)
    {
        cout<<y[j]<<" ";
    }

    return 0;
}
