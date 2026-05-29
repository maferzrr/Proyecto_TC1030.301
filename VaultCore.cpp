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
    
    // 1. Client
    Customer client1("Maria Fernanda", 101);
    
    // 2. Creating accounts using pointers
    Account* savings = new SavingsAccount(5000.0, 12345, 7.5);
    Account* credit = new CreditAccount(1000.0, 67890, 5000.0, 50.0);
    
    // 3. Add accounts
    client1.addAccount(savings);
    client1.addAccount(credit);
    
    cout << "--- Client Registration ---\n" << endl;
    cout << "Client: Maria Fernanda (ID: 101) successfully registered." << endl;

    // 4. Show balances
    cout << "--- Account Balances ---\n" << endl;
    client1.showAccounts(); 
    cout << endl;
    
    // 5. Employee
    Employee emp1("Rashell Aleck", 999, 15000.0, "Finance");
    
    cout << "--- Employee Registration ---\n" << endl;
    cout << "Employee: " << "Rashell Aleck" << endl;
    cout << "Department: " << "Finance" << endl;
    cout << "Action: " << emp1.performingDuties() << endl << endl;
    
    cout << "--- Vacation Request ---\n" << endl;
    int days1 = 15;
    cout << "Requesting " << days1 << " days: ";
    if(emp1.requestLeaveDays(days1)) {
        cout << "Approved" << endl;
    } else {
        cout << "Denied" << endl;
    }
    
    // 6. Free heap memory (IMPORTANT)
    delete savings;
    delete credit;
    
    return 0;
}