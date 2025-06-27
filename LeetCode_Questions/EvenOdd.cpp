#include <iostream>
using namespace std;

class person{
    public:
    virtual void speak();
    
};

class boy: public person{
    public:
    void study()
    {
        cout<<"studying";

    }
    void speak() 
    {
        cout<<"speaking";
    }
};

int main() {
    boy b1;
    
    b1.study();
    
    return 0;
}  