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
        virtual float withdraw (float amount);
        virtual float deposit (float amount);

        // Método para forzar clase abstracta
        // Preguntar a Frida sobre las clases abstractas
        //virtual void whatever() = 0;

        float getBalance();
    
};

// Métodos definidos
float Account::withdraw(float amount){
    if (balance > 0 && amount <= balance){
        return balance -= amount;
    } else {
        cout << "Insufficient balance" << endl;
        return balance;
    }
}

float Account::deposit(float amount){
    return balance += amount;
}

float Account::getBalance(){
    return balance;
}
# endif