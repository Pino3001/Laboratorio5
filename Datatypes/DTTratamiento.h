#ifndef DTTRATAMIENTO_H
#define DTTRATAMIENTO_H
#include "DTFecha.h"
#include "definiciones.h"
#include <string>
#include <list>
#include "DTDatosUsuario.h"
using namespace std;

class DTTratamiento
{
private:
    string descripcion;
    TipoTratamiento tipo;
    list<string> listMedicamentos;
    DTFecha fechaCirujia;
    DTDatosUsuario cirujano;

public:
    DTTratamiento();
    DTTratamiento(string descripcion, TipoTratamiento tipo, list<string> listaMedicamentos);
    DTTratamiento(string descripcion, TipoTratamiento tipo, const DTFecha fechaCirujia, DTDatosUsuario cirujano);

    string getDescripcion()const;
    TipoTratamiento getTipo()const;
    list<string> getListMedicamentos()const;
    DTFecha getFechaCirugia()const;
    DTDatosUsuario getCirujano()const;
};
#endif
