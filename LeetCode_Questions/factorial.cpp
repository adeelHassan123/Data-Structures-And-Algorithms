#include <iostream>
using namespace std;
int fact(int a)
{
    int factorial=1;
    while(a>0)
    {
        factorial *= a;
        a--;
    }
    return factorial;
}
int nCr(int n,int r)
{
    int numerator = fact(n);
    int denumerator=fact(r)*fact(n-r);
    return numerator/denumerator;
}
int main()
{
 cout<<"nCr is: "<<nCr(8,2);   
}