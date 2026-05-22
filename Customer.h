// Classs Customer

# ifndef CUSTOMER_H
# define CUSTOMER_H

# include "Person.h"
# include "SavingsAccount.h"
# include "CreditAccount.h"
# include <vector>

class Customer : public Person {
    private:
    // Atributos
    vector<SavingsAccount> sAccount;
    vector<CreditAccount> cAccount;

    public:
    // Empty constructor
    Customer(): Person("",0){}

    // Constructor with parameters
    Customer(string nom, int ident) : Person (nom, ident){};

    // Methods
    // Function pus_back to add elements into the vector
    void addSavingsAccount(SavingsAccount newSavingsAccount){
        sAccount.push_back(newSavingsAccount);
    }

    void addCreditAccount(CreditAccount newCreditAccount){
        cAccount.push_back(newCreditAccount);
    }

    

};

# endif