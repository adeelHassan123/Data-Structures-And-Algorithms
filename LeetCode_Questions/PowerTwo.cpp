#include<iostream>
using namespace std;

class pow_two
{
    public:
    
    bool check(int a)
    {
        bool val;
        while(a>1)
        {
            int num=a%2;
            if(num==0)
            {
                val=true;
            }
            else{
                return false;
            }
            a/=2;
        }
        return val;
    }
};

int main(){
    while(1)
    {
    int x;
    cout<<"Enter value: ";
    cin>>x;
    pow_two p;
    cout<<"value can be: "<< p.check(x)<<endl;
    }
}