#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char key[] = "horses";
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int keyLength = strlen(key);
    int alphalength=strlen(alpha);

    char matrix[5][5]={"\0"};
    char used[26]={true};
    used['j'-'a']= {false};
    int row =0;
    int colm=0;

    for (int j = 0; j < keyLength; j++)
    {
        char c = key[j];
        if(c='j') 
        {
            c='i';
        }
        if(used[c-'a'])
        {
            matrix[row][colm++]=c;
            used[c-'a']=false;
            if(colm==5)
            {
                colm=0;
                row++;
            }
        }
    }
    
    for (int a = 0; a < alphalength; a++) {
        if (!used[a]) {
            matrix[row][colm++] = alpha[a];
            if (colm == 5) {
                colm = 0;
                row++;
            }
        }
    }
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
  /* char key[] = "horses";
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int keyLength = strlen(key);
    int alphalength=strlen(alpha);

    for(int i=0;i<keyLength;i++)
    {
        for(int j=0;j<alphalength;j++)
        {
            if(key[i]==alpha[j])
            {
                cout<<alpha[j]<<" ";
                alpha[j]=0;
                break;
            }
        }
    }
    for(int j=0;j<alphalength;j++)
        {
            if(alpha[j]!=0)
            {
                 cout<<alpha[j]<<" ";

            }
        }*/
   



    return 0;
}
