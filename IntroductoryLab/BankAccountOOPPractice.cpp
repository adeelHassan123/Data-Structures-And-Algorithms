// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[]={11,2,3,4,7};
//     int* ptr=arr;
//     int size=sizeof(arr)/sizeof(arr[0]);

//     for (int i =1;i<=size;i++)
//     {
//         cout<< *ptr <<" ";
//         ptr++;
//     }
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     // int x[4] = { 0, 4, 6, 9 };
//     // int *p, a = 3;
//     // p = x;
//     // (*p)++;
//     // cout << *p << endl;
//     // cout << *(p + 1) << endl;
//     // p++;
//     // *p = *p + a;
//     // cout << *p << endl;
//     // p = p + 2;
//     // cout << *p << endl;
//     int *ptr=nullptr;
//     cout<<*ptr;
// }
#include <iostream>
#include <string>
using namespace std;

// Base class Account
class Account {
protected:
    int accountNumber;
    double balance;
    string customerName;

public:
    // Constructor
    Account(int accNum, double bal, string name)
        : accountNumber(accNum), balance(bal), customerName(name) {}

    // Virtual destructor
    virtual ~Account() {
        cout << "Account object destroyed." << endl;
    }

    // Pure virtual methods
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    // Display account details
    void displayInfo() const {
        cout << "Account Number: " << accountNumber
             << "\nCustomer Name: " << customerName
             << "\nBalance: " << balance << endl;
    }

    // Comparison operators
    bool operator>(const Account &other) const {
        return balance > other.balance;
    }

    bool operator<(const Account &other) const {
        return balance < other.balance;
    }

    bool operator==(const Account &other) const {
        return balance == other.balance;
    }
};

// Derived class SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;
    static const double MIN_BALANCE;

public:
    SavingsAccount(int accNum, double bal, string name, double rate)
        : Account(accNum, bal, name), interestRate(rate) {}

    void deposit(double amount) override {
        balance += amount + (amount * interestRate);
    }

    void withdraw(double amount) override {
        if (balance - amount >= MIN_BALANCE) {
            balance -= amount;
        } else {
            cout << "Insufficient balance! Minimum balance: " << MIN_BALANCE << endl;
        }
    }
};
const double SavingsAccount::MIN_BALANCE = 100.0;

// Derived class CheckingAccount
class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, string name, double overdraft)
        : Account(accNum, bal, name), overdraftLimit(overdraft) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
        } else {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }
};

// Derived class InvestmentAccount
class InvestmentAccount : public Account {
private:
    int investmentDuration;
    double riskFactor;

public:
    InvestmentAccount(int accNum, double bal, string name, int duration, double risk)
        : Account(accNum, bal, name), investmentDuration(duration), riskFactor(risk) {}

    void deposit(double amount) override {
        balance += amount * (1 + riskFactor);
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount * (1 - riskFactor);
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

// Main function
int main() {
    // Create accounts
    SavingsAccount savAcc(1001, 500.0, "Alice", 0.03);
    CheckingAccount chkAcc(1002, 200.0, "Bob", 100.0);
    InvestmentAccount invAcc(1003, 1000.0, "Charlie", 5, 0.05);

    // Perform operations
    savAcc.deposit(100);
    savAcc.withdraw(50);
    savAcc.displayInfo();

    chkAcc.deposit(200);
    chkAcc.withdraw(350);
    chkAcc.displayInfo();

    invAcc.deposit(300);
    invAcc.withdraw(500);
    invAcc.displayInfo();

    // Compare balances
    if (savAcc > chkAcc) {
        cout << "Savings account has more balance than checking account." << endl;
    } else {
        cout << "Checking account has more or equal balance." << endl;
    }

    if (chkAcc == invAcc) {
        cout << "Checking and investment accounts have the same balance." << endl;
    } else {
        cout << "Checking and investment accounts have different balances." << endl;
    }

    // Display details using polymorphism
    Account *accounts[] = {&savAcc, &chkAcc, &invAcc};
    cout << "\nAll accounts details:" << endl;
    for (Account *acc : accounts) {
        acc->displayInfo();
    }

    return 0;
}
