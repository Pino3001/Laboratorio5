#include "Consulta.h"
#include "Actividad.h"
#include "Medico.h"
#include "Socio.h"
#include "ProblemaDeSalud.h"
#include "Diagnostico.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "DTDiagnostico.h"
#include "DTConsulta.h"
#include <list>
#include <string>
#include "definiciones.h"
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
Consulta ::Consulta(Consulta &consulta, Actividad &actividad) : Actividad(actividad)
{
    this->fechaConsulta = consulta.getFechaConsulta();
    this->horaConsulta = consulta.getHoraConsulta();
}

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
list<Diagnostico *> *Consulta ::getDiagnosticoConsulta()const
{
    return this->diagnosticosConsulta;
}

list<DTDiagnostico> Consulta ::getDatosDiagnosticoConsulta()const
{
    list<DTDiagnostico> ldtd;
    for (Diagnostico *d : *this->diagnosticosConsulta)
    {
        DTDiagnostico dtd = d->getDatosDiagnostico();
        ldtd.push_back(dtd);
    }
    return ldtd;
}

Diagnostico * Consulta ::crearDiagnostico(string descripcion, list<ProblemaDeSalud *> *lPds)
{

    Diagnostico *d = new Diagnostico(descripcion, lPds);
    this->diagnosticosConsulta->push_back(d);
    return d;
}


Consulta::~Consulta() {}
