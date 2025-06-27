#include <iostream>
using namespace std;
class find_max{
    public:
    int find(int a[])
    {
        int max=a[0];
        for(int i=0;i<=10;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
        }
        return max;
    }

};

int main(){
    
    int a[10];
    cout<<"Enter 10 values: "<<endl;
    for(int i=0;i< 10;i++)
    {
        cin>>a[i];
    }
    find_max f;
    cout<<"Max value is: "<<f.find(a);
}