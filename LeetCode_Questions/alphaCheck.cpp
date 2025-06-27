#include <iostream>
using namespace std;

int main()
{ char x;
  cout<<"ENTER ANY LETTER: ";
    cin>>x;
    if(isupper(x) && isalpha(x))
    {
        cout<<"upper";
    }
    else if(islower(x) && isalpha(x))
    {
        cout<<"lower";
    }
    else if(!(isalpha(x)))
    {
        cout<<"not alpha";
    }
}