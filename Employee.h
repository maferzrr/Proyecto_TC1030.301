/*
 *
 * Proyecto VaultCore clase Employee
 * Maria Fernanda Zetina Reyes
 
 * Esta clase hereda de Person y define un objeto de tipo Employee.
 * Sirve para gestionar al personal del sistema bancario, controlando
 * su salario, departamento y los días de vacaciones disponibles.
 */

# ifndef EMPLOYEE_H
# define EMPLOYEE_H

# include "Person.h" // biblioteca con el objeto padre a usar
# include <iostream>
# include <string>

using namespace std;

class Employee : public Person{
    // Declaro las variables privadas de instancia
    private:
        float salary; // salario del empleado
        string department; // departamento al que pertenece
        int availableLeaveDays; // dias de descanso o vacaciones disponibles

    // Declaro constructores y metodos publicos
    public:
        // Constructor default 
        Employee(): Person(), salary(0), department(""), availableLeaveDays(20){}

        // Constructor con parámetros
        Employee(string name, int id, float sal, string dept, int avdays)
            : Person(name, id), salary(sal), department(dept), availableLeaveDays(avdays){}

        // Métodos

        void getInfo();

        float getSalary();

        string performingDuties();

        bool requestLeaveDays(int days);


};

/**
 * getInfo imprime la informacion del empleado
 *
 * utiliza las variables heredadas de Person junto con las propias
 * para imprimir el nombre, ID y departamento en consola.
 *
 * @param
 * @return
 */

void Employee::getInfo(){
     cout << name << "(ID:" << id << ")" << "- Department:" << department;
}

/**
 * getSalary obtiene el salario del empleado
 *
 * retorna el valor almacenado en la variable de instancia salary.
 *
 * @param
 * @return float con el salario actual
 */

float Employee::getSalary(){
    return salary;
}

/**
 * performingDuties simula la actividad del empleado
 *
 * genera un mensaje indicando que el empleado esta trabajando,
 * concatenando el nombre de su departamento.
 *
 * @param
 * @return string con el estado de actividad del empleado
 */

string Employee::performingDuties(){
    return "El empleado de " + department + " se encuentra realizando sus tareas";
}

/**
 * requestLeaveDays solicita dias de descanso
 *
 * verifica si la cantidad de dias solicitada es valida y si el empleado
 * tiene suficientes dias disponibles. Si es exitoso, descuenta los dias.
 *
 * @param int days cantidad de dias solicitados
 * @return bool true si se aprobaron los dias, false si no hay suficientes
 */

bool Employee::requestLeaveDays(int days){
    if(days > 0 && days <= availableLeaveDays) {
        availableLeaveDays -= days; 
        return true;
    }
    return false;
}

# endif