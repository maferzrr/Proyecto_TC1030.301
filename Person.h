// Class Person 

# ifndef PERSON_H
# define PERSON_H

# include <iostream>
# include <string>

using namespace std;

class Person {
    protected:
        // Atributos
        string name;
        int id;

    public:
        // Constructor default 
        Person(): name(""), id(0) {};

        // Constructor con parámetros
        Person(string nom, int ident) : name(nom), id(ident){};

        // Métodos
        // función "pure virtual"
        virtual void getInfo() = 0;

};

# endif
