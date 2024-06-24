#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <iostream>
#include "Contenido.h"

using namespace std;

class Serie : public Contenido {
    private:
        int temporadas; 
        float suma=0;
        int cantidad=0;
        float promedio=0;
    public:
        Serie (string tit, int fe, int temp, string Id, float prom);
        string getTitulo();
        int getFecha();
        void setPromedio(float cal);
        float getPromedio();
        string getId();
        int getTemporadas();
        virtual ~Serie();
        
};
#endif