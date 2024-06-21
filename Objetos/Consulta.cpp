#include "Consulta.h"
#include "Actividad.h"
#include "Medico.h"
#include "Socio.h"
#include "ProblemaDeSalud.h"
#include "Diagnostico.h"
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <list>
#include <string>

using namespace std;

/* Consulta ::Consulta() : Actividad()
{
    this->idConsulta = "0";
    DTFecha fc = DTFecha();
    this->fechaConsulta = fc;
    DTHora hc = DTHora();
    this->horaConsulta = hc;
} */
Consulta ::Consulta(const DTFecha fechaConsulta, const DTHora horaConsulta, Socio *socio, Medico *medico) : Actividad(socio, medico)
{
    this->idConsulta = idConsulta;
    this->fechaConsulta = fechaConsulta;
    this->horaConsulta = horaConsulta;
    this->diagnosticosConsulta = new list<Diagnostico *>;
}
/* Consulta ::Consulta(Consulta &consulta, Actividad &actividad) : Actividad(actividad)
{
    this->fechaConsulta = consulta.getFechaConsulta();
    this->horaConsulta = consulta.getHoraConsulta();
} */

// Setters
void Consulta ::setFechaConsulta(const DTFecha fecha)
{
    this->fechaConsulta = fecha;
}
void Consulta ::setHoraConsulta(const DTHora hora)
{
    this->horaConsulta = hora;
}
void Consulta ::setDiagnosticosConsulta(list<Diagnostico *> *diagnosticosConsulta)
{
    this->diagnosticosConsulta = diagnosticosConsulta;
}

// Getters
DTFecha Consulta ::getFechaConsulta() const
{
    return this->fechaConsulta;
}
DTHora Consulta ::getHoraConsulta() const
{
    return this->horaConsulta;
}
list<Diagnostico *> *Consulta ::getDiagnosticoConsulta()
{
    return this->diagnosticosConsulta;
}


DTConsulta Consulta ::getDatosConsulta() {}

void Consulta ::crearDiagnostico(string descripcion, list<ProblemaDeSalud *> *lPds)
{
    Diagnostico *d = new Diagnostico(descripcion, lPds);
    this->diagnosticosConsulta->push_back(d);
}

void Consulta ::crearDiagnosticoTratFarmaco(string descripcion, list<ProblemaDeSalud *> *lPds, list<string> *medicamentos, string descrTrat)
{
    Diagnostico *d = new Diagnostico(descripcion, lPds);
    this->diagnosticosConsulta->push_back(d);
    d->agregarTratamientoFarmaco(medicamentos, descrTrat);
}

void Consulta ::crearDiagnosticoTratQuirurjico(string descripcion, list<ProblemaDeSalud *> *lPds, Medico *med, string descrTrat, const DTFecha fechaCiruj)
{
    Diagnostico *d = new Diagnostico(descripcion, lPds);
    this->diagnosticosConsulta->push_back(d);
    d->agregarTratamientoQuirurgico(descrTrat, fechaCiruj, med);
}



void Consulta ::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, list<string> listaMedicamentos) {}
void Consulta ::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha) {}
void Consulta ::agregarDiagnosticoConsulta(Diagnostico diagnostico) {}

Consulta::~Consulta() {}