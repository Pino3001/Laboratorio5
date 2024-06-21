#include "Consulta.h"
#include "Actividad.h"
#include "Medico.h"
#include "Socio.h"
#include "ProblemaDeSalud.h"
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
Consulta ::Consulta( const DTFecha fechaConsulta, const DTHora horaConsulta, Socio *socio, Medico *medico) : Actividad(socio, medico)
{
    this->idConsulta = idConsulta;
    this->fechaConsulta = fechaConsulta;
    this->horaConsulta = horaConsulta;
}
Consulta ::Consulta(Consulta &consulta, Actividad &actividad) : Actividad(actividad)
{
    this->fechaConsulta = consulta.getFechaConsulta();
    this->horaConsulta = consulta.getHoraConsulta();
}

void Consulta ::setFechaConsulta(const DTFecha fecha) { this->fechaConsulta = fecha; }
void Consulta ::setHoraConsulta(const DTHora hora) { this->horaConsulta = hora; }

DTFecha Consulta ::getFechaConsulta()const { return this->fechaConsulta; }
DTHora Consulta ::getHoraConsulta() const { return this->horaConsulta; }

DTConsulta Consulta ::getDatosConsulta(){}
Diagnostico *Consulta ::crearDiagnostico(string descripcion, ProblemaDeSalud pds){}
void Consulta ::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, list<string> listaMedicamentos){}
void Consulta ::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha){}
void Consulta ::agregarDiagnosticoConsulta(Diagnostico diagnostico){}

Consulta::~Consulta(){}