#ifndef TRAILER_H
#define TRAILER_H

#include <string>
#include <iostream>
#include "Contenido.h"

using namespace std;

class Trailer: public Contenido{
  private: 
    float duracion;
    float suma=0;
    int cantidad=0;
    float promedio=0;
  public: 
    Trailer(string titulo, int fecha, float duracion, string id, float prom);
    string getTitulo();
    int getFecha();
    void setPromedio(float cal);
    float getPromedio();
    string getId();
    float getDuracion();
    virtual ~Trailer();
};

#endif

