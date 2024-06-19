#include "Farmaco.h"
#include "string.h"
using namespace std;

// Constructor por defecto
Farmaco::Farmaco(){
    this->nombreMedicamento = new list<string>;
}

Farmaco::Farmaco(string descripcion, list <string> *nombreMedicamento) : Tratamiento(descripcion){
    this->nombreMedicamento = nombreMedicamento;
}

//Getter
list<string>* Farmaco::getListaMedicamentos(){
    return this->nombreMedicamento;
}

// Setter
void Farmaco::setListaMedicamentos(list <string> *nombreMedicamento){
    this->nombreMedicamento = nombreMedicamento;
}

//Destructor
Farmaco::~Farmaco(){}