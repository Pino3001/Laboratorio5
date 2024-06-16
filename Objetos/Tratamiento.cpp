#include "Tratamiento.h"
#include "string.h"
using namespace std;

// Constructor por defecto
Tratamiento::Tratamiento(){
    this->descripcion = " ";
}

// Constructor con parametros
Tratamiento::Tratamiento(string descripcion){
    this->descripcion = descripcion;
}

// Getter
string Tratamiento::getDescripcionTratamiento(){
    return this->descripcion;
}

// Setter
void Tratamiento::setDescripcionTratamiento(string descripcion){
    this->descripcion = descripcion;
}
