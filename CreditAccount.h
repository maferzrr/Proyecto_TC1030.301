// Class Credit Account

# ifndef CREDITACCOUNT_H
# define CREDITACCOUNT_H

# include <iostream>

using namespace std; 

class CreditAccount {

private:
    // Attributes
    int accountNumber;
    float balance;
    float credit;
    float latePaymentInterest;

public: 

    // Empty constructor
    CreditAccount(): accountNumber(0), balance(0), credit(0), latePaymentInterest(50){}

    // Constructor with parameters
    CreditAccount(float bal, int accNum, float cre, float payInt): balance(bal), 
    accountNumber(accNum), credit(cre), latePaymentInterest(payInt){};

// Getters
int getAccountNumber(){
    return accountNumber;
}

float getBalance(){
    return balance;
}


float getCredit(){
    return credit;
}

float getLatePaymentInterest(){
    return latePaymentInterest;
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

# endif