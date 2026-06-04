// Class Credit Account

# ifndef CREDITACCOUNT_H
# define CREDITACCOUNT_H

# include "Account.h"
# include <iostream>

using namespace std; 

class CreditAccount : public Account {

    private:
        // Atributos
        float credit;
        float latePaymentInterest;

    public: 

        // Constructor default
        CreditAccount(): Account() ,credit(0), latePaymentInterest(50){}

        // Constructor con parametros
        CreditAccount(float bal, int accNum, float cre, float payInt): Account(bal, accNum), credit(cre), latePaymentInterest(payInt){}
        

        // Métodos
        float getCredit();
        float getLatePaymentInterest();
        float withdraw(float amount);
        float deposit(float amount);
        float getBalance();

};

// Métodos definidos

float CreditAccount::getCredit(){
    return credit;
}

float CreditAccount::getLatePaymentInterest(){
    return latePaymentInterest;
}

float CreditAccount::withdraw(float amount){
        if (balance > 0 and amount <= balance){
            return balance -= amount;
        }
        else {
            cout << "Balance insuficiente" << endl;
            return balance;
        }
    }

float CreditAccount::deposit(float amount){
    return balance += amount;
}

float CreditAccount::getBalance(){
    return balance;
}

# endif