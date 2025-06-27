#include <iostream>
using namespace std;

int main()
{
    cout<<sizeof(int)<<endl;
    cout<<sizeof(char)<<endl;
    cout<<sizeof(float)<<endl;
    cout<<sizeof(double)<<endl;
    cout<<sizeof(long)<<endl;
    int x;
    int count=0;
    cout<<"Enter value: "<<endl;
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        if(x%i==0)
        {
            count++;
        }
        
    }
    if(count>2)
    {
        cout<<x<<" is not a prime number."<<endl;
    }
    else
    {
        cout<<x<<" is a prime number."<<endl;
    }
}