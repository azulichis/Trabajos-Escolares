#ifndef CALIFICADA_H
#define CALIFICADA_H

#include <string>
#include <iostream>

#include "Contenido.h"

using namespace std;

class Calificada {
    private:
        string titulo;
        float calificacion;
    public:
        Calificada(string tit, float cal);
        float getCalificacion();
        string getTitulo();
        void actualizarCalificacion(float cal);

};
#endif