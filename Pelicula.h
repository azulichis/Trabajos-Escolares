#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <iostream>
#include "Contenido.h"

using namespace std;

class Pelicula : public Contenido {
    private:
        string director; 
        float promedio=0;
        float suma=0;
        int cantidad=0;
    public:
        Pelicula(string tit, int fe, string dir, string Id, float promedio);
        string getTitulo();
        int getFecha();
        void setPromedio(float cal);
        float getPromedio();
        string getId();
        string getDirector();
        virtual ~Pelicula(); 

};
#endif