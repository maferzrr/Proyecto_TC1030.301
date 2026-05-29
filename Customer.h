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
    // Attributes
    vector<Account*> accounts;

    public:
    // Empty constructor
    Customer(): Person("",0){}

    // Constructor with parameters
    Customer(string nom, int ident) : Person (nom, ident){};

    // Methods
    // Function pus_back to add elements into the vector
    // Added the account pointer 

    void addAccount(Account* newAccount){
        accounts.push_back(newAccount);
    }
    
    void showAccounts(){
        for (size_t i = 0; i < accounts.size(); i++) {
            cout << "Account Balance: " << accounts[i]->getBalance() << endl;
         }
    } 

};

# endif