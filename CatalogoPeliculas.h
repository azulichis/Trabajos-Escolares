#ifndef CATALOGOPELICULAS_H
#define CATALOGOPELICULAS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Catalogo.h"
#include "Pelicula.h"

class CatalogoPeliculas: public Catalogo{
  private: 
    CatalogoPeliculas();
    vector <Pelicula*> peliculas;
  public:
    ~CatalogoPeliculas();
    static CatalogoPeliculas& getInstancia();
    void leerCatalogo(const string& nombreArchivo) override;
    void mostrarTodos() override;
    vector<Pelicula*>& getPeliculas();
};

#endif