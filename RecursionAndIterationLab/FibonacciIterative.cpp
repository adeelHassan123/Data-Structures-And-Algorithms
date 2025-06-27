#include <iostream>
#include <chrono>  

using namespace std;

int sum(int a, int b) {
    return a + b;
}

void fibonacci(int a) {
    int prev = 0;
    int next = 1;

    cout<<endl<<"Fibioncci series"<<endl;
    
    while (a > 0) {
        cout << prev << " ";
        int x = sum(prev, next); 
        prev = next;
        next = x;
        a--;
    }
}

int main() {
    
    while(1)
    {
    int x;
    cout <<endl<< "Enter value of N: ";
    cin >> x;
    auto start = chrono::high_resolution_clock::now();


    fibonacci(x);

    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = end - start;

    cout << "Time: " << duration.count() << " ms" << endl;
    }

    return 0;
}
