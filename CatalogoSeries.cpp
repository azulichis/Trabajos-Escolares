#include "CatalogoSeries.h"

#include <iostream>
#include <string>

using namespace std;


CatalogoSeries::CatalogoSeries() {
    cout << "CatalogoSeries: Constructor privado" << endl;
}


CatalogoSeries::~CatalogoSeries() {
    for (Serie* serie : series) {
        delete serie;
    }
    series.clear();
}

CatalogoSeries& CatalogoSeries::getInstancia() {
    static CatalogoSeries instancia;
    return instancia;
}

void CatalogoSeries::leerCatalogo(const string& nombreArchivo) {
 try {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) throw runtime_error("No se puede abrir el archivo");

        string linea;
        while (getline(archivo, linea)) {
            istringstream registro(linea);
            string nombre, fe, temp, id, prom;
            getline(registro, nombre, ',');
            getline(registro, fe, ',');
            getline(registro, temp, ',');
            getline(registro, id, ',');
            getline(registro, prom, ',');

            int fecha = stoi(fe);
            int temporadas = stoi(temp);
            float promedio = stof(prom);

            Serie* serie = new Serie(nombre, fecha, temporadas, id, promedio);
            series.push_back(serie);
        }
    } catch (const exception& e) {
        cerr << "Error leyendo el catálogo de series: " << e.what() << endl;
    }
}

void CatalogoSeries::mostrarTodos(){
  cout << "Catalogo Series" << endl;
  string linea1 = "                             \\  /         \n";
  string linea2 = "                              \\/          \n";
  string linea3 = " .=====================================================.\n";
  string linea4 = " | .-------------------------------------------------. |\n" ;
  string linea5=  " | |                                                 | |\n";
  string linea6=  " | |                     CATALOGO SERIES             | |\n";
  string linea7=  " | |                                                 | |\n";
  string linea8=  "";
  string linea9 = " | |                                                 | |   __\n";
  string linea10 = " | '-------------------------------------------------'o|  |o.| \n";
  string linea11 = " |=====================================================|  |::| \n";
  string linea12 = " |#####################################################|  |::|\n";
  string linea13 = " '====================================================='  '--'\n";

    for (Serie* serie : series) {

        string title = serie->getTitulo();
        string year = to_string (serie->getFecha());
        string id = serie->getId();
        string temporadas = to_string (serie->getTemporadas());
        string promedio = to_string (serie->getPromedio());

        string ser = " | |    " + title + "(" + year +  ")" + "[" + id + "] "+ temporadas + " temp " + promedio.substr(0,3);
        string espacios = " ";
        for (int i = 0; i < 51 - ser.size(); ++i) {
            espacios =  espacios + " ";
        }
        linea8 = linea8 + ser + espacios + " | |\n";
    }
    string screenSerie = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
    linea10 + linea11 + linea12 + linea13;
    cout << screenSerie << endl;
}

vector<Serie*>& CatalogoSeries::getSeries() {
    return series;
}
