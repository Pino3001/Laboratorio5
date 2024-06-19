#include "Actividad.h"
#include "Socio.h"
#include "Medico.h"
#include "Usuario.h"
#include "Historial.h"

// Constructores
/* Actividad :: Actividad(){
    this->socioTiene = NULL;
    this->medicoRealiza = NULL;
} */
Actividad ::Actividad(Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio)
{
    this->socioTiene = socio;
    this->medicoRealiza = medico;
    this->nombreMedico = nombreMedico;
    this->ciMedico = ciMedico;
    this->nombreSocio = nombreSocio;
    this->ciSocio = ciSocio;
    this->historialAsoc = nullptr;
}

/* Actividad ::Actividad(Actividad &actividad)
{
    this->socioTiene = actividad.getSocioTiene();
    this->medicoRealiza = actividad.getMedicoRealiza();
} */

// Setters
void Actividad ::setSocioTiene(Socio *socio)
{
    this->socioTiene = socio;
}
void Actividad ::setMedicoRealiza(Medico *medico)
{
    this->medicoRealiza = medico;
}
void Actividad ::setHistorialAsoc(Historial *historial)
{
    this->historialAsoc = historial;
}
void Actividad ::setNombreSocio(string nombre)
{
    this->nombreSocio = nombre;
}
void Actividad ::setCiSocio(string ci)
{
    this->ciSocio = ci;
}
void Actividad ::setNombreMedico(string nombre)
{
    this->nombreMedico = nombre;
}
void Actividad ::setCiMedico(string ci)
{
    this->ciMedico = ci;
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
Historial *Actividad ::getHistorialAsoc()
{
    return this->historialAsoc;
}
string Actividad ::getNombreSocio()
{
    return this->nombreSocio;
}
string Actividad ::getCiSocio()
{
    return this->ciSocio;
}
string Actividad ::getNombreMedico()
{
    return this->nombreMedico;
}
string Actividad ::CiMedico()
{
    return this->ciMedico;
}

// Para implementar
Actividad::~Actividad(){}