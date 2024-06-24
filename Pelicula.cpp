#include <iostream>
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula (string tit, int fe, string dir, string Id, float promedio): Contenido(tit, fe, Id, promedio), director(dir) {}

string Pelicula::getTitulo(){
  return titulo;
}

int Pelicula::getFecha(){
  return fecha;
}

void Pelicula::setPromedio(float cal){
  suma += cal;
  if (cal < 0) {
    cantidad -= 1;
  }
  else {
    cantidad +=1;
  }
  if (cantidad !=0) {
    promedio = suma/cantidad;
  }
  else {
    promedio=0;
  }
}

float Pelicula::getPromedio(){
  return promedio;
}

string Pelicula::getId(){
  return id;
}

string Pelicula::getDirector(){
  return director;
}

Pelicula::~Pelicula() {}
