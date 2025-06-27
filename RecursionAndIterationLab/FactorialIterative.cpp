// #include <iostream>
// #include <chrono>  
// using namespace std;
// using namespace::chrono;

// unsigned long long fact(int a) {
//     unsigned long long factorial = 1;  
//     while(a > 0) {
//         factorial *= a;
//         a--;
//     }
//     return factorial;
// }

// int main() {
//     while(1) {
//         int x;
//         cout << endl << "Enter value of N: ";
//         cin >> x;

//         auto start = chrono::high_resolution_clock::now();

//         unsigned long long result = fact(x);

//         auto end = chrono::high_resolution_clock::now();

//         duration<double, std::milli> long_ii=end-start;
//         cout << "Factorial: " << result << endl;
//         cout << "Time: " << long_ii.count() << " ms" << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <chrono>
using namespace std;
using namespace::chrono;

unsigned long long fact(unsigned long long a)
{
    unsigned long long factoo=1;
    while(a>0)
    {
        factoo*=a;
        a--;
    }
    return factoo;

}
int main()
{
    unsigned long long a;
    cout<<"PLease enter a number"<<endl;
    cin>>a;
    auto start= chrono::high_resolution_clock::now();

    cout<<"Factorial of given number is : "<< fact(a)<<endl;
    
    auto end= chrono::high_resolution_clock::now();

    duration<double,std::milli> timing=end-start;

    cout<<" Time taken is : "<<timing.count()<<endl;




}