#include "ProblemaDeSalud.h"
#include "DTProblemaDeSalud.h"
#include <string>

using namespace std;
// Constructores

ProblemaDeSalud::ProblemaDeSalud()
{
    this->codigo = "";
    this->etiqueta = "";
}

ProblemaDeSalud::ProblemaDeSalud(string codigo, string etiqueta)
{
    this->codigo = codigo;
    this->etiqueta = etiqueta;
}

// Setters
void ProblemaDeSalud::setCodigo(string codigo)
{
    this->codigo = codigo;
}

void ProblemaDeSalud::setEtiqueta(string etiqueta)
{
    this->etiqueta = etiqueta;
}
// Getters
string ProblemaDeSalud::getCodigo()
{
    return this->codigo;
}
string ProblemaDeSalud::getEtiqueta()
{
    return this->etiqueta;
}
DTProblemaDeSalud ProblemaDeSalud::getDatoProblema()
{
    DTProblemaDeSalud dtp(this->codigo, this->etiqueta);
    return dtp;
}

ProblemaDeSalud::~ProblemaDeSalud() {}
