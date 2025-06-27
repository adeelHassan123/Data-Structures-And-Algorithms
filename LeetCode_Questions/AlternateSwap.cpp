#include <iostream>
using namespace std;

void swap(int a[],int size)
{
    if(size%2==0?size=size:size-=1)
    {
    for(int i=0;i<size;i+=2)
    {
        int temp=a[i+1];
        a[i+1]=a[i];
        a[i]=temp;   
    }
    }
}

int main(){
    int x[5]={2,8,20,0,1};
    swap(x,5);
    for(int i=0;i<5;i++)
    {
        cout<<x[i]<<endl;
    }
    
}

