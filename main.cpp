#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;
#include "Usuario.h"
#include "Plataforma.h"
#include "CatalogoSeries.h"
#include "CatalogoPeliculas.h"
#include "CatalogoTrailers.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Trailer.h"
#include "Calificada.h"


int main() {
  Plataforma plataforma("Netflix");
  CatalogoPeliculas& catalogoPel = CatalogoPeliculas::getInstancia();
  catalogoPel.leerCatalogo("catalogoPeliculas.txt");
  CatalogoSeries& catalogoSer = CatalogoSeries::getInstancia();
  catalogoSer.leerCatalogo("catalogoSeries.txt");
  CatalogoTrailers& catalogoTrai = CatalogoTrailers::getInstancia();
  catalogoTrai.leerCatalogo("catalogoTrailers.txt");
  bool salir=false;
  int opcion;
  int opcionDos;
  int opcionTres;
  string user;
  string cont;
  bool inicioSesion;
  bool cerrarSesion = false;
  string linea1 = "                      \\  /         \n";
  string linea2 = "                       \\/          \n";
  string linea3 = " .========================================.\n";
  string linea4 = " | .------------------------------------. |\n" ;
  string linea5=  " | |                                    | |\n";
  string linea6=  " | |                                    | |\n";
  string linea7=  " | |                                    | |\n";
  string linea8 = " | |               ███    ██            | |\n";
  string linea9 = " | |               ████   ██            | |\n";
  string linea10 = " | |               ██ ██  ██            | |\n";
  string linea11 = " | |               ██  ██ ██            | |\n";
  string linea12 = " | |               ██   ████            | |\n";
  string linea13 = " | |                NETFLIX             | |\n";
  string linea14 = " | |                                    | |\n";
  string linea15 = " | |                                    | |\n";
  string linea16 = " | |                                    | |   __\n";
  string linea17 = " | '------------------------------------'o|  |o.| \n";
  string linea18 = " |========================================|  |::| \n";
  string linea19 = " |########################################|  |::|\n";
  string linea20 = " '========================================'  '--'\n";

  string screenOn = linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
  linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;

  cout << screenOn << endl;

  do {
      string linea7 = " | |              MENU INICIO           | |\n";
      string linea8 = " | |                                    | |\n";
      string linea9 = " | |          [1] Nuevo usuario         | |\n";
      string linea10 = " | |          [2] Inciar sesión         | |\n";
      string linea11 = " | |          [3] Renovar plan          | |\n";
      string linea12 = " | |          [4] Salir                 | |\n";
      string linea13 = " | |                                    | |\n";
      string screenMenu1 =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
  linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
      cout << screenMenu1 << endl;
      cin >> opcion;
      if (cin.fail()) {
          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cout << "Opción no válida. Por favor, ingrese un número.\n";
          continue; 
      }
      switch (opcion) {
          case 1: {
              string linea7 = " | |             CREAR CUENTA           | |\n";
              string linea8 = " | |                                    | |\n";
              string linea9 = " | |   .-----------------------------.  | |\n";
              string linea10 = " | |  | usario                       |  | |\n";
              string linea11 = " | |  .------------------------------.  | |\n";
              string linea12 = " | |  | contraseña                   |  | |\n";
              string linea13 = " | |  .------------------------------.  | |\n";
              string linea14 = " | |  | Tradicional [1] | Premium [2]|  | |\n";
              string linea15 = " | |  .------------------------------.  | |\n";
              string screenCrearCuenta =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
  linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
              cout << screenCrearCuenta << endl;
              cout << "Ingresa tu nombre de usuario: ";
              cin >> user;
              bool disponible = plataforma.validarNoRepetido(user);
              if (disponible == false) {
                cout << "Ya existe otro usuario con ese nombre" << endl;
                break;
              }
              cout << "Ingresa tu contraseña: ";
              cin >> cont;
              cout << "Selecciona un plan: ";
              int selectplan;
              cin >> selectplan;
              if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Opción no válida.\n";
                    continue; 
                }
              if (selectplan == 1){
                  plataforma + new Usuario(user,cont,Usuario::SUSCRITO,Usuario::TRADICIONAL);
              } 
              else {
                  if (selectplan==2){
                    plataforma + new Usuario(user,cont,Usuario::SUSCRITO,Usuario::PREMIUM);
                  }
                  else {
                      cout << "Opción no válida" << endl;
                  }
              }
              break;
          }
          case 4: {
              salir = true;
              string linea7 = " | |                                    | |\n";
              string linea8 = " | |                                    | |\n";
              string linea9 = " | |          Cierre de Netflix         | |\n";
              string linea10 = " | |               exitoso              | |\n";
              string linea11 = " | |                                    | |\n";
              string linea12 = " | |                                    | |\n";
              string screenCierre =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
  linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
              cout << screenCierre << endl;
              break;
          }
          case 3: {
            string linea7 = " | |             RENOVAR PLAN           | |\n";
            string linea8 = " | |                                    | |\n";
            string linea9 = " | |   .-----------------------------.  | |\n";
            string linea10 = " | |  | usario                       |  | |\n";
            string linea11 = " | |  .------------------------------.  | |\n";
            string linea12 = " | |  | contraseña                   |  | |\n";
            string linea13 = " | |  .------------------------------.  | |\n";
            string linea14 = " | |  | Tradicional [1] | Premium [2]|  | |\n";
            string linea15 = " | |  .------------------------------.  | |\n";
            string screenSesionPlan =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
            linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
            cout << screenSesionPlan << endl;
            cout << "Ingresa tu nombre de usuario: ";
            cin >> user;
            cout << "Ingresa tu contraseña: ";
            cin >> cont;
            Usuario* existe = plataforma.findUser(user);
            if (existe == nullptr) {
                cout << "Usuario no encontrado" << endl;
            }
            else {
                if (existe->getContrasena() == cont) {
                    cout << "Seleccione un plan: " << endl;
                    int cambio;
                    cin >> cambio;
                    if (cin.fail()) {
                          cin.clear(); 
                          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                          cout << "Opción no válida. \n";
                          continue; 
                      }
                    if (cambio == 1) {
                        existe->setPlan(Usuario::TRADICIONAL);
                    }
                    if (cambio == 2) {
                        existe->setPlan(Usuario::PREMIUM);
                    }
                    else {
                        cout << "Opción no válida" << endl;
                    }
                } else {
                    cout << "Contraseña incorrecta" << endl;
                }
            }
            break;
        }
          case 2: {
              string linea7 = " | |             BIENVENIDO             | |\n";
              string linea8 = " | |                                    | |\n";
              string linea9 = " | |         .---------------.          | |\n";
              string linea10 = " | |         | usario        |          | |\n";
              string linea11 = " | |         .---------------.          | |\n";
              string linea12 = " | |         | contraseña    |          | |\n";
              string linea13 = " | |         .---------------.          | |\n";
              string screenSesion =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
              linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
              cout << screenSesion << endl;
              cout << "Usuario: ";
              cin >> user;
              cout << "Contraseña: ";
              cin >> cont;
              inicioSesion = plataforma.iniciarSesion(user,cont);
              Usuario* fan = plataforma.findUser(user); //usuario*
              if (inicioSesion) {
                cerrarSesion = false;
                do {
                    string linea6 = " | |               NETFLIX              | |\n";
                    string linea7 = " | |                                    | |\n";
                    string linea8 = " | |  [1] Ver Catálogo Películas        | |\n";
                    string linea9 = " | |  [2] Ver Catálogo Series           | |\n";
                    string linea10 = " | |  [3] Ver Catálogo Tráilers         | |\n";
                    string linea11 = " | |  [4] Calificar Contenido           | |\n";
                    string linea12 = " | |  [5] Historial Calificaciones      | |\n";
                    string linea13 = " | |  [6] Consultar Plan Suscripción    | |\n";
                    string linea14 = " | |  [7] Cambiar Plan Suscripción      | |\n";
                    string linea15 = " | |  [8] Cerrar Sesión                 | |\n";
                    string screenPlataforma =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
                    linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
                    cout << screenPlataforma << endl;
                    cout << "Selecciona una opcion: ";
                    cin >> opcionDos;
                    if (cin.fail()) {
                          cin.clear(); 
                          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                          cout << "Opción no válida. Por favor, ingrese un número.\n";
                          continue; 
                      }
                    switch(opcionDos) {
                        case 1:
                            catalogoPel.mostrarTodos();
                            break;
                        case 2: 
                            catalogoSer.mostrarTodos();
                            break;
                        case 3:
                            catalogoTrai.mostrarTodos();
                            break;
                        case 4: {
                            string linea6 = " | |        SISTEMA DE CALIFICACIONES   | |\n";    
                            string linea7 = " | |                                    | |\n";
                            string linea8 = " | |     Título                         | |\n";
                            string linea9 = " | |    .-----------------------.       | |\n";
                            string linea10 = " | |    |                       |       | |\n";
                            string linea11 = " | |    .-----------------------.       | |\n";
                            string linea12 = " | |     Calificación                   | |\n";
                            string linea13 = " | |    .-----------------------.       | |\n";
                            string linea14 = " | |    | ☆ ☆ ☆ ☆ ☆             |       | |\n";
                            string linea15 = " | |    .-----------------------.       | |\n";
                            string screenCalifar =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
                            linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
                            cout << screenCalifar << endl;
                            string titulo;
                            cout << "Ingrese el titulo del contenido a calificar: ";
                            cin.ignore();
                            getline(cin, titulo); 
                            float calif;
                            cout << "Ingrese la calificación: ";
                            cin >> calif;
                            if (cin.fail()) {
                                  cin.clear(); 
                                  cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                                  cout << "Opción no válida.\n";
                                  continue; 
                              }
                            if (calif>5 || calif<0){
                              cout << "Calificación no válida" << endl;
                            }
                            else {
                                Calificada* nuevaCalificacion = new Calificada(titulo, calif);
                                bool se_pudo = fan->calificar(nuevaCalificacion);
                                if (se_pudo == true){
                                  cout << "" << endl;
                                } else {
                                    cout << "Contenido no encontrado" << endl;
                                }
                            }
                            break;
                        }
                        case 5: 
                            fan->mostrarCalificadas();
                            break;
                        case 6:{
                            string status, plan, espacios; 
                            if (fan->getStatus() == 1){
                                 status = "SUSCRITO";
                            }else{
                                 status = "SINSUSCRIPCION";
                            }
                            if (fan->getPlan() == 1){
                                 plan = "TRADICIONAL";
                                 espacios = "                   ";
                            }else{
                                if (fan->getPlan() == 2){
                                  plan = "PREMIUM";
                                  espacios = "                       ";
                                }else{
                                    plan = "NA";
                                }
                            }
                            string linea6 = " | |           PLAN SUSCRIPCIÓN         | |\n";    
                            string linea7 = " | |                                    | |\n";
                            string linea8 = " | |     Status                         | |\n";
                            string linea9 = " | |    .-----------------------.       | |\n";
                            string linea10 = " | |      " + status + "                      | |\n";
                            string linea11 = " | |    .-----------------------.       | |\n";
                            string linea12 = " | |     Plan                           | |\n";
                            string linea13 = " | |    .-----------------------.       | |\n";
                            string linea14 = " | |      " + plan + espacios + "| |\n";
                            string linea15 = " | |    .-----------------------.       | |\n";
                            string screenPlan =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
                            linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
                            cout << screenPlan << endl;
                            break;
                        }
                        case 7:{
                            string linea6 = " | |                                    | |\n";    
                            string linea7 = " | |        CAMBIO SUSCRIPCIONES        | |\n";
                            string linea8 = " | |                                    | |\n";
                            string linea9 = " | |    [1] Suscribirse a Premium       | |\n";
                            string linea10 = " | |    [2] Suscribirse a Tradicional   | |\n";
                            string linea11 = " | |    [3] Cancelar Suscripción        | |\n";
                            string linea12 = " | |                                    | |\n";
                            string linea13 = " | |                                    | |\n";
                            string linea14 = " | |                                    | |\n";
                            string linea15 = " | |                                    | |\n";
                            string screenCambioSub =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
                            linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
                            cout << screenCambioSub << endl;
                            cout << "Selecciona una opcion: ";
                            cin >> opcionTres;
                            if (cin.fail()) {
                                  cin.clear(); 
                                  cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                                  cout << "Opción no válida. Por favor, ingrese un número.\n";
                                  continue; 
                              }
                            switch (opcionTres){
                                case 1: 
                                    fan->setPlan(Usuario::PREMIUM);
                                    cout << fan->getPlan() << endl; 
                                    break;
                                case 2:
                                    fan->setPlan(Usuario::TRADICIONAL);
                                    break;
                                case 3:{
                                    fan->setPlan(Usuario::NA);
                                    string linea6 = " | |                                    | |\n";
                                    string linea7 = " | |                                    | |\n";
                                    string linea8 = " | |                                    | |\n";
                                    string linea9 = " | |       Suscripción cancelada :(     | |\n";
                                    string linea10 = " | |        Cerrando sesión ...         | |\n";
                                    string linea11 = " | |                                    | |\n";
                                    string linea12 = " | |                                    | |\n";
                                    string linea13 = " | |                                    | |\n";
                                    string linea14 = " | |                                    | |\n";
                                    string linea15 = " | |                                    | |\n";
                                    string screenSubCancel =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
                                    linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
                                    cout << screenSubCancel << endl;
                                    inicioSesion = false;
                                    cerrarSesion = true;
                                    break;
                                 }
                                default:
                                    cout << "Opción no válida" << endl;
                                    break;
                            }
                            break;
                        }
                        case 8:{
                            string linea6 = " | |                                    | |\n";
                            string linea7 = " | |                                    | |\n";
                            string linea8 = " | |                                    | |\n";
                            string linea9 = " | |          Cierre de sesión          | |\n";
                            string linea10 = " | |               exitoso              | |\n";
                            string linea11 = " | |                                    | |\n";
                            string linea12 = " | |                                    | |\n";
                            string linea13 = " | |                                    | |\n";
                            string linea14 = " | |                                    | |\n";
                            string linea15 = " | |                                    | |\n";
                            string screenCierreSesion =  linea1 + linea2 + linea3 + linea4 + linea5 + linea6 + linea7 + linea8 + linea9 +
                            linea10 + linea11 + linea12 + linea13 + linea14 + linea15 + linea16 + linea17 + linea18 + linea19 + linea20;
                            cout << screenCierreSesion << endl;
                            inicioSesion = false;
                            cerrarSesion = true;
                            break;
                        }
                        default:
                            cout << "Opción inválida" << endl;
                            break;
                    }
                } while (cerrarSesion==false);
              }
              break;
          }
          default:   
              cout << "Opción no válida" << endl;
             break;
      }
  } while (salir==false);
  return 0;
}
