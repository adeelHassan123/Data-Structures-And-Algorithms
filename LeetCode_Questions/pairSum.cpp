#include<iostream>
using namespace std;

void pairSum(int a[], int size, int S)
{
    cout << "Pairs with sum " << S << " are:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {  
            if (a[i] + a[j] == S) {
                cout << a[i] << " " << a[j] << endl;
            }
        }
    }
}

int main() {
    int S;
    int y[5];

    cout << "Enter 5 array numbers:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> y[i];
    }

    cout << "Enter S (sum) for which pairs need to be found: " << endl;
    cin >> S;

    int size = sizeof(y) / sizeof(y[0]);

    pairSum(y, size, S);

    return 0;
}
