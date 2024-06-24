#include <iostream>
#include "Plataforma.h"

using namespace std;

Plataforma::Plataforma(string nom): nombre(nom){}

void Plataforma::agregarUsuario(Usuario*u){
    try {
        usuarios.push_back(u);
    } catch (const exception& e){
        cerr << "Error al agregar usuario: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Ocurrió un error desconocido al agregar usuario" << endl;
    }
}

bool Plataforma::iniciarSesion(string user, string contrasena) {
    try {
        for (Usuario* usuario: usuarios){
            if (usuario->getNombre() == user && usuario->getContrasena() == contrasena) {
                if (usuario->getStatus() == Usuario::SUSCRITO) {
                    return true;
                }
                if (usuario->getStatus()== Usuario::SINSUSCRIPCION) {
                    cout << "Usuario no suscrito" << endl;
                    return false;
                }
            }
            else if (usuario->getNombre() == user && usuario->getContrasena() != contrasena) {
                cout << "Contraseña incorrecta" << endl;
                return false;
            }
        }
        return false;
    } catch (const exception& e) {
        cerr << "Error al iniciar sesión: " << e.what() << endl;
        return false;
    }
    catch (...) {
        cerr << "Ocurrió un error desconocido al iniciar sesión" << endl;
        return false; 
    }
}

void Plataforma::operator+(Usuario* other) {
    try {
        agregarUsuario(other); 
        cout << "Usuario creado exitosamente" << endl;
    } catch (const exception& e) {
        cerr << "Error al agregar usuario: " << e.what() << endl;
    } catch (...) {
        cerr << "Ocurrió un error desconocido al agregar usuario" << endl;
    }
}

bool Plataforma::validarNoRepetido(string nom) { 
    for (Usuario* usuario : usuarios) { 
        if (usuario->getNombre() == nom) {
            return false;
        }
    }
    return true;
}


Usuario* Plataforma::findUser(string& user){
    try {
        for (auto usuario:usuarios)
            if (usuario->getNombre()==user){
                return usuario;
            }
        throw runtime_error("Usuario no encontrado");
    } catch (const exception& e) {
        cerr << "Error al buscar usuario: " << e.what() << endl;
        return nullptr;
    } catch (...) {
        cerr << "Ocurrió un error desconocido al buscar usuario" << endl;
        return nullptr;
    }
}

Plataforma::~Plataforma(){
    cout << "Destructor de plataforma" << endl;
    for (auto usuario: usuarios)
        delete usuario;
}

string Plataforma::getNombre(){
    return nombre;
}


