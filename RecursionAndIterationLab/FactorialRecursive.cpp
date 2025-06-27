#include <iostream>
#include <chrono>  
using namespace std;
using namespace::chrono;

unsigned long long fact(int a) {
    if (a == 0 || a == 1)
        return 1;
    else
        return a * fact(a - 1);
}

int main() {
    while (1) {
        int x;
        cout << endl << "Enter value of N: ";
        cin >> x;

        auto start = high_resolution_clock::now();

        unsigned long long result = fact(x);

        auto end = high_resolution_clock::now();

        duration<double, milli> long_ii = end - start;

        cout << "Factorial: " << result << endl;
        cout << "Time: " << long_ii.count() << " ms" << endl;
    }

    return 0;
}   
