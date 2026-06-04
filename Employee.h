// Class Employee

# ifndef EMPLOYEE_H
# define EMPLOYEE_H

# include "Person.h"
# include <iostream>
# include <string>

using namespace std;

class Employee : public Person{
    private:
        // Atributos
        float salary;
        string department;

    public:
        // Constructor default 
        Employee(): Person(), salary(0), department(""){}

        // Constructor con parámetros
        Employee(string name, int id, float sal, string dept)
            : Person(name, id), salary(sal), department(dept){}

        // Métodos

        void getInfo();

        float getSalary();

        string performingDuties();

        bool requestLeaveDays(int days);


};

// Define Methods

void Employee::getInfo(){
    cout << name; 
    cout << id;
}

float Employee::getSalary(){
    return salary;
}

string Employee::performingDuties(){
    return "El empleado de " + department + " se encuentra realizando sus tareas";
}

bool Employee::requestLeaveDays (int days){
    if(days > 0 && days <= 30)
        return true;
    else
        return false;
    }

# endif