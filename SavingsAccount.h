// Class Savings Account

# ifndef SAVINGSACCOUNT_H
# define SAVINGSACCOUNT_H

# include <iostream>

using namespace std;

class SavingsAccount{

private:
    // Attributes
    float balance;
    float interestRate;
    int accountNumber;

public: 

    // Empty cosntructor
    SavingsAccount(): balance(0), interestRate(7.5), accountNumber(0){}

    // Constructor with parameters
    SavingsAccount( float bal, float inRate, int accNum): balance(bal), interestRate(inRate), accountNumber(accNum){};

    // Getters 
    float getBalance(){
        return balance;
    }

    float getInterestRate() const {
        return interestRate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    // Methods

    float deposit(float amount){
        return balance += amount;
    }

    float withdraw(float amount){
        if (balance > 0 and amount <= balance){
            return balance -= amount;
        }
        else {
            cout << "Insufficient balance" << endl;
            return balance;
        }
    }

};

#endif