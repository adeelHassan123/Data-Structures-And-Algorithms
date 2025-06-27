#include<iostream>
using namespace std;

void Sort(int a[], int a_size)
{
    int count=0;
    int temp[a_size];
    for (int i = 0; i < a_size; i++) {
        temp[i]=a[i];
    }
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < a_size; j++) { 
            if(temp[j]==0)
            {
                a[count]=0;
                count++;
            }
        }
        for (int j = 0; j < a_size; j++) { 
            if(temp[j]==1)
            {
                a[count]=1;
                count++;
            }
        }
        for (int j = 0; j < a_size; j++) { 
            if(temp[j]==2)
            {
                a[count]=2;
                count++;
            }
        }
    }
}

int main() {
    int y[5];

    cout << "Enter 5 array numbers:" << endl;
    for (int i = 0; i < 5; i++) {
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
