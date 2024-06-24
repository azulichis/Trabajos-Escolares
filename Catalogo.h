#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>

using namespace std;

class Catalogo{
  public: 
    virtual void leerCatalogo (const string& nombreArchivo) = 0;
    virtual void mostrarTodos () = 0;
};

#endif