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
### Casos en los que el proyecto dejaría de funcionar
#### Destructores virtuales faltantes
- Las clases con funciones virtuales, al no contar con un desturctor virtual, el comportamiento es indefinido y probablemente solo se liberará la parte de la clase base, no la de la clase derivada.

#### Validación de entradas
El menú interactivo en VaultCore.cpp es altamente vulnerable a errores del usuario:

- Entradas de tipo incorrecto: Si el usuario ingresa una letra cuando el sistema espera un entero para opcion, id, saldo o tasa, el flujo cin entrará en estado de error. A partir de ese momento, el programa ignorará futuras lecturas, causando un bucle infinito en el do-while al intentar leer la variable opcion.

- Desbordamiento: No hay validación para valores negativos o extremadamente grandes en campos como saldo o salario.

#### Falta de validación en el tipo de cuenta (enum ausente)
En VaultCore.cpp, la elección del tipo de cuenta depende de un número (1 para Ahorros, 2 para Crédito).

- Si el usuario ingresa un número distinto (como 3 o 99), el código simplemente no añade ninguna cuenta al cliente y continúa.

- No hay una estructura de control fuerte (como un enum o una validación estricta) que asegure que el objeto creado sea consistente con el tipo solicitado. Esto hace que el sistema sea propenso a estados inconsistentes donde un usuario cree que creó una cuenta pero el sistema no la registró.

------------

##### Autor
- María Fernanda Zetina Reyes | A01709799
- Ing. Tecnologías Computacionales
- Materia: TC1030.301

