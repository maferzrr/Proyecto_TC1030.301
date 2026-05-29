// Class Person 

# ifndef PERSON_H
# define PERSON_H

# include <iostream>
# include <string>

using namespace std;

class Person {
protected:
    // Attributes
    string name;
    int id;

public:
    // Empty constructor
    Person(): name(""), id(0) {};

    // Constructor with parameters
    Person(string nom, int ident) : name(nom), id(ident){};

    // Methods

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    };

};

# endif