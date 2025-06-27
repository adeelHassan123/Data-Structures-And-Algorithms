#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char key[] = "horses";
    char record[26] = ""; 
    int index = 0;

    for (int i = 0; i < strlen(key); i++)
    {
        int count = 0;
        for (int j = 0; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                count++;
            }
        }
        
        if (count > 1 && strchr(record, key[i]) == nullptr) 
        {
            record[index++] = key[i]; 
        }
    }

    cout << "REPEATED CHARS ARE: ";
    for (int i = 0; i < index; i++) 
    {
        cout << record[i] << " ";
    }
    cout << endl;

    return 0;
}
