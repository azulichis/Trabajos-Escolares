#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(string nom, string cont, Status stat, Plan pl)
    : nombre(nom), contrasena(cont), status(stat), plan(pl) {}

bool Usuario::calificar(Calificada *c) {
  try {
    CatalogoPeliculas &catalogo2Pelis = CatalogoPeliculas::getInstancia();
    vector<Pelicula *> pelis = catalogo2Pelis.getPeliculas();
    CatalogoSeries &catalogo2Ser = CatalogoSeries::getInstancia();
    vector<Serie *> sers = catalogo2Ser.getSeries();
    CatalogoTrailers &catalogo2Trai = CatalogoTrailers::getInstancia();
    vector<Trailer *> trails = catalogo2Trai.getTrailers();
    for (Pelicula *pelicula : pelis) {
        if (pelicula->getTitulo() == c->getTitulo()) {
            bool yaCalificado = false;
            for (Calificada *calificada : calificadas) {
                if (calificada->getTitulo() == c->getTitulo()) {
                    float calificacionAnterior = calificada->getCalificacion();
                    float nuevaCalificacion = c->getCalificacion();
                    pelicula->setPromedio(-calificacionAnterior); 
                    calificada->actualizarCalificacion(nuevaCalificacion);
                    pelicula->setPromedio(nuevaCalificacion); 
                    cout << "Se ha actualizado la calificación" << endl;
                    yaCalificado = true;
                    return true;
                }
            }
            if (!yaCalificado) {
                float nuevaCalificacion = c->getCalificacion();
                pelicula->setPromedio(nuevaCalificacion); 
                calificadas.push_back(c);
                cout << "Se ha calificado exitosamente" << endl;
                return true;
            }
        }
    }
    for (Serie *serie : sers) {
      if (serie->getTitulo() == c->getTitulo()) {
          bool yaCalificado = false;
          for (Calificada *calificada : calificadas) {
              if (calificada->getTitulo() == c->getTitulo()) {
                  float calificacionAnterior = calificada->getCalificacion();
                  float nuevaCalificacion = c->getCalificacion();
                  serie->setPromedio(-calificacionAnterior); 
                  calificada->actualizarCalificacion(nuevaCalificacion);
                  serie->setPromedio(nuevaCalificacion); 
                  cout << "Se ha actualizado la calificación" << endl;
                  yaCalificado = true;
                  return true;
              }
          }
          if (!yaCalificado) {
              float nuevaCalificacion = c->getCalificacion();
              serie->setPromedio(nuevaCalificacion); 
              calificadas.push_back(c);
              cout << "Se ha calificado exitosamente" << endl;
              return true;
          }
      }
    }
    for (Trailer *trailer : trails) {
      if (trailer->getTitulo() == c->getTitulo()) {
          bool yaCalificado = false;
          for (Calificada *calificada : calificadas) {
              if (calificada->getTitulo() == c->getTitulo()) {
                  float calificacionAnterior = calificada->getCalificacion();
                  float nuevaCalificacion = c->getCalificacion();
                  trailer->setPromedio(-calificacionAnterior); 
                  calificada->actualizarCalificacion(nuevaCalificacion);
                  trailer->setPromedio(nuevaCalificacion); 
                  cout << "Se ha actualizado la calificación" << endl;
                  yaCalificado = true;
                  return true;
              }
          }
          if (!yaCalificado) {
              float nuevaCalificacion = c->getCalificacion();
              trailer->setPromedio(nuevaCalificacion); 
              calificadas.push_back(c);
              cout << "Se ha calificado exitosamente" << endl;
              return true;
          }
      }
    }
    return false;
  } catch (const exception &e) {
    cerr << "Error al calificar: " << e.what() << endl;
    return false;
  } catch (...) {
    cerr << "Ocurrió un error desconocido al calificar" << endl;
    return false;
  }
}

void Usuario::mostrarCalificadas(){
  if (calificadas.empty()) {
    cout << "No hay contenido calificado" << endl;
  } else {
      string linea1 = "                      \\  /         \n";
      string linea2 = "                       \\/          \n";
      string linea3 = " .========================================.\n";
      string linea4 = " | .------------------------------------. |\n" ;
      string linea5=  " | |                                    | |\n";
      string linea6=  " | |         MIS CALIFICACIONES         | |\n";
      string linea7=  " | |                                    | |\n";
      string linea8=  "";
      string linea9 = " | |                                    | |   __\n";
      string linea10 = " | '------------------------------------'o|  |o.| \n";
      string linea11 = " |========================================|  |::| \n";
      string linea12 = " |########################################|  |::|\n";
      string linea13 = " '========================================'  '--'\n";
      try {
        for (auto calificada:calificadas) {
            if (calificada == nullptr) {
              throw runtime_error("Se ha encontrado un contenido calificado no válido");
            }
            string title = calificada->getTitulo();
            float calif = calificada->getCalificacion();
            string starsBlack = "";
            string starsBlank = "";
            for (int i = 0; i < int(calif); ++i) {
                starsBlack = starsBlack + "★";
            }
            for (int i = 0; i < 5 - int(calif); ++i) {
              starsBlank = starsBlank + "☆";
            }
            string espacios = " ";
            string calificado = " | |  " + title + " : ";
            for (int i = 0; i < 33 - calificado.size(); ++i) {
                espacios =  espacios + " ";
            }
            linea8 = linea8 + calificado + starsBlack + starsBlank + espacios + " | |\n";
        }
          string screenCalificaciones = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
          linea10 + linea11 + linea12 + linea13;
          cout << screenCalificaciones << endl;
      }
      catch (const exception &e) {
        cerr << "Error mostrando contenido calificado: " << e.what() << endl;
      } catch (...) {
        cerr
            << "Ha ocurrido un error desconocido al mostrar el contenido calificado"
            << endl;
      }
 }
}

Usuario::Status Usuario::getStatus() { return status; }

void Usuario::setPlan(Plan pl) {
  plan = pl;
  if (pl == NA) {
    status = SINSUSCRIPCION;
  } else {
    status = SUSCRITO;
  }
}

Usuario::Plan Usuario::getPlan() { return plan; }

string Usuario::getNombre() { return nombre; }

string Usuario::getContrasena() { return contrasena; }

Usuario ::~Usuario() {}