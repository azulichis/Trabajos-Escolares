#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
#include <vector>
#include "Calificada.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Trailer.h"
#include "CatalogoPeliculas.h"
#include "CatalogoSeries.h"
#include "CatalogoTrailers.h"

using namespace std;

class Usuario {
    public:
        enum Status {SINSUSCRIPCION, SUSCRITO};
        enum Plan {NA,TRADICIONAL,PREMIUM};
    private:
        string nombre;
        string contrasena;
        vector <Calificada*> calificadas;
        Status status;
        Plan plan;
    public:
        Usuario(string nom, string cont, Status stat, Plan pl);
        bool calificar(Calificada*c);
        void mostrarCalificadas();
        Status getStatus();
        void setPlan(Plan pl);
        Plan getPlan();
        string getNombre();
        string getContrasena();
        virtual ~Usuario();
};
#endif