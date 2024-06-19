#include "Quirurgico.h"
#include "Tratamiento.h"
#include "Medico.h"
#include <string>
using namespace std;

// Constructor por defecto
Quirurgico::Quirurgico(string descripcion, DTFecha fechaCirugia) : Tratamiento(descripcion){
    this->fechaCirugia = fechaCirugia;
}
Quirurgico ::Quirurgico(string descripcion, DTFecha fechaCirugia, Medico *cirujano) : Tratamiento(descripcion){
    this->fechaCirugia = fechaCirugia;
    this->cirujanoOperacion = cirujano;
}


// Getter
DTFecha Quirurgico::getFechaCirugia(){
    return this->fechaCirugia;
}
Medico *Quirurgico::getCirujanoOperacion(){
    return this->cirujanoOperacion;
}

// Setter
void Quirurgico::setFechaCirugia(DTFecha fechaCirugia){
    this->fechaCirugia = fechaCirugia;
}
void Quirurgico::setCirujanoOperacion(Medico *cirujano){
    this->cirujanoOperacion = cirujano;
}

// Destructor
Quirurgico::~Quirurgico(){}