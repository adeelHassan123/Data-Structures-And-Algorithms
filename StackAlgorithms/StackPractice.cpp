#include <iostream>
using namespace std;
const int MAX = 5;
class queue{
    private:
    int front=0;
    int rear=-1;
    int dataArr[MAX];

    public:
    void enqueue(int data)
    {
        rear = (rear + 1) % MAX;
        dataArr[rear++]=data;
    }

};

int main()
{

}