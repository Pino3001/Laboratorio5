#include "DTProblemaDeSalud.h"

DTProblemaDeSalud::DTProblemaDeSalud() : codigo(""), etiqueta("") {}

DTProblemaDeSalud::DTProblemaDeSalud(string codigo, string etiqueta) : codigo(codigo), etiqueta(etiqueta) {}

string DTProblemaDeSalud::getCodigo()
{
    return this->codigo;
}
string DTProblemaDeSalud::getEtiqueta()
{
    return this->etiqueta;
}