#include "Emergencia.h"
#include "Diagnostico.h"
#include "DTConsulta.h"
#include <string>

// Constructor con parámetros
Emergencia::Emergencia(string motivo, const DTFecha fecha, const DTHora hora, Socio *socio, Medico *medico)
    : Consulta(fecha, hora, socio, medico)
{
    this->motivoConsulta = motivo;
}
Emergencia::Emergencia(Emergencia &emergencia, Consulta &consulta, Actividad &actividad) : Consulta(consulta, actividad){
    this->motivoConsulta = emergencia.getMotivoConsulta();
}

// Setter
void Emergencia::setMotivoConsulta(string motivo)
{
    this->motivoConsulta = motivo;
}

// Getter
string Emergencia::getMotivoConsulta()
{
    return this->motivoConsulta;
}
// Retorna un objeto DTConsulta con los datos correspondientes
DTConsulta Emergencia::getDatosConsulta()
{
    DTConsulta dtc(this->nombreSocio(), this->cedulaSocio(), this->nombreMedico(), this->getFechaConsulta(), this->getHoraConsulta(), TipoConsulta::Tipo_Emergencia);
    return dtc;
}

// Métodos adicionales
string Emergencia::obtenerCiSocio()
{
    return this->cedulaSocio();
}
string Emergencia::obtenerCiMedico()
{
    return this->cedulaMedico();
}
TipoConsulta Emergencia::obtenerTipoConsulta()
{
    return TipoConsulta::Tipo_Emergencia;
}

Diagnostico Emergencia::crearDiagnostico(string descripcion, ProblemaDeSalud pds)
{
    // Implementación del método
    // Crear y retornar un objeto Diagnostico
}
void Emergencia::agregarTratamientoFarmaco(Diagnostico diagnostico, string descripcion, set<string> *listMedicamentos)
{
    // Implementación del método
    // Agregar tratamiento farmacológico al diagnóstico
}
void Emergencia::agregarTratamientoQuirurgico(Diagnostico diagnostico, string descripcion, const DTFecha fecha)
{
    // Implementación del método
    // Agregar tratamiento quirúrgico al diagnóstico
}
void Emergencia::agregarDiagnosticoAConsulta(Diagnostico diagnostico)
{
    // Implementación del método
    // Agregar diagnóstico a la consulta
}

Historial *Emergencia ::getHistorialAsoc() {}

// Destructor
Emergencia::~Emergencia()
{
    // Liberar recursos si es necesario
}