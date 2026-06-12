/*
 *
 * Proyecto VaultCore clase SavingsAccount
 * Maria Fernanda Zetina Reyes
 
 * Esta clase hereda de Account y define un objeto de tipo SavingsAccount.
 * Representa una cuenta de ahorros estandar, permitiendo depósitos, retiros
 * controlados y la consulta de la tasa de interes aplicable.
 */

# ifndef SAVINGSACCOUNT_H
# define SAVINGSACCOUNT_H

# include "Account.h" // biblioteca con el objeto padre a usar
# include <iostream>

using namespace std;

class SavingsAccount: public Account {

    // Declaro las variables privadas de instancia
    private:
        float interestRate; // tasa de interes de la cuenta

    // Declaro constructores y metodos publicos
    public: 
        // Constructor default
        SavingsAccount(): Account(), interestRate(7.5){}

        // Constructor con parámetros
        SavingsAccount( float bal, int accNum, float inRate): Account(bal, accNum), interestRate(inRate){}

        float getInterestRate() const;
        float withdraw(float amount);
        float deposit(float amount);
        float getBalance();

};

/**
 * getInterestRate obtiene la tasa de interes
 *
 * retorna el porcentaje de interes configurado para esta cuenta.
 * Es un metodo constante (const) para garantizar que no modifique atributos.
 *
 * @param
 * @return float con la tasa de interes
 */

float SavingsAccount::getInterestRate() const {
    return interestRate;
}

/**
 * withdraw retira fondos de la cuenta de ahorros
 *
 * verifica que el monto solicitado sea positivo y que no exceda
 * el balance actual disponible antes de realizar el descuento.
 *
 * @param float amount cantidad a retirar
 * @return float con el nuevo balance de la cuenta
 */

float SavingsAccount::withdraw(float amount){
    if (amount > 0 && amount <= balance){
        return balance -= amount;
    }
    else {
        cout << "Balance insuficiente" << endl;
        return balance;
    }
}

/**
 * deposit agrega fondos a la cuenta de ahorros
 *
 * verifica que el monto sea positivo y lo suma al balance actual.
 *
 * @param float amount cantidad a depositar
 * @return float con el nuevo balance de la cuenta
 */

float SavingsAccount::deposit(float amount){
    if (amount > 0){
        return balance += amount; 
    }
    else {
        cout << "Monto de deposito invalido" << endl;
        return balance;
    }
}

/**
 * getBalance obtiene el balance de la cuenta
 *
 * retorna los fondos disponibles actualmente en la cuenta de ahorros.
 *
 * @param
 * @return float con el balance actual
 */

float SavingsAccount::getBalance(){
    return balance;
}

#endif