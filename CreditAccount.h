// Class Credit Account

# ifndef CREDITACCOUNT_H
# define CREDITACCOUNT_H

# include "Account.h"
# include <iostream>

using namespace std; 

class CreditAccount : public Account {

private:
    // Attributes
    float credit;
    float latePaymentInterest;

public: 

    // Empty constructor
    CreditAccount(): Account() ,credit(0), latePaymentInterest(50){}

    // Constructor with parameters
    CreditAccount(float bal, int accNum, float cre, float payInt): Account(bal, accNum), credit(cre), latePaymentInterest(payInt){}
    
// Getters

float getCredit(){
    return credit;
}

float getLatePaymentInterest(){
    return latePaymentInterest;
}

};

# endif