#include "Consulta.h"

#include "Actividad.h"

#include "Medico.h"
#include "Socio.h"
#include "definiciones.h"
#include "DTFecha.h"
#include "DTHora.h"
#include <list>
#include <string>

using namespace std;

Consulta ::Consulta() : Actividad()
{
    this->idConsulta = "0";
    DTFecha fc = DTFecha();
    this->fechaConsulta = fc;
    DTHora hc = DTHora();
    this->horaConsulta = hc;
}
Consulta ::Consulta(string idConsulta, DTFecha fecha, DTHora hora, Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio) : Actividad(socio, medico, nombreMedico, ciMedico, nombreSocio, ciSocio)
{
    // this->idConsulta =
    this->fechaConsulta = fecha;
    this->horaConsulta = hora;
}
Consulta ::Consulta(Consulta &consulta, Actividad &actividad) : Actividad(actividad)
{
    this->idConsulta = consulta.getIdConsulta();
    this->fechaConsulta = consulta.getFechaConsulta();
    this->horaConsulta = consulta.getHoraConsulta();
}

void Consulta ::setFechaConsulta(DTFecha fecha) { this->fechaConsulta = fecha; }
void Consulta ::setHoraConsulta(DTHora hora) { this->horaConsulta = hora; }

string Consulta ::getIdConsulta() { return this->idConsulta; }
DTFecha Consulta ::getFechaConsulta() { return this->fechaConsulta; }
DTHora Consulta ::getHoraConsulta() { return this->horaConsulta; }

DTConsulta getDatosConsulta();
Diagnostico *crearDiagnostico(string descripcion, ProblemaDeSalud pds);
void agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, list<string> listaMedicamentos);
void agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, DTFecha fecha);
void agregarDiagnosticoConsulta(Diagnostico diagnostico);

~Consulta();