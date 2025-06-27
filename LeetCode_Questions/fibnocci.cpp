#include<iostream>
using namespace std;
int sum(int a,int b)
{
    return a + b;
}
void fibnoci(int a)
{
    int prev=0;
    int next=1;
    int x=sum(prev,next);
    while(a>0)
    {
        cout<<prev<<endl;
        prev=next;
        next=x;
        a--;
    }
}

int main(){
    fibnoci(10);
}
