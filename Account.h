// Abstract Class Account

# ifndef ACCOUNT_H
# define ACCOUNT_H

# include <iostream>

using namespace std;

class Account {
    protected:
        // Atributos
        float balance;
        int accountNumber;

    public:
        // Constructor default
        Account(): balance(0.0), accountNumber(0) {}

        // Constructor con parametros
        Account(float bal, int accNum): balance(bal), accountNumber(accNum) {}

        // Métodos
        virtual float withdraw(float amount) = 0;
        virtual float deposit(float amount) = 0;

        float getBalance();
    
};

float Account::getBalance(){
    return balance;
}

# endif