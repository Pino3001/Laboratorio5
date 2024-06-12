#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include "Usuario.h"
#include "Socio.h"
#include "Medico.h"

#include "string.h"
using namespace std;

class Actividad
{
private:
    Socio *socioTiene;
    Medico *medicoRealiza;

public:
    Actividad(Socio *socio, Medico *medico);
    Actividad(Actividad &actividad);

    void setSocioTiene(Socio *socio);
    void setMedicoRealiza(Medico *medico);

    Socio* getSocioTiene();
    Medico* getMedicoRealiza();

    ~Actividad();
};
#endif





