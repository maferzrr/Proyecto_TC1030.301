// Class Employee

# ifndef EMPLOYEE_H
# define EMPLOYEE_H

# include "Person.h"
# include <iostream>
# include <string>

using namespace std;

class Employee : public Person{
private:
    // Atributtes
    float salary;
    string department;

public:
    // Empty constructor
    Employee(): Person(), salary(0), department(""){}

    // Constructor with parameters
    Employee(string name, int id, float sal, string dept)
        : Person(name, id), salary(sal), department(dept){}

    // Getter
    float getSalary(){
        return salary;
    }

    // Methods
    string performingDuties(){
        return "The customer from " + department + " is performing their duties";
    }

    bool requestLeaveDays(int days){
        if(days > 0 && days <= 30)
        return true;
    else
        return false;
    }


};


# endif