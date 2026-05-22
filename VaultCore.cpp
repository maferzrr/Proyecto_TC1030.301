// Main (test)

#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Employee.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

using namespace std;

int main() {
    
    Customer client1("Maria Fernanda", 101);
    
    
    SavingsAccount savings(5000.0, 0.05, 12345);
    CreditAccount credit(1000.0, 67890, 5000.0, 50.0);
    
    
    client1.addSavingsAccount(savings);
    client1.addCreditAccount(credit);
    
    cout << "--- Client Registration ---" << endl;
    cout << "Client: " << "Maria Fernanda" << " (ID: 101) successfully registered." << endl;
    cout << "Accounts added succesfully." << endl << endl;

    
    Employee emp1("Juan Perez", 999, 15000.0, "Finance");
    
    cout << "--- Employee Registration ---" << endl;
    cout << "Employee: " << "Juan Perez" << endl;
    cout << "Department: " << "Finanzas" << endl;
    cout << "Action: " << emp1.performingDuties() << endl << endl;
    
    
    cout << "--- Vacation Request ---" << endl;
    int days1 = 15;
    
    if (emp1.requestLeaveDays(days1)) {
        cout << "Request of de " << days1 << " dias: APROBADA." << endl;
    } else {
        cout << "Request of " << days1 << " dias: RECHAZADA." << endl;
    }

    int days2 = 45;
    if (emp1.requestLeaveDays(days2)) {
        cout << "Request of " << days2 << " days: APPROVED." << endl;
    } else {
        cout << "Request of " << days2 << " days: DENIED." << endl;
    }

    return 0;
}