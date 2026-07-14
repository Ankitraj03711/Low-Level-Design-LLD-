class car{
    //variable-character
    //Methods-Behaviour
}
// we put the all variables and methods in a object and we call it class . and it is a blueprint 

// their are somthing in variable we can not acess from it outside 


// From here we can get the contact of Acess Modifiers


// Access Modifiers
1.public: if we declare any variable or methods as public 
we can acess from anywhere.

2.private: if we declare any varible or methods as a 
private we can not acess from outside .

3.protected:we can not use from outside but 
the child class can use it.



#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:// we do it because we can not anyone can change 
it.
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Deposit Money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited ₹" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw Money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn ₹" << amount << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    // Getter
    double getBalance() {
        return balance;
    }

    // Getter
    string getAccountHolder() {
        return accountHolder;
    }

    // Display Details
    void displayAccount() {
        cout << "\nAccount Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : ₹" << balance << endl;
    }
};

int main() {

    BankAccount account("Ankit Raj", 123456789, 10000);

    account.displayAccount();

    cout << "\nDepositing Money...\n";
    account.deposit(5000);

    cout << "\nWithdrawing Money...\n";
    account.withdraw(3000);

    cout << "\nCurrent Balance: ₹" << account.getBalance() << endl;

    // ❌ Not Allowed (Private Members)
    // account.balance = 50000;
    // account.accountNumber = 111111;

    return 0;
}
