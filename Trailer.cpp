#include "Trailer.h"

using namespace std;

Trailer :: Trailer (string titulo, int fecha, float duracion, string id, float prom) : Contenido (titulo, fecha, id, prom), duracion(duracion){}

string Trailer:: getTitulo(){
  return titulo;
}

int Trailer :: getFecha (){
  return fecha;
}

void Trailer::setPromedio(float cal){
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

float Trailer :: getPromedio (){
  return promedio;
}

string Trailer::getId(){
  return id;
}

float Trailer::getDuracion(){
  return duracion;
}

Trailer::~Trailer() {
}