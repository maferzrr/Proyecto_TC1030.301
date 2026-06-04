// Class Savings Account

# ifndef SAVINGSACCOUNT_H
# define SAVINGSACCOUNT_H

# include "Account.h"
# include <iostream>

using namespace std;

class SavingsAccount: public Account {

    private:
        // Atributos
        float interestRate;

    public: 

        // Constructor default
        SavingsAccount(): Account(), interestRate(7.5){}

        // Constructor con parámetros
        SavingsAccount( float bal, int accNum, float inRate): Account(bal, accNum), interestRate(inRate){}

        // Métodos
        float getInterestRate() const;
        float withdraw(float amount);
        float deposit(float amount);
        float getBalance();

};

// Métodos definidos

float SavingsAccount::getInterestRate() const {
    return interestRate;
}


float SavingsAccount::withdraw(float amount){
    if (balance > 0 and amount <= balance){
        return balance -= amount;
    }
    else {
        cout << "Balance insuficiente" << endl;
        return balance;
    }
}

float SavingsAccount::deposit(float amount){
    return balance += amount;
}

float SavingsAccount::getBalance(){
    return balance;
}

#endif