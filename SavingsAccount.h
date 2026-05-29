// Class Savings Account

# ifndef SAVINGSACCOUNT_H
# define SAVINGSACCOUNT_H

# include "Account.h"
# include <iostream>

using namespace std;

class SavingsAccount: public Account {

private:
    // Attributes
    float interestRate;
  

public: 

    // Empty cosntructor
    SavingsAccount(): Account(), interestRate(7.5){}

    // Constructor with parameters
    SavingsAccount( float bal, int accNum, float inRate): Account(bal, accNum), interestRate(inRate){}

    // Getters 

    float getInterestRate() const {
        return interestRate;
    }


};

#endif