/*
 *
 * Proyecto VaultCore clase Customer
 * Maria Fernanda Zetina Reyes

 * Esta clase hereda de Person y define un objeto de tipo Customer.
 * Sirve para gestionar los clientes del sistema bancario, almacenando
 * sus datos personales y un arreglo (vector) de apuntadores a sus cuentas.
 */

# ifndef CUSTOMER_H
# define CUSTOMER_H

# include "Person.h" // biblioteca con el objeto padre a usar
# include "Account.h" // biblioteca con el objeto cuenta a usar
# include <vector>
# include <iostream>

using namespace std;

class Customer : public Person {
    // Declaro las variables privadas de instancia
    private:
        vector<Account*> accounts; // se define como vector de apuntadores para usar polimorfismo

    // Declaro constructores y metodos publicos
    public:
        // Constructor default
        Customer(): Person("",0){}

        // Constructor con parámetros
        Customer(string nom, int ident) : Person (nom, ident){};

        // Métodos
        
        void getInfo();

        void addAccount(Account* newAccount);

        Account* getAccount(int accNum);
        
        void showAccounts();

};

/**
 * getInfo imprime la informacion del cliente
 *
 * utiliza las variables heredadas de Person para imprimir el nombre
 * y el ID del cliente en consola.
 *
 * @param
 * @return
 */

void Customer::getInfo(){
    cout << name << "(ID:" << id << ")";
}

/**
 * addAccount asocia una nueva cuenta al cliente
 *
 * recibe un apuntador de tipo Account (que puede ser SavingsAccount o CreditAccount)
 * y lo agrega al vector de cuentas del cliente usando el metodo push_back.
 *
 * @param Account* newAccount apuntador a la cuenta a vincular
 * @return
 */

void Customer::addAccount(Account* newAccount){
        accounts.push_back(newAccount);
    }


/**
 * getAccount busca y retorna una cuenta específica del cliente
 *
 * recorre el vector de cuentas buscando una coincidencia con accNum.
 * Si la encuentra, devuelve el apuntador a la cuenta; si no, devuelve nullptr.
 *
 * @param int accNum numero de cuenta a buscar
 * @return Account* apuntador a la cuenta encontrada o nullptr
 */

Account* Customer::getAccount(int accNum) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accNum) {
            return accounts[i]; // Devolvemos el apuntador (aquí va el polimorfismo)
        }
    }
    return nullptr; // No se encontró esa cuenta en este cliente
}

/**
 * showAccounts imprime los balances de todas las cuentas del cliente
 *
 * recorre el vector accounts[] invocando el metodo getBalance() de cada objeto,
 * aprovechando el polimorfismo para calcular el balance segun el tipo de cuenta.
 *
 * @param
 * @return
 */

void Customer::showAccounts(){
        for (size_t i = 0; i < accounts.size(); i++) {
            cout << "Account Balance: " << accounts[i]->getBalance() << endl;
    }
}



# endif