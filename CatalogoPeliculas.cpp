#include "CatalogoPeliculas.h"
#include <iostream>

using namespace std;

CatalogoPeliculas::CatalogoPeliculas () { cout << "CatalogoPeliculas: Constructor privado" << endl; }

CatalogoPeliculas::~CatalogoPeliculas() {
    for (Pelicula* pelicula : peliculas) {
        delete pelicula;
    }
    peliculas.clear();
}

CatalogoPeliculas& CatalogoPeliculas::getInstancia(){
   static CatalogoPeliculas instancia;
   return instancia;
}

void CatalogoPeliculas :: leerCatalogo (const string& nombreArchivo){
try {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) throw runtime_error("No se puede abrir el archivo");

        string linea;
        while (getline(archivo, linea)) {
            istringstream registro(linea);
            string nombre, fe, director, id, prom;
            getline(registro, nombre, ',');
            getline(registro, fe, ',');
            getline(registro, director, ',');
            getline(registro, id, ',');
            getline(registro, prom, ',');

            int fecha = stoi(fe);
            float promedio = stof(prom);

            Pelicula* pelicula = new Pelicula(nombre, fecha, director, id, promedio);
            peliculas.push_back(pelicula);
        }
    } catch (const exception& e) {
        cerr << "Error leyendo el catálogo de películas: " << e.what() << endl;
    }
}

void CatalogoPeliculas::mostrarTodos(){
  string linea1 = "                      \\  /         \n";
  string linea2 = "                       \\/          \n";
  string linea3 = " .========================================.\n";
  string linea4 = " | .------------------------------------. |\n" ;
  string linea5=  " | |                                    | |\n";
  string linea6=  " | |         CATALOGO PELICULAS         | |\n";
  string linea7=  " | |                                    | |\n";
  string linea8=  "";
  string linea9 = " | |                                    | |   __\n";
  string linea10 = " | '------------------------------------'o|  |o.| \n";
  string linea11 = " |========================================|  |::| \n";
  string linea12 = " |########################################|  |::|\n";
  string linea13 = " '========================================'  '--'\n";
    try {
            for (Pelicula* pelicula : peliculas) {
                if (!pelicula) throw runtime_error("Película no válida");
                string title = pelicula->getTitulo();
                string year = to_string (pelicula->getFecha());
                string id =  pelicula->getId();
                string promedio = to_string (pelicula->getPromedio());
                //38 espacios
                string espacios = " ";
                string peli = " | |  " + title + " (" + year + ") " + "[" + id + "] "  + promedio.substr(0,3);
                for (int i = 0; i < 38 - peli.size(); ++i) {
                    espacios =  espacios + " ";
                }
                linea8 = linea8 + peli + espacios + " | |\n";

            } 
            string screenPeli = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
            linea10 + linea11 + linea12 + linea13;
            cout << screenPeli << endl;
        } catch (const exception& e) {
            cerr << "Error mostrando todas las películas: " << e.what() << endl;
        }  
}

vector<Pelicula*>& CatalogoPeliculas::getPeliculas() {
    return peliculas;
}

