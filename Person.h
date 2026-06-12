/*
 *
 * Proyecto VaultCore clase Person
 * Maria Fernanda Zetina Reyes

 * Esta clase abstracta define un objeto base de tipo Person. 
 * Contiene los atributos fundamentales (nombre e ID) compartidos 
 * por todas las personas en el sistema, y sirve como clase padre 
 * para Customer y Employee.
 */ 

# ifndef PERSON_H
# define PERSON_H

# include <iostream>
# include <string>

using namespace std;

class Person {
    // Declaro las variables protegidas de instancia
    protected:
        string name; // nombre de la persona
        int id; // identificador unico

    // Declaro constructores y metodos publicos
    public:
        // Constructor default 
        Person(): name(""), id(0) {};

        // Constructor con parámetros
        Person(string nom, int ident) : name(nom), id(ident){};

         // funcion "pure virtual" para obligar a las clases hijas a implementar su propia version
        virtual void getInfo() = 0;

};

# endif
