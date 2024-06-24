#ifndef CONTENIDO_H
#define CONTENIDO_H

#include <string>
#include <iostream>

using namespace std;

class Contenido {
  protected:
     string titulo;
     int fecha;
     string id;
     float promedio=0;
     float suma=0;
     int cantidad=0;
  public:
    Contenido (string titulo, int fecha, string id, float promedio);
    virtual string getTitulo()=0;
    virtual int getFecha()=0;
    virtual string getId()=0;
    virtual float getPromedio()=0;
    virtual void setPromedio(float cal) = 0;
};

#endif