/** 
 * Proyecto VaultCore clase Account
 * Maria Fernanda Zetina Reyes

 * Esta clase abstracta define un objeto de tipo Account que contiene las operaciones
 * base para depositar, retirar y consultar fondos. Es utilizada como clase padre 
 * para los diferentes tipos de cuentas bancarias en el sistema VaultCore.
 */


# ifndef ACCOUNT_H
# define ACCOUNT_H

# include <iostream>

using namespace std;

class Account {
    // Declaración de las variables protegidas de instancia
    protected:
        float balance; // balance de fondos en la cuenta
        int accountNumber; // identificador unico de la cuenta

    // Declaración de constructores y metodos públicos
    public:
        // Constructor default
        Account(): balance(0.0), accountNumber(0) {}

        // Constructor con parametros
        Account(float bal, int accNum): balance(bal), accountNumber(accNum) {}

        // Método getter
        int getAccountNumber() const; 

        // Funciones virtuales puras para usar polimorfismo en clases hijas
        virtual float withdraw(float amount) = 0;
        virtual float deposit(float amount) = 0;
        virtual float getBalance();
    
};

/**
 * getBalance obtiene el balance de la cuenta
 *
 * retorna el valor almacenado en la variable de instancia balance.
 *
 * @param 
 * @return float con el balance actual de la cuenta
 */

float Account::getBalance(){
    return balance;
}

/**
 * getAccountNumber obtiene el identificador de la cuenta
 *
 * retorna el valor de la variable de instancia accountNumber.
 *
 * @param
 * @return int con el numero de cuenta
 */
int Account::getAccountNumber() const {
    return accountNumber;
}


# endif