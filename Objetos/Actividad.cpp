#include "Actividad.h"
#include "Socio.h"
#include "Medico.h"
#include "Usuario.h"
#include "Historial.h"
#include "DTFecha.h"

// Constructores
Actividad ::Actividad(Socio *socio, Medico *medico)
{
    this->socioConsulta = socio;
    this->medicoRealiza = medico;
    this->historialAsoc = nullptr;
}

Actividad ::Actividad(Actividad &actividad)
{
    this->socioConsulta = actividad.getSocioConsulta();
    this->medicoRealiza = actividad.getMedicoRealiza();
    this->historialAsoc = actividad.getHistorialAsoc();
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
Historial *Actividad::getHistorialAsoc()
{
    return this->historialAsoc;
}

void Actividad::addHistorialAsoc(Historial *h)
{
    this->historialAsoc = h;
    this->socioConsulta->addHistorialSocio(h);
}

string Actividad ::cedulaSocio() const
{
    return this->socioConsulta->verCi();
}
string Actividad ::cedulaMedico() const
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

bool Actividad::operator<(const Actividad &act) const
{
    if (cedulaMedico() != act.cedulaMedico())
    {
        return cedulaMedico() < act.cedulaMedico();
    }
    return getFechaConsulta() < act.getFechaConsulta();
}
// Para implementar
Actividad::~Actividad() {}