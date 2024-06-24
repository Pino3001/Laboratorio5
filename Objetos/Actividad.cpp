#include "Actividad.h"
#include "Socio.h"
#include "Medico.h"
#include "Usuario.h"
#include "DTFecha.h"

// Constructores
Actividad ::Actividad(Socio *socio, Medico *medico)
{
    this->socioConsulta = socio;
    this->medicoRealiza = medico;

}

Actividad ::Actividad(const Actividad &actividad)
{
    this->socioConsulta = actividad.getSocioConsulta();
    this->medicoRealiza = actividad.getMedicoRealiza();
}

// Setters
void Actividad ::setSocioConsulta(Socio *socio)
{
    this->socioConsulta = socio;
}
void Actividad ::setMedicoRealiza(Medico *medico)
{
    this->medicoRealiza = medico;
}

// Getters
Socio *Actividad ::getSocioConsulta()const
{
    return this->socioConsulta;
}
Medico *Actividad ::getMedicoRealiza()const
{
    return this->medicoRealiza;
}

string Actividad:: getNombreSocioActividad()const{
    return this->getSocioConsulta()->getUsuarioVinculado()->getNombre();
}
string Actividad:: getNombreMedicoActividad()const{
    return this->getMedicoRealiza()->getUsuarioVinculado()->getNombre();
}

//Operador de comparacion para ordenamiento.
bool Actividad::operator<(const Actividad &act) const
{
   if (this->getNombreMedicoActividad() != act.getNombreMedicoActividad())
    {
       return this->getNombreMedicoActividad() < act.getNombreMedicoActividad();
   }
   return getFechaConsulta() < act.getFechaConsulta();
}
//Destructor
Actividad::~Actividad() {}








