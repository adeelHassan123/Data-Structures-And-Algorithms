#include <iostream>
using namespace std;

class complement {
public:
    
    int comp(int a) {
        int base = 1;
        int value = 0;
        int remainder;
        
        while (a > 0) {
            remainder = a % 10;
            remainder = (remainder == 0) ? 1 : 0;  
            value = value + (remainder * base);
            base *= 10;
            a /= 10;  
        }
        return value;
    }
};

class converter{
    public:
    int  Dec_Bin(int a)
    {
    int value=0;
    int x=1;
    while(a>0)
    {
        int num=a%2;
        value += (num*x);
        x*=10;
        a/=2;
    }
    return value;
}
int binaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;
    int remainder;

    while (binary > 0) {
        remainder = binary % 10;
        decimal = decimal + remainder * base;
        binary = binary / 10;
        base = base * 2;
    }
    return decimal;
}
};
int main()
{
    int x;
    cout<<"enter decimal number : ";
    cin>>x;
    converter c;
    int y= c.Dec_Bin(x);
    
    complement com;
    int z=com.comp(y);
    
    cout<<"Complement in dec "<< c.binaryToDecimal(z);

}