#include<iostream>
using namespace std;

void TripleSum(int a[], int size, int S)
{
    cout << "Pairs with sum " << S << " are:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) { 
            for (int k = j + 1; k < size; k++){ 
                if (a[i] + a[j] + a[k] == S) {
                    cout << a[i] << " " << a[j] <<" " <<a[k]<< endl;
                }
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

    cout << "Enter S (sum) for which triplets need to be found: " << endl;
    cin >> S;

    int size = sizeof(y) / sizeof(y[0]);

    TripleSum(y, size, S);

    return 0;
}
