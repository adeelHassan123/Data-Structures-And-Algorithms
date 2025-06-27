#include <iostream>
using namespace std;

bool uniqueOccurrences(int a[], int size)
{
    int freq[size] = {0};  
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (a[i] == a[j] && a[i]!=char(120)) {
                freq[i]++;
                a[j]==char(120);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        int count=0;
        for (int j = i + 1; j < size; j++) {
            if (freq[i] == freq[j] && freq[i] != 0 && count>1) {
                return false;  
            }
            count++;
        }
    }
    return true;
}

int main()
{
    int a[] = {2, 4,3, 2, 3, 2};  
    int size = sizeof(a) / sizeof(a[0]);

    bool isUnique = uniqueOccurrences(a, size);  
    
    cout << "Unique occurrences: " << (isUnique ? "Yes" : "No") << endl;

    return 0;
}
