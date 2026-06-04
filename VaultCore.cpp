// Main (test con menú interactivo)

#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Employee.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

using namespace std;

void mostrarBienvenida() {
    cout << "=========================================================\n";
    cout << "                ¡BIENVENIDO A VAULTCORE!                 \n";
    cout << "=========================================================\n";
    cout << "Aquí tú eres el líder. Tú decides qué hacer:\n";
    cout << "Añadir empleados, registrar clientes, controlar cuentas\n";
    cout << "bancarias y supervisar el núcleo financiero del sistema.\n";
    cout << "=========================================================\n\n";
}

int main() {
    // Vectores para almacenar dinámicamente los datos
    vector<Customer> listaClientes;
    vector<Employee> listaEmpleados;

    // Datos iniciales para que no inicie vacío
    Customer clienteOriginal("Maria Fernanda", 101);
    clienteOriginal.addAccount(new SavingsAccount(5000.0, 12345, 7.5));
    clienteOriginal.addAccount(new CreditAccount(1000.0, 67890, 5000.0, 50.0));
    listaClientes.push_back(clienteOriginal);

    listaEmpleados.push_back(Employee("Rashell Aleck", 999, 15000.0, "Finance"));

    int opcion = 0;

    // Mostrar la introducción
    mostrarBienvenida();

    do {
        cout << "--- MENÚ PRINCIPAL DE VAULTCORE ---\n";
        cout << "1. Registrar un nuevo Cliente\n";
        cout << "2. Registrar un nuevo Empleado\n";
        cout << "3. Ver lista de Clientes y sus Balances\n";
        cout << "4. Ver lista de Empleados\n";
        cout << "5. Salir del sistema\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                string nombreCliente;
                int idCliente;
                cout << "--- Registro de Cliente ---\n";
                cout << "Ingresa el nombre del cliente: ";
                cin.ignore(); 
                getline(cin, nombreCliente);
                cout << "Ingresa el ID del cliente: ";
                cin >> idCliente;

                Customer nuevoCliente(nombreCliente, idCliente);

                
                int tipoCuenta;
                cout << "\n¿Deseas asignarle una cuenta bancaria inicial?\n";
                cout << "1. Cuenta de Ahorros\n";
                cout << "2. Cuenta de Crédito\n";
                cout << "3. Ninguna por ahora\n";
                cout << "Selecciona una opción: ";
                cin >> tipoCuenta;

                if (tipoCuenta == 1) {
                    float saldo, tasa;
                    int numCuenta;
                    cout << "Saldo inicial: "; cin >> saldo;
                    cout << "Número de cuenta: "; cin >> numCuenta;
                    cout << "Tasa de interés (%): "; cin >> tasa;
                    nuevoCliente.addAccount(new SavingsAccount(saldo, numCuenta, tasa));
                    cout << "¡Cuenta de ahorros añadida con éxito!\n";
                } else if (tipoCuenta == 2) {
                    float saldo, credito, interes;
                    int numCuenta;
                    cout << "Saldo inicial: "; cin >> saldo;
                    cout << "Número de cuenta: "; cin >> numCuenta;
                    cout << "Límite de crédito: "; cin >> credito;
                    cout << "Interés por pago tardío: "; cin >> interes;
                    nuevoCliente.addAccount(new CreditAccount(saldo, numCuenta, credito, interes));
                    cout << "¡Cuenta de crédito añadida con éxito!\n";
                }

                listaClientes.push_back(nuevoCliente);
                cout << "\n¡Cliente '" << nombreCliente << "' registrado exitosamente!\n\n";
                break;
            }

            case 2: {
                string nombreEmp, depto;
                int idEmp;
                float salario;
                cout << "--- Registro de Empleado ---\n";
                cout << "Ingresa el nombre del empleado: ";
                cin.ignore();
                getline(cin, nombreEmp);
                cout << "Ingresa el ID del empleado: ";
                cin >> idEmp;
                cout << "Ingresa el salario: ";
                cin >> salario;
                cout << "Ingresa el departamento: ";
                cin.ignore();
                getline(cin, depto);

                Employee nuevoEmpleado(nombreEmp, idEmp, salario, depto);
                listaEmpleados.push_back(nuevoEmpleado);
                cout << "\n¡Empleado '" << nombreEmp << "' registrado en el departamento de " << depto << "!\n\n";
                break;
            }

            case 3:
                cout << "--- Listado de Clientes Registrados ---\n";
                if (listaClientes.empty()) {
                    cout << "No hay clientes en el sistema.\n";
                } else {
                    for (size_t i = 0; i < listaClientes.size(); i++) {
                        cout << "-----------------------------------\n";
                        cout << "Cliente: ";
                        listaClientes[i].getInfo(); 
                        cout << "\nCuentas asociadas:\n";
                        listaClientes[i].showAccounts(); 
                    }
                    cout << "-----------------------------------\n";
                }
                cout << endl;
                break;

            case 4:
                cout << "--- Listado de Empleados Activos ---\n";
                if (listaEmpleados.empty()) {
                    cout << "No hay empleados en el sistema.\n";
                } else {
                    for (size_t i = 0; i < listaEmpleados.size(); i++) {
                        cout << "-----------------------------------\n";
                        cout << "Empleado: ";
                        listaEmpleados[i].getInfo();
                        cout << "\nSalario: $" << listaEmpleados[i].getSalary() << endl;
                        cout << "Estado: " << listaEmpleados[i].performingDuties() << endl;
                    }
                    cout << "-----------------------------------\n";
                }
                cout << endl;
                break;

            case 5:
                cout << "Saliendo de VaultCore... ¡Gracias por ser nuestro líder hoy!\n";
                break;

            default:
                cout << "Opción inválida. Intenta de nuevo, líder.\n\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}