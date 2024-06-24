#ifndef CATALOGOTRAILERS_H
#define CATALOGOTRAILERS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Catalogo.h"
#include "Trailer.h"

using namespace std;

class CatalogoTrailers: public Catalogo{
  private: 
    CatalogoTrailers();
    vector <Trailer*> trailers;
  public:
    ~CatalogoTrailers();
    static CatalogoTrailers& getInstancia();
    void leerCatalogo(const string& nombreArchivo) override;
    void mostrarTodos() override;
    vector<Trailer*>& getTrailers();
};

#endif