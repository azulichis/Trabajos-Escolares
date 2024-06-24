#include "CatalogoTrailers.h"

#include <iostream>

using namespace std;


CatalogoTrailers::CatalogoTrailers() {
    cout << "CatalogoSeries: Constructor privado" << endl;
}


CatalogoTrailers::~CatalogoTrailers() {
    for (Trailer* trailer : trailers) {
        delete trailer;
    }
    trailers.clear();
}

CatalogoTrailers& CatalogoTrailers::getInstancia() {
    static CatalogoTrailers instancia;
    return instancia;
}

void CatalogoTrailers::leerCatalogo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        istringstream registro(linea);
        string nombre, fe, dur,id, prom;
        getline(registro, nombre, ',');
        getline(registro, fe, ',');
        getline(registro, dur, ',');
        getline(registro, id, ',');
        getline(registro, prom, ',');

        int fecha = stoi(fe); 
        float duracion = stof(dur);
        float promedio = stof(prom); 

        Trailer*trailer = new Trailer(nombre, fecha, duracion, id, promedio); 
        trailers.push_back(trailer);
    } 
}

void CatalogoTrailers::mostrarTodos(){
  string linea1 = "                             \\  /         \n";
  string linea2 = "                              \\/          \n";
  string linea3 = " .=====================================================.\n";
  string linea4 = " | .-------------------------------------------------. |\n" ;
  string linea5=  " | |                                                 | |\n";
  string linea6=  " | |                CATALOGO TRAILERS                | |\n";
  string linea7=  " | |                                                 | |\n";
  string linea8=  "";
  string linea9 = " | |                                                 | |   __\n";
  string linea10 = " | '-------------------------------------------------'o|  |o.| \n";
  string linea11 = " |=====================================================|  |::| \n";
  string linea12 = " |#####################################################|  |::|\n";
  string linea13 = " '====================================================='  '--'\n";

    for (Trailer* trailer : trailers) {

        string title = trailer->getTitulo();
        string year = to_string (trailer->getFecha());
        string id = trailer->getId();
        string duracion = to_string (trailer->getDuracion());
        string promedio = to_string (trailer->getPromedio());

        string tra = " | |  " + title + "(" + year +  ")" + "[" + id + "] "+ duracion.substr(0,3) + " min " + promedio.substr(0,3);

        string espacios = " ";
        for (int i = 0; i < 51 - tra.size(); ++i) {
            espacios =  espacios + " ";
        }
        linea8 = linea8 + tra + espacios +  " | |\n";
    }
    string screenSerie = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
    linea10 + linea11 + linea12 + linea13;
    cout << screenSerie << endl;
}
vector<Trailer*>& CatalogoTrailers::getTrailers() {
    return trailers;
}

