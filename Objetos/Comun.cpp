#include "Comun.h"
#include "Diagnostico.h"
#include "ProblemaDeSalud.h"
#include "Consulta.h"
#include "Socio.h"
#include "Medico.h"
#include "DTConsulta.h"
#include "DTReserva.h"
#include "DTFecha.h"
#include "DTHora.h"
#include "definiciones.h"
#include <string>

Comun::Comun(const DTFecha fechaReserva, EstadoConsulta estConsulta, const DTFecha fecha, const DTHora hora, Socio *socio, Medico *medico) : Consulta(fecha, hora, socio, medico)
{
    this->fechaReserva = fecha;
    this->estadoConsulta = estConsulta;
}
Comun::Comun(Comun &comun, Consulta &consulta, Actividad &actividad) : Consulta(consulta, actividad)
{
    this->fechaReserva = comun.getFechaReserva();
    this->estadoConsulta = comun.getEstadoConsulta();
}

// Setters
void Comun::setFechaReserva(const DTFecha fechaReserva)
{
    this->fechaReserva = fechaReserva;
}
void Comun::setEstadoConsulta(EstadoConsulta estadoConsulta)
{
    this->estadoConsulta = estadoConsulta;
}

// Getters
DTFecha Comun::getFechaReserva() const
{
    return this->fechaReserva;
}
EstadoConsulta Comun::getEstadoConsulta()
{
    return this->estadoConsulta;
}
DTConsulta Comun::getDatosConsulta()
{
    DTConsulta dtc(this->nombreSocio(), this->cedulaSocio(), this->nombreMedico(), this->getFechaConsulta(), this->getHoraConsulta(), TipoConsulta::Tipo_Comun);
    return dtc;
}

string Comun::obtenerCiSocio()
{
    return this->cedulaSocio();
}
string Comun::obtenerCiMedico()
{
    return this->cedulaMedico();
}
TipoConsulta Comun::obtenerTipoConsulta()
{
    return TipoConsulta::Tipo_Comun;
}

Diagnostico Comun::crearDiagnostico(std::string descripcion, ProblemaDeSalud *pds)
{
    // Implementación del método
    // Crear y retornar un objeto Diagnostico
}

void Comun::agregarTratamientoFarmaco(Diagnostico *diagnostico, std::string descripcion, std::list<std::string> *listMedicamentos)
{
    // Implementación del método
    // Agregar tratamiento farmacológico al diagnóstico
}

void Comun::agregarTratamientoQuirurgico(Diagnostico *diagnostico, std::string descripcion, const DTFecha fecha)
{
    // Implementación del método
    // Agregar tratamiento quirúrgico al diagnóstico
}

void Comun::agregarDiagnosticoAConsulta(Diagnostico *diagnostico)
{
    // Implementación del método
    // Agregar diagnóstico a la consulta
}

set<DTReserva> *Comun::getDatosReservas()
{
    // Implementación del método
    // Retornar un conjunto de DTReserva
}

Historial *Comun ::getHistorialAsoc() {}

// Destructor
Comun::~Comun()
{
    // Limpieza si es necesario
}