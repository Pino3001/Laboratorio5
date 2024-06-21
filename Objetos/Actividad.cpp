#include "Actividad.h"
#include "Socio.h"
#include "Medico.h"
#include "Usuario.h"
#include "Historial.h"

// Constructores
Actividad ::Actividad(Socio *socio, Medico *medico)
{
    this->socioConsulta = socio;
    this->medicoRealiza = medico;
    this->historialAsoc = nullptr;
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
void Actividad ::setHistorialAsoc(Historial *historial)
{
    this->historialAsoc = historial;
}

// Getters
Socio *Actividad ::getSocioConsulta()
{
    return this->socioConsulta;
}
Medico *Actividad ::getMedicoRealiza()
{
    return this->medicoRealiza;
}

string Actividad ::cedulaSocio()
{
    return this->socioConsulta->verCi();
}
string Actividad ::cedulaMedico()
{
    return this->medicoRealiza->verCi();
}
string Actividad ::nombreSocio()
{
    return this->socioConsulta->verNombre();
}
string Actividad ::nombreMedico()
{
    return this->medicoRealiza->verNombre();
}
// Para implementar
Actividad::~Actividad() {}