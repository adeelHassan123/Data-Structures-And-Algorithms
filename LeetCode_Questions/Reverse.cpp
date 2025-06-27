#include<iostream>
using namespace std;
class reverse_number{
    public:
     int x,a,b,c;
     reverse_number(int a)
     {
        x=a; 
     }
     int rev()
     {
        int reversed = 0;
            int num = x; 
            while (num != 0) {
                int digit = num % 10;
                if(reversed<INT_MAX && reversed >INT_MIN)
                {
                    reversed = reversed * 10 + digit;
                }
                num /= 10;
            }
            return reversed;
     }
};
class reverse_array
{
    public:
    
    void rev(int a[], int size)
    {
        for (int i = 0; i < size / 2; i++)
        {
            int temp = a[i];
            a[i] = a[size - 1 - i];
            a[size - 1 - i] = temp;
        }
    }
};
int main()
{
    /*int x;
    cin>>x;
    reverse_number r1(x);
    cout<<r1.rev();*/

    int y[10]={2,4,-8,-1,0,5,11,0,1};
    reverse_array r;
    r.rev(y,10);
        for(int i=0;i<10;i++)
        {
           cout<<y[i]<<endl;
        }
}