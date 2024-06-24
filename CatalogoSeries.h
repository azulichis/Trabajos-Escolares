#ifndef CATALOGOSERIES_H
#define CATALOGOSERIES_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Serie.h"
#include "Catalogo.h"

using namespace std;

class CatalogoSeries: public Catalogo {
    private:
        CatalogoSeries();
        vector <Serie*> series;
    public:
        ~CatalogoSeries();
        static CatalogoSeries& getInstancia();
        void leerCatalogo(const string& nombreArchivo) override;
        void mostrarTodos() override;
        vector<Serie*>& getSeries();
};
#endif