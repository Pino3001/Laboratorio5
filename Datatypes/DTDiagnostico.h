#ifndef DTDIAGNOSTICO_H
#define DTDIAGNOSTICO_H
#include "DTTratamiento.h"
#include "DTProblemaDeSalud.h"
#include <list>
#include <string>
using namespace std;

class DTDiagnostico
{
private:
    string descripcion;
    list<DTProblemaDeSalud> *pDeSalud;
    list<DTTratamiento> *tratamientos;

public:
    DTDiagnostico();
    DTDiagnostico(string descripcion, list<DTProblemaDeSalud> *problemas, list<DTTratamiento> *tratamientos);

    string getDescripcion();
    list<DTProblemaDeSalud> *getPDeSalud();
    list<DTTratamiento> *getTratamientos();

};
#endif
