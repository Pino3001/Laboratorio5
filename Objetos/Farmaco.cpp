#include "Farmaco.h"
#include "string.h"
using namespace std;

// Constructor por defecto
Farmaco::Farmaco(){
    this->nombreMedicamento = " ";
}
// Constructores con parametros
Farmaco::Farmaco(string nombreMedicamento){
    this->nombreMedicamento = nombreMedicamento;
}

Farmaco::Farmaco(string descripcion, string nombreMedicamento){
    this->setDescripcionTratamiento(descripcion) = descripcion;
    this->nombreMedicamento = nombreMedicamento;
}

//Getter
DTFecha Farmaco::getNombreMedicamento(){
    return this->nombreMedicamento;
}

// Setter
void Farmaco::setNombreMedicamento(string nombreMedicamento){
    this->nombreMedicamento = nombreMedicamento;
}

//Destructor
Farmaco::~Farmaco(){}