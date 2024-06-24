#include <iostream>
#include "Serie.h"

using namespace std;


Serie :: Serie (string tit, int fe, int temp, string Id, float prom) : Contenido(tit, fe, Id, prom),temporadas(temp) {}

string Serie::getTitulo(){
  return titulo;
}

int Serie::getFecha(){
  return fecha;
}

float Serie:: getPromedio (){
  return promedio;
}

string Serie::getId(){
  return id;
}

void Serie::setPromedio(float cal){
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

int Serie::getTemporadas(){
  return temporadas;
}

Serie::~Serie() {
}
