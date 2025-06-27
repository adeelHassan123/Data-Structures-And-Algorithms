#include <iostream>
#include <chrono>  

using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    
    while(1)
    {
    int x;
    cout<<endl;
    cout << "Enter value of N: " ;
    cin >> x;
    auto start = chrono::high_resolution_clock::now();

    cout<<"Finocci series: " ;
    for(int i=0;i<x;i++)
    {
        cout<<fibonacci(i)<< " ";
    }

    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = end - start;

    cout <<endl<< "Time: " << duration.count() << " ms" << endl;

    }

    

    return 0;
}
