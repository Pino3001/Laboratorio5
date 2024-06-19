#ifndef DTTRATAMIENTO_H
#define DTTRATAMIENTO_H
#include "DTFecha.h"
#include "definiciones.h"
#include <string>
#include <list>
using namespace std;

class DTTratamiento
{
private:
    string descripcion;
    TipoTratamiento tipo;
    list<string> listMedicamentos;
    DTFecha fechaCirujia;
    string nombreCirujano;

public:
    DTTratamiento();
    DTTratamiento(string descripcion, TipoTratamiento tipo, list<string> listaMedicamentos);
    DTTratamiento(string descripcion, TipoTratamiento tipo, DTFecha fechaCirujia, string nombreCirujano);

    string getDescripcion();
    TipoTratamiento getTipo();
    list<string> getListMedicamentos();
    DTFecha& getFechaCirugia();
    string getNombreCirujano();
};
#endif