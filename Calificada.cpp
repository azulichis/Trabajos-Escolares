#include <iostream>
#include "Calificada.h"

using namespace std;

Calificada::Calificada(string tit, float cal) : titulo(tit), calificacion(cal) {}

string Calificada::getTitulo(){
  return titulo;
}

float Calificada::getCalificacion(){
  return calificacion;
}

void Calificada::actualizarCalificacion(float cal){
  calificacion = cal;
}
