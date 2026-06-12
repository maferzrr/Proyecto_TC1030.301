/*
 *
 * Proyecto VaultCore clase CreditAccount
 * Maria Fernanda Zetina Reyes
 
 * Esta clase hereda de Account y define un objeto de tipo CreditAccount.
 * Contiene las operaciones específicas para manejar cuentas de crédito,
 * incluyendo límites de crédito y cargos por pagos tardíos.
 */

# ifndef CREDITACCOUNT_H
# define CREDITACCOUNT_H

# include "Account.h" // biblioteca con el objeto padre a usar
# include <iostream>

using namespace std; 

class CreditAccount : public Account {
    // Declaro las variables privadas de instancia
    private:
      
        float credit; // limite de credito otorgado
        float latePaymentInterest; // intereses por atraso

    // Declaro constructores y metodos publicos
    public: 

        // Constructor default
        CreditAccount(): Account() ,credit(0), latePaymentInterest(50){}

        // Constructor con parametros
        CreditAccount(float bal, int accNum, float cre, float payInt): Account(bal, accNum), credit(cre), latePaymentInterest(payInt){}
        

        // Métodos
        float getCredit();
        float getLatePaymentInterest();
        float withdraw(float amount);
        float deposit(float amount);
        float getBalance();

};

/**
 * getCredit obtiene el limite de credito
 *
 * retorna el valor de la variable de instancia credit que representa el tope de la cuenta.
 *
 * @param
 * @return float con el limite de credito
 */

float CreditAccount::getCredit(){
    return credit;
}

/**
 * getLatePaymentInterest obtiene el interes moratorio
 *
 * retorna la penalizacion configurada para esta cuenta en caso de atraso.
 *
 * @param
 * @return float con el interes por pago tardio
 */

float CreditAccount::getLatePaymentInterest(){
    return latePaymentInterest;
}

/**
 * withdraw simula un cargo a la tarjeta de credito
 *
 * verifica que el monto sea positivo y que el cargo sumado al balance actual (deuda)
 * no supere el limite de credito establecido.
 *
 * @param float amount cantidad a cargar a la cuenta
 * @return float con el nuevo balance (deuda) de la cuenta
 */

float CreditAccount::withdraw(float amount){
        if (amount > 0 && (balance + amount) <= credit){
            return balance += amount;
        }
        else {
            cout << "Balance insuficiente" << endl;
            return balance;
        }
    }

 /**
 * deposit abona a la deuda de la tarjeta de credito
 *
 * verifica que el monto sea positivo y lo resta del balance (deuda) actual.
 *
 * @param float amount cantidad a pagar
 * @return float con el nuevo balance (deuda) de la cuenta
 */

float CreditAccount::deposit(float amount){
    if (amount > 0){
        balance -= amount; 
        cout << "Pago realizado con exito. Deuda actual: $" << balance << endl;
        return balance;
    }
    else {
        cout << "Monto de pago invalido" << endl;
        return balance;
    }
}

/**
 * getBalance calcula el credito disponible
 *
 * resta el balance actual (deuda) del limite de credito para saber
 * cuanto dinero le queda disponible al cliente para gastar.
 *
 * @param
 * @return float con el credito disponible
 */

float CreditAccount::getBalance(){
    return credit - balance;
}

# endif