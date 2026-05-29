// Class Account

# ifndef ACCOUNT_H
# define ACCOUNT_H

# include <iostream>

using namespace std;

class Account {
    protected:

    // Attributes
    float balance;
    int accountNumber;

    public:
    // Empty constructor
    Account(): balance(0.0), accountNumber(0) {}

    // Default constructor
    Account(float bal, int accNum): balance(bal), accountNumber(accNum) {}

    // Methods

    virtual float withdraw(float amount){
        if (balance > 0 and amount <= balance){
            return balance -= amount;
        }
        else {
            cout << "Insufficient balance" << endl;
            return balance;
        }
    }

     virtual float deposit(float amount){
        return balance += amount;
    }

    virtual float getBalance(){
        return balance;
    }
};

# endif