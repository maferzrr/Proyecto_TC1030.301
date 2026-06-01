# 🏦 VaultCore 
La banca es uno de los pilares fundamentales de la economía moderna. Nos permite 
administrar el dinero de forma segura, realizar transacciones y hacer crecer nuestros 
ahorros a través del tiempo. Sin embargo, detrás de cada cuenta y cada operación existe 
una estructura de datos y procesos que hacen posible su funcionamiento.

------------
### Funcionalidad
Este proyecto presenta un sistema bancario básico desarrollado en C++ que simula las 
operaciones esenciales de un banco: registro de clientes, apertura de cuentas y 
cálculo de intereses.

Se implementan los siguientes elementos:

* Cliente: persona registrada en el banco que puede poseer una o más cuentas.
* Empleado: representa al personal del banco con funciones asignadas según su rol.
* Cuenta de ahorro: genera intereses periódicos sobre el saldo disponible.
* Cuenta de crédito: permite ver el crédito disponible, así como ver la tasa de intereses moratorios.

------------

### Instrucciones de Compilación

- Descargue todos los documentos adjuntos (a excepción de el diagrama UML).
- Desde la terminal, siga los pasos de compilación para su sistema operativo y compile únicamente el archivo "VaultCore.cpp".

#### Comando de compilación
  - g++ [nombre del archivo.cpp] -o [nombre del ejecutable a crear]

------------

### Casos en los que el proyecto dejarría de funcionar
#### Errores de Redondeo 
- Uso del tipo de dato float para almacenar saldos y tasas de interés. Descrepancias y pérdida de precisión centavo a centavo tras múltiples operaciones financieras.
#### Vulnerabilidad en Saldos 
- Los métodos withdraw y deposit no validan que el monto sea positivo.
#### Falta de Control en Límites de Crédito
- En CreditAccount, el saldo (balance) se maneja de forma genérica heredada de Account y no se conecta lógicamente con el atributo credit.
- El método withdraw no verifica si el retiro supera el límite de crédito disponible, permitiendo al cliente gastar dinero infinito.

------------

##### Autor
- María Fernanda Zetina Reyes | A01709799
- Ing. Tecnologías Computacionales
- Materia: TC1030.301

