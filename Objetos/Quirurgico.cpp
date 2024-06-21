#include "Quirurgico.h"
#include "Tratamiento.h"
#include "Medico.h"
#include <string>
using namespace std;

// Constructor por defecto
Quirurgico::Quirurgico(string descripcion, const DTFecha fechaCirugia) : Tratamiento(descripcion){
    this->fechaCirugia = fechaCirugia;
}
Quirurgico ::Quirurgico(string descripcion, const DTFecha fechaCirugia, Medico *cirujano) : Tratamiento(descripcion), fechaCirugia(fechaCirugia), cirujanoOperacion(cirujano) {}


// Getter
DTFecha Quirurgico::getFechaCirugia()const{
    return this->fechaCirugia;
}
Medico *Quirurgico::getCirujanoOperacion(){
    return this->cirujanoOperacion;
}

// Setter
void Quirurgico::setFechaCirugia(const DTFecha fechaCirugia){
    this->fechaCirugia = fechaCirugia;
}
void Quirurgico::setCirujanoOperacion(Medico *cirujano){
    this->cirujanoOperacion = cirujano;
}

// Destructor
Quirurgico::~Quirurgico(){}