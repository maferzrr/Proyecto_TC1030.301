// Class Customer

# ifndef CUSTOMER_H
# define CUSTOMER_H

# include "Person.h"
# include "Account.h"
# include <vector>
# include <iostream>

using namespace std;

class Customer : public Person {
    private:
    // Atributos
    vector<Account*> accounts;

    public:
    // Constructor default
    Customer(): Person("",0){}

    // Constructor con parámetros
    Customer(string nom, int ident) : Person (nom, ident){};

    // Métodos
    
    void getInfo();

    void addAccount(Account* newAccount);
    
    void showAccounts();

};

// Métodos definidos

void Customer::getInfo(){
    cout << name << "(ID:" << id << ")";
}

// push_back para añadir elementos al vector

void Customer::addAccount(Account* newAccount){
        accounts.push_back(newAccount);
    }

void Customer::showAccounts(){
        for (size_t i = 0; i < accounts.size(); i++) {
            cout << "Account Balance: " << accounts[i]->getBalance() << endl;
    }
}

# endif