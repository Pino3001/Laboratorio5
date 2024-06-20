#include "Comun.h"
#include "Diagnostico.h"
#include "ProblemaDeSalud.h"
#include "Consulta.h"
#include "Socio.h"
#include "Medico.h"
#include "Diagnostico.h"
#include "DTConsulta.h"
#include "DTReserva.h"
#include "DTFecha.h"
#include "DTHora.h"

Comun::Comun(const DTFecha fechaReserva, EstadoConsulta estConsulta, string idConsulta, const DTFecha fecha, const DTHora hora, Socio *socio, Medico *medico, string nombreMedico, string ciMedico, string nombreSocio, string ciSocio) : Consulta(idConsulta, fecha, hora, socio, medico, nombreMedico, ciMedico, nombreSocio, ciSocio)
{
    this->fechaReserva = fecha;
    this->estadoConsulta = estConsulta;
}
/* Comun::Comun() : Consulta(){
    DTFecha f();
    this->fechaReserva = f;
    this->estadoConsulta = Reservada;
} */


// Setters
void Comun::setFechaReserva(const DTFecha fechaReserva){this->fechaReserva = fechaReserva;}
void Comun::setEstadoConsulta(EstadoConsulta estadoConsulta){this->estadoConsulta = estadoConsulta;}

// Getters
DTFecha Comun::getFechaReserva() const {return this->fechaReserva;}
EstadoConsulta Comun::getEstadoConsulta(){return this->estadoConsulta;}

// Métodos adicionales
DTConsulta Comun::getDatosConsulta()
{
    // Implementación del método
    // Retornar un objeto DTConsulta con los datos correspondientes
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

//de Herencia
string Comun ::getNombreSocio()
{

}
string Comun ::getCiSocio()
{

}
string Comun ::getNombreMedico()
{
}
string Comun ::CiMedico()
{
}




// Destructor
Comun::~Comun()
{
    // Limpieza si es necesario
}