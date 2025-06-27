#include <iostream>
using namespace std;

class stack{
    private:
    int top=-1;
    // int count=0;
    int dataArr[10];

    public:
    void push(int data)
    {
        dataArr[++top]=data;
    }
    int pop()
    {
        if(isempty())
        {
            cout<<"empty"<<endl;
        }
        return dataArr[top--];
        // top--;
    }
    bool isempty()
    {
        return top<0;
    }
};

int main()
{
    stack* s=new stack();
    s->push(5);
    s->push(6);
    s->push(7);
    cout<<s->pop()<<endl;
}