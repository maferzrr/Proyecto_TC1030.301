/*
 * Proyecto VaultCore Main
 * 
 * María Fernanda Zetina Reyes
 * A01709799

 * Archivo principal del proyecto. Contiene la funcion main que ejecuta
 * el flujo del programa. 
 */

#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Employee.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

using namespace std;

/**
 * mostrarBienvenida imprime el encabezado del sistema
 *
 * limpia el codigo del main aislando la impresion de la interfaz
 * inicial del sistema VaultCore.
 *
 * @param
 * @return
 */
void mostrarBienvenida() {
    cout << "=========================================================\n";
    cout << "                ¡BIENVENIDO A VAULTCORE!                 \n";
    cout << "=========================================================\n";
    cout << "Aquí tú eres el líder. Tú decides qué hacer:\n";
    cout << "Añadir empleados, registrar clientes, controlar cuentas\n";
    cout << "bancarias y supervisar el núcleo financiero del sistema.\n";
    cout << "=========================================================\n\n";
}

/**
 * main controla el flujo de ejecucion principal
 *
 * inicializa los vectores para almacenar clientes y empleados,
 * y despliega un menu ciclico (do-while) controlado por el usuario
 * para realizar las operaciones del banco utilizando polimorfismo y herencia.
 *
 * @param
 * @return int 0 al finalizar la ejecucion correctamente
 */
int main() {

    vector<Customer> listaClientes;
    vector<Employee> listaEmpleados;

    int opcion = 0;
    int totalCuentas = 0;

    mostrarBienvenida();

    do {
        cout << "--- MENÚ PRINCIPAL DE VAULTCORE ---\n";
        cout << "1. Registrar un nuevo Cliente\n";
        cout << "2. Registrar un nuevo Empleado\n";
        cout << "3. Ver lista de Clientes y sus Balances\n";
        cout << "4. Ver lista de Empleados\n";
        cout << "5. Realizar un Depósito\n";
        cout << "6. Realizar un Retiro\n";
        cout << "7. Salir del sistema\n";
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

                //new crea el objeto en tiempo de ejecución
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
                    cout << "Saldo inicial disponible: "; cin >> saldo;
                    
                    cout << "Número de cuenta (máximo 9 dígitos): "; 
                    cin >> numCuenta;
                    while (cin.fail() || numCuenta < 0 || numCuenta > 999999999) {
                        if (cin.fail()) {
                            cin.clear(); 
                            cin.ignore(10000, '\n'); 
                        }
                        cout << "Error: Valor inválido o excede el límite de 9 dígitos.\n";
                        cout << "Número de cuenta (máximo 9 dígitos): ";
                        cin >> numCuenta;
                    }

                    cout << "Tasa de interés (%): "; cin >> tasa;
                    
                    //new crea el objeto en tiempo de ejecución para usar polimorfismo
                    nuevoCliente.addAccount(new SavingsAccount(saldo, numCuenta, tasa));
                    totalCuentas++; 
                    cout << "¡Cuenta de ahorros añadida con éxito!\n";
                } else if (tipoCuenta == 2) {
                    float deuda, credito, interes;
                    int numCuenta;
                   
                    cout << "Deuda inicial (0 si está limpia): "; cin >> deuda;
                    
                    cout << "Número de cuenta (máximo 9 dígitos): "; 
                    cin >> numCuenta;
                    while (cin.fail() || numCuenta < 0 || numCuenta > 999999999) {
                        if (cin.fail()) {
                            cin.clear(); 
                            cin.ignore(10000, '\n'); 
                        }
                        cout << "Error: Valor inválido o excede el límite de 9 dígitos.\n";
                        cout << "Número de cuenta (máximo 9 dígitos): ";
                        cin >> numCuenta;
                    }

                    cout << "Límite de crédito: "; cin >> credito;
                    cout << "Interés por pago tardío: "; cin >> interes;
                    
                    //new crea el objeto en tiempo de ejecución para usar polimorfismo
                    nuevoCliente.addAccount(new CreditAccount(deuda, numCuenta, credito, interes));
                    totalCuentas++; 
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

                //new crea el objeto en tiempo de ejecución
                Employee nuevoEmpleado(nombreEmp, idEmp, salario, depto, 20);
                listaEmpleados.push_back(nuevoEmpleado);
                cout << "\n¡Empleado '" << nombreEmp << "' registrado en el departamento de " << depto << "!\n\n";
                break;
            }

            case 3:
                cout << "--- Listado de Clientes Registrados ---\n";
                if (listaClientes.empty()) {
                    cout << "No hay clientes en el sistema.\n";
                } else {
                    //Ciclo que recorre el arreglo e imprime cada objeto.
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
                    //Ciclo que recorre el arreglo e imprime cada objeto.
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

            case 5: {
                cout << "--- Realizar Depósito ---\n";
                if (listaClientes.empty() || totalCuentas == 0) {
                    cout << "Error: No hay cuentas registradas en el sistema actualmente.\n\n";
                    break;
                }

                int cuentaBuscada;
                Account* cuenta = nullptr;

                while (cuenta == nullptr) {
                    cout << "Ingresa el número de cuenta: ";
                    cin >> cuentaBuscada;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Error: Entrada inválida. Introduce un valor numérico.\n";
                        continue;
                    }

                    //Ciclo que recorre el arreglo
                    for (size_t i = 0; i < listaClientes.size(); i++) {
                        cuenta = listaClientes[i].getAccount(cuentaBuscada);
                        if (cuenta != nullptr) {
                            break; 
                        }
                    }

                    if (cuenta == nullptr) {
                        cout << "La cuenta número " << cuentaBuscada << " no existe en el sistema. Intente de nuevo.\n";
                    }
                }

                float monto;
                cout << "Ingresa el monto a depositar: ";
                cin >> monto;
                
                while (cin.fail() || monto <= 0) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Error: El monto debe ser un valor numérico mayor a 0.\n";
                    cout << "Ingresa el monto a depositar: ";
                    cin >> monto;
                }

                cuenta->deposit(monto); 
                cout << endl;
                break;
            }

            case 6: {
                cout << "--- Realizar Retiro / Cargo ---\n";
                if (listaClientes.empty() || totalCuentas == 0) {
                    cout << "Error: No hay cuentas registradas en el sistema actualmente.\n\n";
                    break;
                }

                int cuentaBuscada;
                Account* cuenta = nullptr;

                while (cuenta == nullptr) {
                    cout << "Ingresa el número de cuenta: ";
                    cin >> cuentaBuscada;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Error: Entrada inválida. Introduce un valor numérico.\n";
                        continue;
                    }

                    //Ciclo que recorre el arreglo
                    for (size_t i = 0; i < listaClientes.size(); i++) {
                        cuenta = listaClientes[i].getAccount(cuentaBuscada);
                        if (cuenta != nullptr) {
                            break; 
                        }
                    }

                    if (cuenta == nullptr) {
                        cout << "La cuenta número " << cuentaBuscada << " no existe en el sistema. Intente de nuevo.\n";
                    }
                }

                float monto;
                cout << "Ingresa el monto a retirar: ";
                cin >> monto;

                while (cin.fail() || monto <= 0) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    cout << "Error: El monto debe ser un valor numérico mayor a 0.\n";
                    cout << "Ingresa el monto a retirar: ";
                    cin >> monto;
                }

                cuenta->withdraw(monto); 
                cout << endl;
                break;
            }

            case 7:
                cout << "Saliendo de VaultCore... ¡Gracias!\n";
                break;

            default:
                cout << "Opción inválida. Intenta de nuevo.\n\n";
                break;
        }

    } while (opcion != 7);

    return 0;
}