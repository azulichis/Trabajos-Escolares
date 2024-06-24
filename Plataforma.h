#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

class Plataforma{
private: 
    string nombre;
public:
    vector <Usuario*> usuarios;
    Plataforma(string nom);
    void agregarUsuario(Usuario*u);
    bool iniciarSesion(string user, string contrasena);
    void operator+(Usuario*other);
    ~Plataforma(); 
    Usuario* findUser(string& user);
    string getNombre();
    bool validarNoRepetido(string nom);

};

#endif