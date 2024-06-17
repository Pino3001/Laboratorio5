#include "ProblemaDeSalud.h"
#include "Diagnostico.h"
#include <string>

using namespace std;
//Constructores

ProblemaDeSalud::ProblemaDeSalud() {
    this->codigo = "";
    this->etiqueta = "";
}


ProblemaDeSalud::ProblemaDeSalud(string codigo, string etiqueta) {
    this->codigo = codigo;
    this->etiqueta = etiqueta;
}

//Getters y Setters
string ProblemaDeSalud::getCodigo() {
    return this->codigo;
}


string ProblemaDeSalud::getEtiqueta() {
    return this->etiqueta;
}


void ProblemaDeSalud::setCodigo(string codigo) {
    this->codigo = codigo;
}

void ProblemaDeSalud::setEtiqueta(string etiqueta) {
    this->etiqueta = etiqueta;
}


ProblemaDeSalud::~ProblemaDeSalud() {}
