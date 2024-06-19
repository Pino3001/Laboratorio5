#include "DTDiagnostico.h"

DTDiagnostico::DTDiagnostico()
    : descripcion(""), pDeSalud(), tratamientos() {}

// Constructor con todos los parámetros
DTDiagnostico::DTDiagnostico(string descripcion, list<DTProblemaDeSalud> *pDeSalud, list<DTTratamiento> *tratamientos)
    : descripcion(descripcion), pDeSalud(pDeSalud), tratamientos(tratamientos) {}

// Getters
string DTDiagnostico::getDescripcion()
{
    return descripcion;
}

list<DTProblemaDeSalud> *DTDiagnostico::getPDeSalud()
{
    return pDeSalud;
}

std::list<DTTratamiento> *DTDiagnostico::getTratamientos()
{
    return tratamientos;
}