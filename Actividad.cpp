#include "Actividad.h"

#include "Usuario.h"
#include "Socio.h"
#include "Medico.h"

#include "string.h"
using namespace std;

// Constructores
Actividad :: Actividad(){
    this->socioTiene = NULL;
    this->medicoRealiza = NULL;
}
Actividad ::Actividad(Socio *socio, Medico *medico)
{
    this->socioTiene = socio;
    this->medicoRealiza = medico;
}

Actividad ::Actividad(Actividad &actividad)
{
    this->socioTiene = actividad.getSocioTiene();
    this->medicoRealiza = actividad.getMedicoRealiza();
}

// Setters
void Actividad ::setSocioTiene(Socio *socio)
{
    this->socioTiene = socio;
}
void Actividad ::setMedicoRealiza(Medico *medico)
{
    this->medicoRealiza = medico;
}

// Getters
Socio *Actividad ::getSocioTiene()
{
    return this->socioTiene;
}
Medico *Actividad ::getMedicoRealiza()
{
    return this->medicoRealiza;
}

//Para implementar
    /*~Actividad();*/